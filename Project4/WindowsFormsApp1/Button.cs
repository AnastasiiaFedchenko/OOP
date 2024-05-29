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
        ButtonState state;
        int floor;
        public event Controller.SetNewTargetDelegate SetNewTarget; 
        public MyButton(int floor): base() 
        { 
            this.state = ButtonState.INACTIVE;
            this.floor = floor;
        }
        protected override void OnClick(EventArgs e) 
        {
            if (this.state != ButtonState.INACTIVE) return;

            this.state = ButtonState.ACTIVE;
            Debug.WriteLine(string.Format("Вызов на этаж №{0}", this.floor));
            this.Enabled = false;
            SetNewTarget.Invoke(this.floor);
        }
        public void Unpress() 
        {
            if (this.state == ButtonState.INACTIVE) return;

            this.state = ButtonState.INACTIVE;
            this.Enabled = true;
        }
    }
}
