﻿using System;
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
        enum CabinState
        {
            WAIT,
            MOVING,
            STOP
        };
        CabinState state;
        Doors doors;
        int cur_floor;
        int target_floor;
        bool new_target;
        Direction direction;
        public System.Windows.Forms.Timer moveTimer = new System.Windows.Forms.Timer();
        public event PassFloorDelegate PassFloorEvent;
        public event UpdateTargetDelegate UpdateTargetEvent;
        public event StopCabinDelegate StopCabinEvent;
        public event Doors.StartOpeningDelegate StartOpeningEvent;
        public event Doors.StartClosingDelegate StartClosingEvent;

        public Cabin() 
        {
            state = CabinState.STOP;
            doors = new Doors();
            doors.MoveCabinEvent += this.MoveCabin;
            StartOpeningEvent += doors.StartOpening;
            cur_floor = 1;
            target_floor = -1;
            new_target = false;
            direction = Direction.STAY;
            moveTimer.Tick += new EventHandler(MoveCabin);
            StopCabinEvent += StopCabin;
            StartClosingEvent += doors.StartClosing;
        }
        public delegate void MoveCabinDelegate();
        public void MoveCabin() 
        {
            if (new_target)
            {
                if (state == CabinState.WAIT)
                {
                    state = CabinState.MOVING;
                    if (cur_floor == target_floor)
                        StopCabin();
                    else
                    {
                        moveTimer.Interval = 500;
                        moveTimer.Start();
                    }
                }
                else if (state == CabinState.MOVING)
                {
                    cur_floor += (int)direction;
                    if (cur_floor == target_floor)
                        StopCabin();
                    else
                    {
                        PassFloorEvent.Invoke(cur_floor);
                        moveTimer.Interval = 500;
                        moveTimer.Start();
                    }
                }
            }
        }
        public void MoveCabin(Object my_object, EventArgs my_args)
        {
            moveTimer.Stop();
            if (new_target)
            {
                if (state == CabinState.WAIT)
                {
                    state = CabinState.MOVING;
                    if (cur_floor == target_floor)
                        StopCabinEvent.Invoke();
                    else
                    {
                        moveTimer.Interval = 500;
                        moveTimer.Start();
                    }
                }
                else if (state == CabinState.MOVING)
                {
                    cur_floor += (int)direction;
                    if (cur_floor == target_floor)
                        StopCabinEvent.Invoke();
                    else
                    {
                        PassFloorEvent.Invoke(cur_floor);
                        moveTimer.Interval = 500;
                        moveTimer.Start();
                    }
                }
            }
        }
        public delegate void StopCabinDelegate();
        public void StopCabin()
        {
            if (state == CabinState.MOVING)
            {
                state = CabinState.STOP;
                Debug.WriteLine(string.Format("Лифт остановился на этаже №{0}", cur_floor));
                StartOpeningEvent.Invoke();
                UpdateTargetEvent.Invoke(cur_floor);
            }
        }
        public delegate void CallCabinDelegate(int floor);
        public void CallCabin(int floor) 
        {
            if (state == CabinState.STOP)
            {
                new_target = true;
                state = CabinState.WAIT;
                target_floor = floor;

                if (target_floor > cur_floor)
                    direction = Direction.UP;
                else if (target_floor < cur_floor)
                    direction = Direction.DOWN;
                else
                    direction = Direction.STAY;

                StartClosingEvent.Invoke();
            }
        }
    }
}
