using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.Design;
using static System.Windows.Forms.AxHost;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ToolTip;
using static WindowsFormsApp1.Controller;
using static WindowsFormsApp1.Form1;

namespace WindowsFormsApp1
{
    public class Doors
    {
        enum DoorState{
            OPEN,
            CLOSED,
            OPENING,
            CLOSING
        };
        DoorState state;
        int floor;
        System.Windows.Forms.Timer openTimer = new System.Windows.Forms.Timer();
        System.Windows.Forms.Timer waitTimer = new System.Windows.Forms.Timer();
        System.Windows.Forms.Timer closeTimer = new System.Windows.Forms.Timer();
        public event Cabin.MoveCabinDelegate MoveCabin;
        //public event Cabin.FreeCabinDelegate FreeCabin;
        //public event ReachFloorDelegate ReachFloor;

        public Doors() 
        {
            closeTimer.Tick += new EventHandler(Close);
            openTimer.Tick += new EventHandler(Open);
            waitTimer.Tick += new EventHandler(StartClosing);
            this.state = DoorState.CLOSED; 
        }

        public void StartClosing() 
        {
            if (state == DoorState.OPEN)
            {
                state = DoorState.CLOSING; // Переход в состояние закрытия дверей
                Debug.WriteLine("Двери закрываются...");
                this.closeTimer.Interval = 1000;
                this.closeTimer.Start();
            }
            else if (state == DoorState.CLOSED)
            {
                //FreeCabin.Invoke();
                //ReachFloor.Invoke(this.floor);
                MoveCabin.Invoke();
            }
        }
        public void StartClosing(Object my_object, EventArgs my_args)
        {
            if (state == DoorState.OPEN)
            {
                waitTimer.Stop();
                state = DoorState.CLOSING; // Переход в состояние закрытия дверей
                Debug.WriteLine("Двери закрываются...");
                this.closeTimer.Interval = 1000;
                this.closeTimer.Start();
            }
            else if (state == DoorState.CLOSED)
            {
                //FreeCabin.Invoke();
                //ReachFloor.Invoke(this.floor);
                MoveCabin.Invoke();
            }
        }
        public void StartOpening(int floor)
        {
            if (state == DoorState.CLOSED)
            {
                this.floor = floor;
                state = DoorState.OPENING; // Переход в состояние открытия дверей
                Debug.WriteLine("Двери открываются...");
                this.openTimer.Interval = 1000;
                this.openTimer.Start();
            }
            else if (state == DoorState.OPEN)
            {
                this.waitTimer.Interval = 3000;
                this.waitTimer.Start();
            }
        }

        public void Open(Object my_object, EventArgs my_args) 
        {
            if (state == DoorState.OPENING)
            {
                openTimer.Stop();
                state = DoorState.OPEN; // Переход в состояние открытых дверей
                Debug.WriteLine("Двери открыты. Можно заходить.");
                this.waitTimer.Interval = 3000;
                this.waitTimer.Start();
            }
            else if (state == DoorState.OPEN)
            {
                this.waitTimer.Interval = 3000;
                this.waitTimer.Start();
            }

        }
        public void Close(Object my_object, EventArgs my_args) 
        {
            if (state == DoorState.CLOSING)
            {
                closeTimer.Stop();
                state = DoorState.CLOSED; // Переход в состояние закрытых дверей
                Debug.WriteLine("Двери закрыты.");
                //FreeCabin.Invoke();
                //ReachFloor.Invoke(this.floor);
                MoveCabin.Invoke();
            }
        }
    }
}
