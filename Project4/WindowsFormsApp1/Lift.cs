using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public class Lift
    {
        Controller controller;
        Cabin cabin;
        public Lift(List<MyButton> floor_b, List<MyButton> elev_b1) 
        {
            controller = new Controller(floor_b, elev_b1);

            for (int i = 0; i < controller.floor_buttons.Count; i++)
            {
                controller.floor_buttons[i].SetNewTarget += this.controller.SetNewTarget;
            }
            for (int i = 0; i < controller.elevator_buttons.Count; i++)
            {
                controller.elevator_buttons[i].SetNewTarget += this.controller.SetNewTarget;
            }

            cabin = new Cabin();
            cabin.PassFloorEvent += controller.PassFloor;
            cabin.ReachFloorEvent += controller.ReachFloor;

            controller.CallCabinEvent += cabin.CallCabin;
        }
    }
}
