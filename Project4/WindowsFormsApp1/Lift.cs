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
        Cabin cabin1;
        Cabin cabin2;
        public Lift(List<MyButton> floor_b, List<MyButton> elev_b1, List<MyButton> elev_b2) 
        {
            controller = new Controller(floor_b, elev_b1, elev_b2);
            
            for (int i = 0; i < controller.floor_buttons.Count; i++)
                controller.floor_buttons[i].SetNewTarget += this.controller.SetNewTarget;
            for (int i = 0; i < controller.elevator_buttons1.Count; i++)
                controller.elevator_buttons1[i].SetNewTarget += this.controller.SetNewTarget;
            for (int i = 0; i < controller.elevator_buttons2.Count; i++)
                controller.elevator_buttons2[i].SetNewTarget += this.controller.SetNewTarget;

            cabin1 = new Cabin(1);
            cabin1.PassFloor += controller.PassFloor;
            cabin1.ReachFloor += controller.ReachFloor;

            controller.CallCabin1 += cabin1.CallCabin;

            cabin2 = new Cabin(2);
            cabin2.PassFloor += controller.PassFloor;
            cabin2.ReachFloor += controller.ReachFloor;

            controller.CallCabin2 += cabin2.CallCabin;
        }
    }
}
