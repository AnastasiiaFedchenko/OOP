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
            BUSY
        };
        public enum Direction 
        {
            UP = 1, 
            STAY = 0,
            DOWN = -1
        }
        List<ControllerState> state;
        List<int> cur_floor;
        List<int> target_floor;
        List<Direction> direction;

        List<bool> need_to_visit;
        public List<MyButton> floor_buttons;
        public List<MyButton> elevator_buttons1;
        public List<MyButton> elevator_buttons2;

        public event Cabin.CallCabinDelegate CallCabin1Event;
        public event Cabin.CallCabinDelegate CallCabin2Event;

        public List<MyButton.UnpressDelegate> UnpressesFloorButtonEvent;
        public List<MyButton.UnpressDelegate> UnpressesElev1ButtonEvent;
        public List<MyButton.UnpressDelegate> UnpressesElev2ButtonEvent;
        public Controller(List<MyButton> floor_b, List<MyButton> elev_b1, List<MyButton> elev_b2) 
        {
            state = new List<ControllerState>();
            cur_floor = new List<int>();
            target_floor = new List<int>();
            direction = new List<Direction>();

            state.Add(ControllerState.FREE);
            state.Add(ControllerState.FREE);
            cur_floor.Add(1);
            cur_floor.Add(1);
            target_floor.Add(1);
            target_floor.Add(1);
            direction.Add(Direction.STAY);
            direction.Add(Direction.STAY);

            need_to_visit = new List<bool>();
            UnpressesFloorButtonEvent = new List<MyButton.UnpressDelegate>();
            UnpressesElev1ButtonEvent = new List<MyButton.UnpressDelegate>();
            UnpressesElev2ButtonEvent = new List<MyButton.UnpressDelegate>();
            for (int i = 0; i < 5; i++)
            {
                UnpressesFloorButtonEvent.Add(floor_b[i].Unpress);
                UnpressesElev1ButtonEvent.Add(elev_b1[i].Unpress);
                UnpressesElev2ButtonEvent.Add(elev_b2[i].Unpress);
                need_to_visit.Add(false);
            }
            floor_buttons = floor_b;
            elevator_buttons1 = elev_b1;
            elevator_buttons2 = elev_b2;
        }

        public delegate void SetNewTargetDelegate(int floor, int elev_n);
        public void SetNewTarget(int floor, int elev_n) 
        {
            if (elev_n == 0)
            {
                if (state[0] == ControllerState.FREE) elev_n = 1;
                else if (state[1] == ControllerState.FREE) elev_n = 2;
                else
                    elev_n = 1;
            }
            if (need_to_visit[floor - 1] == true)
                return;
            state[elev_n - 1] = ControllerState.BUSY;
            need_to_visit[floor - 1] = true;

            if (target_floor[elev_n - 1] == -1)
                target_floor[elev_n - 1] = floor;

            if ((direction[elev_n - 1] == Direction.UP && floor > target_floor[elev_n - 1]) ||
                (direction[elev_n - 1] == Direction.DOWN && floor < target_floor[elev_n - 1]))
                target_floor[elev_n - 1] = floor;

            if (cur_floor[elev_n - 1] > target_floor[elev_n - 1])
                direction[elev_n - 1] = Direction.DOWN;
            else
                direction[elev_n - 1] = Direction.UP;
            if (elev_n == 1)
                CallCabin1Event(floor);
            else 
                CallCabin2Event(floor);
        }
        void GetNewTarget(int elev_n) 
        {
            if (direction[elev_n - 1] == Direction.UP)
            {
                for (int i = 5; i >= 1; i--)
                {
                    if (need_to_visit[i - 1] == true)
                    {
                        target_floor[elev_n - 1] = i;
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
                        target_floor[elev_n - 1] = i;
                        break;
                    }
                }
            }
        }
        bool NextTarget(ref int floor, int elev_n) 
        {
            if (target_floor[elev_n - 1] > cur_floor[elev_n - 1])
            {
                for (int i = cur_floor[elev_n - 1]; i <= 5; i++)
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
                for (int i = cur_floor[elev_n - 1]; i >= 1; i--)
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

        public delegate void ReachFloorDelegate(int floor, int elev_n);
        public void ReachFloor(int floor, int elev_n)
        {
            if (state[elev_n - 1] == ControllerState.BUSY)
            {
                cur_floor[elev_n - 1] = floor;
                need_to_visit[floor - 1] = false;
                UnpressesFloorButtonEvent[floor - 1].Invoke();
                //floor_buttons[floor - 1].Unpress();
                if (elev_n == 1)
                    UnpressesElev1ButtonEvent[floor - 1].Invoke();
                else
                    UnpressesElev2ButtonEvent[floor - 1].Invoke();

                if (cur_floor[elev_n - 1] == target_floor[elev_n - 1])
                {
                    target_floor[elev_n - 1] = -1;
                    GetNewTarget(elev_n);
                }
                if (NextTarget(ref floor, elev_n))
                {
                    if (cur_floor[elev_n - 1] > target_floor[elev_n - 1])
                        direction[elev_n - 1] = Direction.DOWN;
                    else
                        direction[elev_n - 1] = Direction.UP;
                    if (elev_n == 1)
                        CallCabin1Event(floor);
                    else
                        CallCabin2Event(floor);
                }
                else
                    state[elev_n - 1] = ControllerState.FREE;
            }
        }

        public delegate void PassFloorDelegate(int floor, int elev_n);
        public void PassFloor(int floor, int elev_n) 
        {
            cur_floor[elev_n - 1] = floor;
            Debug.WriteLine(string.Format("Лифт №{0} проходит этаж №{1}", elev_n, floor));
        }
    }
}
