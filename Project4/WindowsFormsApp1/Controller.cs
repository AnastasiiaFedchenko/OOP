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

namespace WindowsFormsApp1
{
    public class Controller
    {
        enum ControllerState
        {
            FREE,
            BUSY
        };
        enum Direction 
        {
            UP = -1, 
            STAY = 0,
            DOWN = 1
        }
        ControllerState state;
        int cur_floor;
        int target_floor;
        Direction direction;
        Direction last_direction;
        List<bool> need_to_visit;
        public List<MyButton> floor_buttons;
        public List<MyButton> elevator_buttons;

        public event Cabin.MoveCabinDelegate moveCabin;
        public event Cabin.StopCabinDelegate stopCabin;
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

        /*public delegate void FreeDelegate();
        public void free() 
        {
            this.state = ControllerState.FREE;
            cur_floor = this.target_floor;
            NewTarget(false, 0);
        }*/

        public delegate void NewTargetDelegate(bool got_new, int floor);
        public void NewTarget(bool got_new, int floor)
        {
            this.state = ControllerState.BUSY;
            if (got_new)
            {
                this.need_to_visit[floor - 1] = true;
                identifyNewTarget(out floor);
                target_floor = floor;
                decideDirection();
                if (direction == Direction.STAY)
                    reachFloor();
                else
                {
                    moveCabin.Invoke(Math.Abs(cur_floor - target_floor) * 2000);
                }
            }
            else if (identifyNewTarget(out floor))
            {
                target_floor = floor;
                decideDirection();
                if (direction == Direction.STAY)
                    reachFloor();
                else
                {
                    updateFloor();
                    moveCabin.Invoke(Math.Abs(cur_floor - target_floor) * 2000);
                }
            }
        }
        void decideDirection() 
        {
            if (target_floor > cur_floor)
                direction = Direction.UP;
            else if (target_floor < cur_floor)
                direction = Direction.DOWN;
            else
            {
                last_direction = direction;
                direction = Direction.STAY;
            }
        }
        
        bool identifyNewTarget(out int new_target) 
        {
            bool rc = false;
            Direction dir;
            new_target = 0;

            if (direction != Direction.STAY)
                dir = direction;
            else
                dir = (last_direction == Direction.STAY) ? Direction.UP : last_direction;

            for (int i = cur_floor; !rc && i <= 5 && i > 0; i = i + (int)dir)
                if (need_to_visit[i - 1])
                {
                    new_target = i;
                    rc = true;
                }

            if (!rc)
            {
                dir = ((dir == Direction.UP) ? Direction.DOWN : Direction.UP);

                for (int i = cur_floor; !rc && i <= 5 && i > 0; i = i + (int)dir)
                {
                    if (need_to_visit[i - 1])
                    {
                        new_target = i;
                        rc = true;
                    }
                }
            }

            return rc;
        }
        public delegate void ReachFloor(Object my_object, EventArgs my_args);
        public void reachFloor(Object my_object, EventArgs my_args) 
        {
            // Если контроллер не занят, выходим [лифт не движется]
            if (this.state != ControllerState.BUSY) return;

            Debug.WriteLine(string.Format("Лифт на этаже №{0}", target_floor));

            if ((target_floor - 1) >= 0 && (target_floor - 1) < 5)
            {
                floor_buttons[target_floor - 1].Unpress(); // кнопка разжимается
                elevator_buttons[target_floor - 1].Unpress();
                need_to_visit[target_floor - 1] = false; // посещать его уже не надо
            }

            if (identifyNewTarget(out this.target_floor))
                stopCabin();
            else
            {
                this.state = ControllerState.FREE;
                stopCabin();
            }
        }
        public void reachFloor()
        {
            // Если контроллер не занят, выходим [лифт не движется]
            if (this.state != ControllerState.BUSY) return;

            Debug.WriteLine(string.Format("Лифт на этаже №{0}", target_floor));

            if ((target_floor - 1) >= 0 && (target_floor - 1) < 5)
            {
                floor_buttons[target_floor - 1].Unpress(); // кнопка разжимается
                elevator_buttons[target_floor - 1].Unpress();
                need_to_visit[target_floor - 1] = false; // посещать его уже не надо
            }
            
            if (identifyNewTarget(out this.target_floor))
                stopCabin();
            else 
            {
                this.state = ControllerState.FREE;
                stopCabin();
            }
        }
        void updateFloor()
        {
            cur_floor += (int)direction;
            //qDebug() << "... Лифт едет на этаж № " << _curFloor;
        }
    }
}
