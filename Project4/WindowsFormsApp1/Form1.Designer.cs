namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        public System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.FloorButton1 = new MyButton(1, MyButton.ButtonPlacement.FLOOR);
            this.FloorButton2 = new MyButton(2, MyButton.ButtonPlacement.FLOOR);
            this.FloorButton3 = new MyButton(3, MyButton.ButtonPlacement.FLOOR);
            this.FloorButton4 = new MyButton(4, MyButton.ButtonPlacement.FLOOR);
            this.FloorButton5 = new MyButton(5, MyButton.ButtonPlacement.FLOOR);

            this.Elevator1Button1 = new MyButton(1, MyButton.ButtonPlacement.ELEV);
            this.Elevator1Button2 = new MyButton(2, MyButton.ButtonPlacement.ELEV);
            this.Elevator1Button3 = new MyButton(3, MyButton.ButtonPlacement.ELEV);
            this.Elevator1Button4 = new MyButton(4, MyButton.ButtonPlacement.ELEV);
            this.Elevator1Button5 = new MyButton(5, MyButton.ButtonPlacement.ELEV);

            this.FloorGroupBox = new System.Windows.Forms.GroupBox();
            this.Elevator1GroupBox = new System.Windows.Forms.GroupBox();
            this.FloorGroupBox.SuspendLayout();
            this.Elevator1GroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // FloorButton1
            // 
            this.FloorButton1.Location = new System.Drawing.Point(6, 62);
            this.FloorButton1.Name = "FloorButton1";
            this.FloorButton1.Size = new System.Drawing.Size(397, 54);
            this.FloorButton1.TabIndex = 1;
            this.FloorButton1.Text = "1";
            this.FloorButton1.UseVisualStyleBackColor = true;
            // 
            // FloorButton2
            // 
            this.FloorButton2.Location = new System.Drawing.Point(6, 122);
            this.FloorButton2.Name = "FloorButton2";
            this.FloorButton2.Size = new System.Drawing.Size(397, 54);
            this.FloorButton2.TabIndex = 2;
            this.FloorButton2.Text = "2";
            this.FloorButton2.UseVisualStyleBackColor = true;
            // 
            // FloorButton3
            // 
            this.FloorButton3.Location = new System.Drawing.Point(6, 182);
            this.FloorButton3.Name = "FloorButton3";
            this.FloorButton3.Size = new System.Drawing.Size(397, 54);
            this.FloorButton3.TabIndex = 3;
            this.FloorButton3.Text = "3";
            this.FloorButton3.UseVisualStyleBackColor = true;
            // 
            // FloorButton4
            // 
            this.FloorButton4.Location = new System.Drawing.Point(6, 242);
            this.FloorButton4.Name = "FloorButton4";
            this.FloorButton4.Size = new System.Drawing.Size(397, 54);
            this.FloorButton4.TabIndex = 4;
            this.FloorButton4.Text = "4";
            this.FloorButton4.UseVisualStyleBackColor = true;
            // 
            // FloorButton5
            // 
            this.FloorButton5.Location = new System.Drawing.Point(6, 302);
            this.FloorButton5.Name = "FloorButton5";
            this.FloorButton5.Size = new System.Drawing.Size(397, 54);
            this.FloorButton5.TabIndex = 5;
            this.FloorButton5.Text = "5";
            this.FloorButton5.UseVisualStyleBackColor = true;
            // 
            // Elevator1Button1
            // 
            this.Elevator1Button1.Location = new System.Drawing.Point(6, 62);
            this.Elevator1Button1.Name = "Elevator1Button1";
            this.Elevator1Button1.Size = new System.Drawing.Size(397, 54);
            this.Elevator1Button1.TabIndex = 1;
            this.Elevator1Button1.Text = "1";
            this.Elevator1Button1.UseVisualStyleBackColor = true;
            // 
            // Elevator1Button2
            // 
            this.Elevator1Button2.Location = new System.Drawing.Point(6, 122);
            this.Elevator1Button2.Name = "Elevator1Button2";
            this.Elevator1Button2.Size = new System.Drawing.Size(397, 54);
            this.Elevator1Button2.TabIndex = 2;
            this.Elevator1Button2.Text = "2";
            this.Elevator1Button2.UseVisualStyleBackColor = true;
            // 
            // Elevator1Button3
            // 
            this.Elevator1Button3.Location = new System.Drawing.Point(6, 182);
            this.Elevator1Button3.Name = "Elevator1Button3";
            this.Elevator1Button3.Size = new System.Drawing.Size(397, 54);
            this.Elevator1Button3.TabIndex = 3;
            this.Elevator1Button3.Text = "3";
            this.Elevator1Button3.UseVisualStyleBackColor = true;
            // 
            // Elevator1Button4
            // 
            this.Elevator1Button4.Location = new System.Drawing.Point(6, 242);
            this.Elevator1Button4.Name = "Elevator1Button4";
            this.Elevator1Button4.Size = new System.Drawing.Size(397, 54);
            this.Elevator1Button4.TabIndex = 4;
            this.Elevator1Button4.Text = "4";
            this.Elevator1Button4.UseVisualStyleBackColor = true;
            // 
            // Elevator1Button5
            // 
            this.Elevator1Button5.Location = new System.Drawing.Point(6, 302);
            this.Elevator1Button5.Name = "Elevator1Button5";
            this.Elevator1Button5.Size = new System.Drawing.Size(397, 54);
            this.Elevator1Button5.TabIndex = 5;
            this.Elevator1Button5.Text = "5";
            this.Elevator1Button5.UseVisualStyleBackColor = true;
            // 
            // FloorGroupBox
            // 
            this.FloorGroupBox.Controls.Add(this.FloorButton5);
            this.FloorGroupBox.Controls.Add(this.FloorButton4);
            this.FloorGroupBox.Controls.Add(this.FloorButton3);
            this.FloorGroupBox.Controls.Add(this.FloorButton2);
            this.FloorGroupBox.Controls.Add(this.FloorButton1);
            this.FloorGroupBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.875F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.FloorGroupBox.Location = new System.Drawing.Point(12, 12);
            this.FloorGroupBox.Name = "FloorGroupBox";
            this.FloorGroupBox.Size = new System.Drawing.Size(409, 369);
            this.FloorGroupBox.TabIndex = 2;
            this.FloorGroupBox.TabStop = false;
            this.FloorGroupBox.Text = "Кнопки на этажах:";
            // 
            // Elevator1GroupBox
            // 
            this.Elevator1GroupBox.Controls.Add(this.Elevator1Button1);
            this.Elevator1GroupBox.Controls.Add(this.Elevator1Button2);
            this.Elevator1GroupBox.Controls.Add(this.Elevator1Button3);
            this.Elevator1GroupBox.Controls.Add(this.Elevator1Button4);
            this.Elevator1GroupBox.Controls.Add(this.Elevator1Button5);
            this.Elevator1GroupBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.875F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Elevator1GroupBox.Location = new System.Drawing.Point(438, 12);
            this.Elevator1GroupBox.Name = "Elevator1GroupBox";
            this.Elevator1GroupBox.Size = new System.Drawing.Size(409, 369);
            this.Elevator1GroupBox.TabIndex = 3;
            this.Elevator1GroupBox.TabStop = false;
            this.Elevator1GroupBox.Text = "Кнопки в лифте:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(850, 384);
            this.Controls.Add(this.Elevator1GroupBox);
            this.Controls.Add(this.FloorGroupBox);
            this.Name = "Form1";
            this.Text = "ООП л/р 4";
            this.FloorGroupBox.ResumeLayout(false);
            this.Elevator1GroupBox.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox FloorGroupBox;
        private MyButton FloorButton1;
        private MyButton FloorButton2;
        private MyButton FloorButton3;
        private MyButton FloorButton4;
        private MyButton FloorButton5;
        
        private System.Windows.Forms.GroupBox Elevator1GroupBox;
        private MyButton Elevator1Button1;
        private MyButton Elevator1Button2;
        private MyButton Elevator1Button3;
        private MyButton Elevator1Button4;
        private MyButton Elevator1Button5;
    }
}

