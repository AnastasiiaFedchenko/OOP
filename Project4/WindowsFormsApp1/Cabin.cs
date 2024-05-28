using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.AxHost;
using static WindowsFormsApp1.Controller;
using static WindowsFormsApp1.Form1;

namespace WindowsFormsApp1
{
    public class Cabin
    {
        enum State
        {
            WAIT,
            MOVING,
            STOP
        };
        State state;
        Doors doors;
        //public event Controller.FreeDelegate free_controller;
        public event Controller.NewTargetDelegate newTarget;

        public System.Windows.Forms.Timer moveTimer = new System.Windows.Forms.Timer();
        public Cabin() 
        {
            state = State.STOP;
            doors = new Doors();
            doors.free += this.free;
        }
        public delegate void StopCabinDelegate();
        public void stopCabin()
        {
            this.state = State.WAIT;
            this.moveTimer.Stop();
            doors.StartOpening();
        }
        public delegate void MoveCabinDelegate(int moving_interval);
        public void moveCabin(int moving_interval) 
        {
            if (this.state == State.STOP || this.state == State.MOVING)
            {
                this.state = State.MOVING;
                Debug.WriteLine("\n...\nЕдем\n...\n");
                // здесь должно быть отмеренно время для движения
                this.moveTimer.Interval = moving_interval;
                this.moveTimer.Start();
            }
        }
        public delegate void FreeDelegate();
        public void free() 
        {
            if (this.state != State.STOP)
            {
                this.state = State.STOP;
                newTarget.Invoke(false, 0);
            }
        }
    }
}
