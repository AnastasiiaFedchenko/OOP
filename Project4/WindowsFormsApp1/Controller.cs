using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static WindowsFormsApp1.Form1;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;
using static System.Windows.Forms.AxHost;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Drawing;

namespace WindowsFormsApp1
{
    public class Controller
    {
        enum ControllerState
        {
            FREE,
            BUSY,
            UPDATING_TARGET
        };
        public enum Direction 
        {
            UP = 1, 
            STAY = 0,
            DOWN = -1
        }
        ControllerState state;

        int cur_floor;
        int target_floor;
        Direction direction;

        List<bool> need_to_visit;
        public List<MyButton> floor_buttons;
        public List<MyButton> elevator_buttons;

        public event Cabin.CallCabinDelegate CallCabinEvent;
        public event SetNewTargetDelegate SetNewTargetEvent;
        //public event UpdateTargetDelegate UpdateTargetEvent;
        public event FreeDelegate FreeEvent;

        public List<MyButton.UnpressDelegate> UnpressesFloorButtonEvent;
        public List<MyButton.UnpressDelegate> UnpressesElevButtonEvent;
        public Controller(List<MyButton> floor_b, List<MyButton> elev_b) 
        {
            state = ControllerState.FREE;
            cur_floor = 1;
            target_floor = -1;
            direction = Direction.STAY;

            need_to_visit = new List<bool>();
            UnpressesFloorButtonEvent = new List<MyButton.UnpressDelegate>();
            UnpressesElevButtonEvent = new List<MyButton.UnpressDelegate>();
            for (int i = 0; i < 5; i++)
            {
                UnpressesFloorButtonEvent.Add(floor_b[i].Unpress);
                UnpressesElevButtonEvent.Add(elev_b[i].Unpress);
                need_to_visit.Add(false);
            }
            floor_buttons = floor_b;
            elevator_buttons = elev_b;
            SetNewTargetEvent += this.SetNewTarget;
            //UpdateTargetEvent += this.UpdateTarget;
            FreeEvent += this.Free;
        }

        public delegate void SetNewTargetDelegate(int floor);
        public void SetNewTarget(int floor)
        {
            state = ControllerState.BUSY;

            if (need_to_visit[floor - 1] == true)
                CallCabinEvent(floor);
    
            need_to_visit[floor - 1] = true;

            if (target_floor == -1)
                target_floor = floor;

            if ((direction == Direction.UP && floor > target_floor) ||
                (direction == Direction.DOWN && floor < target_floor))
                target_floor = floor;

            if (cur_floor > target_floor)
                direction = Direction.DOWN;
            else
                direction = Direction.UP;
            CallCabinEvent(floor);
        }

        public delegate void UpdateTargetDelegate(int floor);
        public void UpdateTarget(int floor) 
        {
            if (state == ControllerState.BUSY) 
            {
                state = ControllerState.UPDATING_TARGET;

                cur_floor = floor;
                need_to_visit[floor - 1] = false;
                floor_buttons[floor - 1].Unpress();
                elevator_buttons[floor - 1].Unpress();
                
                if (cur_floor == target_floor)
                {
                    target_floor = -1;
                    GetNewTarget();
                }
                if (NextTarget(ref floor))
                {
                    if (cur_floor > target_floor)
                        direction = Direction.DOWN;
                    else
                        direction = Direction.UP;
                    SetNewTargetEvent.Invoke(floor);
                }
                else
                    FreeEvent.Invoke();
            }
        }
        public delegate void FreeDelegate();
        public void Free()
        {
            if (state == ControllerState.UPDATING_TARGET)
                state = ControllerState.FREE;
        }
        void GetNewTarget() 
        {
            if (direction == Direction.UP)
            {
                for (int i = 5; i >= 1; i--)
                {
                    if (need_to_visit[i - 1] == true)
                    {
                        target_floor = i;
                        return;
                    }
                }
            }
            else
            {
                for (int i = 1; i <= 5; i++)
                {
                    if (need_to_visit[i - 1] == true)
                    {
                        target_floor = i;
                        break;
                    }
                }
            }
        }
        bool NextTarget(ref int floor) 
        {
            if (target_floor > cur_floor)
            {
                for (int i = cur_floor; i <= 5; i++)
                {
                    if (need_to_visit[i - 1])
                    {
                        floor = i;
                        return true;
                    }
                }
            }
            else
            {
                for (int i = cur_floor; i >= 1; i--)
                {
                    if (need_to_visit[i - 1])
                    {
                        floor = i;
                        return true;
                    }
                }
            }
            return false;
        }
        public delegate void PassFloorDelegate(int floor);
        public void PassFloor(int floor) 
        {
            cur_floor = floor;
            Debug.WriteLine(string.Format("Лифт проходит этаж №{0}", floor));
        }
    }
}
