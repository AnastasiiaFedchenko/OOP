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
        ControllerState state;
        int cur_floor;
        int target_floor;
        Direction direction;
        Direction last_direction;
        List<bool> need_to_visit;
        public List<MyButton> floor_buttons;
        public List<MyButton> elevator_buttons;

        public event Cabin.CallCabinDelegate CallCabin;
        public Controller(List<MyButton> floor_b, List<MyButton> elev_b) 
        {
            state = ControllerState.FREE;
            cur_floor = 1;
            target_floor = 1;
            need_to_visit = new List<bool>();
            for (int i = 0; i < 5; i++)
                need_to_visit.Add(false);
            floor_buttons = floor_b;
            elevator_buttons = elev_b;
        }

        public delegate void SetNewTargetDelegate(int floor);
        public void SetNewTarget(int floor) 
        {
            if (need_to_visit[floor - 1] == true)
                return;
            state = ControllerState.BUSY;
            need_to_visit[floor - 1] = true;

            if (target_floor == -1)
                target_floor = floor;

            if ((direction == Direction.UP && floor > target_floor) || 
                (direction == Direction.DOWN && floor < target_floor))
            {
                target_floor = floor;
            }

            // Если лифт стоял и ему дали новую цель, определим его направление движения
            if (cur_floor > target_floor)
                direction = Direction.DOWN;
            else
                direction = Direction.UP;

            CallCabin(floor);
        }
        void GetNewTarget() 
        {
            // Если двигались вверх, ищем ближайший сверху(не нашли - смотрим ниже)
            if (direction == Direction.UP)
            {
                for (int i = 5; i >= 1; i--)
                    if (need_to_visit[i - 1] == true)
                    {
                        target_floor = i;
                        return;
                    }
            }
            // Если двигались в низ/стояли - ищем ближайший снизу(не нашли - смотрим выше)
            else
            {
                for (int i = 1; i <= 5; i++)
                    if (need_to_visit[i - 1] == true)
                    {
                        target_floor = i;
                        break;
                    }
            }
        }
        bool NextTarget(ref int floor) 
        {
            if (target_floor > cur_floor)
            {
                for (int i = cur_floor; i <= 5; i++)
                    if (need_to_visit[i - 1])
                    {
                        floor = i;
                        return true;
                    }
            }
            else
            {
                for (int i = cur_floor; i >= 1; i--)
                    if (need_to_visit[i - 1])
                    {
                        floor = i;
                        return true;
                    }
            }
            return false;
        }

        public delegate void ReachFloorDelegate(int floor);
        public void ReachFloor(int floor)
        {
            // Если достигли во время работы
            if (state == ControllerState.BUSY)
            {
                cur_floor = floor; // Обновляем текущий этаж на котором находится лифт
                need_to_visit[floor - 1] = false; // При достижении этажа удаляем его из целей
                floor_buttons[floor -1].Unpress();
                elevator_buttons[floor - 1].Unpress();

                // Если достигли целевого этажа - устанавливаем новую цель
                if (cur_floor == target_floor)
                {
                    target_floor = -1;
                    GetNewTarget();
                }
                // Если еще остались этажи, куда нужно доехать - устанавливаем новую ближайшую цель
                if (NextTarget(ref floor))
                {
                    if (cur_floor > target_floor)
                        direction = Direction.DOWN;
                    else
                        direction = Direction.UP;
                    CallCabin(floor);
                }
                // Если добрались до всех этажей - контроллер свободен
                else
                    state = ControllerState.FREE;
            }
        }

        public delegate void PassFloorDelegate(int floor);
        public void PassFloor(int floor) 
        {
            cur_floor = floor;
            Debug.WriteLine(string.Format("Лифт проходит этаж №{0}", floor));
        }
    }
}
