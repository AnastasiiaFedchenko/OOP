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
        public Lift(List<MyButton> floor_b, List<MyButton> elev_b) 
        {
            controller = new Controller(floor_b, elev_b);
            for (int i = 0; i < controller.floor_buttons.Count; i++)
                controller.floor_buttons[i].newTarget += this.controller.NewTarget;
            for (int i = 0; i < controller.elevator_buttons.Count; i++)
                controller.elevator_buttons[i].newTarget += this.controller.NewTarget;

            cabin = new Cabin();
            cabin.newTarget += controller.NewTarget;
            cabin.moveTimer.Tick += new EventHandler(controller.reachFloor);
            controller.moveCabin += cabin.moveCabin;
            controller.stopCabin += cabin.stopCabin;
        }
    }
}
