using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static WindowsFormsApp1.Form1;

namespace WindowsFormsApp1
{
    public class MyButton: System.Windows.Forms.Button
    {
        enum ButtonState
        {
            ACTIVE,
            INACTIVE
        };
        public enum ButtonPlacement 
        {
            FLOOR = 0,
            ELEV = 1
        }
        ButtonState state;
        int floor;
        ButtonPlacement placement;

        public event Controller.SetNewTargetDelegate SetNewTarget; 
        public MyButton(int floor, ButtonPlacement placement) : base() 
        { 
            this.state = ButtonState.INACTIVE;
            this.floor = floor;
            this.placement = placement;
        }
        protected override void OnClick(EventArgs e) 
        {
            if (this.state != ButtonState.INACTIVE) return;

            this.state = ButtonState.ACTIVE;
            if (this.placement == ButtonPlacement.FLOOR)
                Debug.WriteLine(string.Format("Вызов на этаж №{0}", this.floor));
            else if (this.placement == ButtonPlacement.ELEV)
                Debug.WriteLine(string.Format("Вызов лифта на этаж №{0}", this.floor));
            this.Enabled = false;
            SetNewTarget.Invoke(this.floor);
        }

        public delegate void UnpressDelegate();
        public void Unpress() 
        {
            if (this.state == ButtonState.INACTIVE) return;

            this.state = ButtonState.INACTIVE;
            this.Enabled = true;
        }
    }
}
