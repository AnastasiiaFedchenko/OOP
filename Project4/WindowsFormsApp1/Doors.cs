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
        public event Cabin.FreeDelegate free;

        public Doors() 
        {
            closeTimer.Tick += new EventHandler(Close);
            openTimer.Tick += new EventHandler(Open);
            waitTimer.Tick += new EventHandler(StartClosing);
            this.state = DoorState.CLOSED; 
        }

        public void StartClosing(Object my_object, EventArgs my_args) 
        {
            // Если двери до этого не открыты, закрывать не можем
            if (this.state != DoorState.OPEN) return;

            this.state = DoorState.CLOSING;

            Debug.WriteLine(string.Format("Двери закрываются..."));

            this.closeTimer.Interval = 2000;
            this.closeTimer.Start();
        }
        public void StartOpening()
        {
            if (!(this.state == DoorState.CLOSED || this.state == DoorState.CLOSING)) return;

            Debug.WriteLine(string.Format("Двери открываются..."));

            if (this.state == DoorState.CLOSED)
            {
                this.openTimer.Interval = 2000;
                this.openTimer.Start();
            }
            else
            {
                int timer = this.closeTimer.Interval;
                closeTimer.Stop();
                this.openTimer.Interval = 2000 - timer;
                this.openTimer.Start();
            }
            this.state = DoorState.OPENING;
        }

        public void Open(Object my_object, EventArgs my_args) 
        {
            // Если двери до этого не открывались, выходим
            if (this.state != DoorState.OPENING) return;

            // Изменение состояния
            this.state = DoorState.OPEN;

            //listBox.Invoke(PrintDelegateFunc, new object[] 
            //{ string.Format("Двери открылись!") });
            Debug.WriteLine(string.Format("Двери открылись!"));
            Debug.WriteLine(string.Format("Можно заходить."));

            // Запуск таймера
            this.waitTimer.Interval = 3000;
            this.waitTimer.Start();

        }
        public void Close(Object my_object, EventArgs my_args) 
        {
            // Если двери до этого не закрывались, выходим
            if (this.state != DoorState.CLOSING) return;

            // Изменение состояния
            this.state = DoorState.CLOSED;

            Debug.WriteLine(string.Format("Двери закрылись!"));

            // Сообщаем другим, что мы закрылись
            free.Invoke();
        }
    }
}
