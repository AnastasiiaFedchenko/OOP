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
        System.Windows.Forms.Timer openTimer = new System.Windows.Forms.Timer();
        System.Windows.Forms.Timer waitTimer = new System.Windows.Forms.Timer();
        System.Windows.Forms.Timer closeTimer = new System.Windows.Forms.Timer();
        public event Cabin.MoveCabinDelegate MoveCabinEvent;

        public Doors() 
        {
            closeTimer.Tick += new EventHandler(Close);
            openTimer.Tick += new EventHandler(Open);
            waitTimer.Tick += new EventHandler(StartClosing);
            this.state = DoorState.CLOSED;
        }

        public delegate void StartClosingDelegate();
        public void StartClosing() 
        {
            if (state == DoorState.OPEN)
            {
                state = DoorState.CLOSING;
                Debug.WriteLine(string.Format("Двери закрываются..."));
                this.closeTimer.Interval = 1000;
                this.closeTimer.Start();
            }
            else if (state == DoorState.CLOSED)
                MoveCabinEvent.Invoke();
        }
        public void StartClosing(Object my_object, EventArgs my_args)
        {
            if (state == DoorState.OPEN)
            {
                waitTimer.Stop();
                state = DoorState.CLOSING;
                Debug.WriteLine(string.Format("Двери закрываются..."));
                this.closeTimer.Interval = 1000;
                this.closeTimer.Start();
            }
            else if (state == DoorState.CLOSED)
                MoveCabinEvent.Invoke();
        }

        public delegate void StartOpeningDelegate();
        public void StartOpening()
        {
            if (state == DoorState.CLOSED)
            {
                state = DoorState.OPENING;
                Debug.WriteLine(string.Format("Двери открываются..."));
                this.openTimer.Interval = 1000;
                this.openTimer.Start();
            }
        }
        public void Open(Object my_object, EventArgs my_args) 
        {
            if (state == DoorState.OPENING)
            {
                openTimer.Stop();
                state = DoorState.OPEN;
                Debug.WriteLine(string.Format("Двери открыты. Можно заходить."));
                this.waitTimer.Interval = 3000;
                this.waitTimer.Start();
            }
        }
        public void Close(Object my_object, EventArgs my_args) 
        {
            if (state == DoorState.CLOSING)
            {
                closeTimer.Stop();
                state = DoorState.CLOSED;
                Debug.WriteLine(string.Format("Двери закрыты."));
                MoveCabinEvent.Invoke();
            }
        }
    }
}
