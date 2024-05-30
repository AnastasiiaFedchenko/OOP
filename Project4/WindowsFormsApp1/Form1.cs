using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace WindowsFormsApp1
{
    
    public partial class Form1 : Form
    {
        Lift lift;
        public Form1()
        {
            InitializeComponent();
            List <MyButton> floor_b = new List <MyButton> ();
            floor_b.Add(FloorButton1);
            floor_b.Add(FloorButton2);
            floor_b.Add(FloorButton3);
            floor_b.Add(FloorButton4);
            floor_b.Add(FloorButton5);

            List<MyButton> elev_b = new List<MyButton>();
            elev_b.Add(Elevator1Button1);
            elev_b.Add(Elevator1Button2);
            elev_b.Add(Elevator1Button3);
            elev_b.Add(Elevator1Button4);
            elev_b.Add(Elevator1Button5);

            lift = new Lift(floor_b, elev_b);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }
    }
}
