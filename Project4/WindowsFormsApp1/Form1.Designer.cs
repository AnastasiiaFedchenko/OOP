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
            this.FloorButton1 = new MyButton(1);
            this.FloorButton2 = new MyButton(2);
            this.FloorButton3 = new MyButton(3);
            this.FloorButton4 = new MyButton(4);
            this.FloorButton5 = new MyButton(5);

            this.ElevatorButton1 = new MyButton(1);
            this.ElevatorButton2 = new MyButton(2);
            this.ElevatorButton3 = new MyButton(3);
            this.ElevatorButton4 = new MyButton(4);
            this.ElevatorButton5 = new MyButton(5);

            this.FloorGroupBox = new System.Windows.Forms.GroupBox();
            this.ElevatorGroupBox = new System.Windows.Forms.GroupBox();
            this.FloorGroupBox.SuspendLayout();
            this.ElevatorGroupBox.SuspendLayout();
            this.SuspendLayout();
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
            // FloorButton5
            // 
            this.FloorButton5.Location = new System.Drawing.Point(6, 302);
            this.FloorButton5.Name = "FloorButton5";
            this.FloorButton5.Size = new System.Drawing.Size(397, 54);
            this.FloorButton5.TabIndex = 5;
            this.FloorButton5.Text = "5";
            this.FloorButton5.UseVisualStyleBackColor = true;
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
            // FloorButton3
            // 
            this.FloorButton3.Location = new System.Drawing.Point(6, 182);
            this.FloorButton3.Name = "FloorButton3";
            this.FloorButton3.Size = new System.Drawing.Size(397, 54);
            this.FloorButton3.TabIndex = 3;
            this.FloorButton3.Text = "3";
            this.FloorButton3.UseVisualStyleBackColor = true;
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
            // FloorButton1
            // 
            this.FloorButton1.Location = new System.Drawing.Point(6, 62);
            this.FloorButton1.Name = "FloorButton1";
            this.FloorButton1.Size = new System.Drawing.Size(397, 54);
            this.FloorButton1.TabIndex = 1;
            this.FloorButton1.Text = "1";
            this.FloorButton1.UseVisualStyleBackColor = true;
            // 
            // ElevaterGroupBox
            // 
            this.ElevatorGroupBox.Controls.Add(this.ElevatorButton1);
            this.ElevatorGroupBox.Controls.Add(this.ElevatorButton2);
            this.ElevatorGroupBox.Controls.Add(this.ElevatorButton3);
            this.ElevatorGroupBox.Controls.Add(this.ElevatorButton4);
            this.ElevatorGroupBox.Controls.Add(this.ElevatorButton5);
            this.ElevatorGroupBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.875F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ElevatorGroupBox.Location = new System.Drawing.Point(427, 12);
            this.ElevatorGroupBox.Name = "ElevaterGroupBox";
            this.ElevatorGroupBox.Size = new System.Drawing.Size(409, 369);
            this.ElevatorGroupBox.TabIndex = 3;
            this.ElevatorGroupBox.TabStop = false;
            this.ElevatorGroupBox.Text = "Кнопки в лифте:";
            // 
            // ElevatorButton1
            // 
            this.ElevatorButton1.Location = new System.Drawing.Point(6, 62);
            this.ElevatorButton1.Name = "ElevatorButton1";
            this.ElevatorButton1.Size = new System.Drawing.Size(397, 54);
            this.ElevatorButton1.TabIndex = 1;
            this.ElevatorButton1.Text = "1";
            this.ElevatorButton1.UseVisualStyleBackColor = true;
            // 
            // ElevatorButton2
            // 
            this.ElevatorButton2.Location = new System.Drawing.Point(6, 122);
            this.ElevatorButton2.Name = "ElevatorButton2";
            this.ElevatorButton2.Size = new System.Drawing.Size(397, 54);
            this.ElevatorButton2.TabIndex = 2;
            this.ElevatorButton2.Text = "2";
            this.ElevatorButton2.UseVisualStyleBackColor = true;
            // 
            // ElevatorButton3
            // 
            this.ElevatorButton3.Location = new System.Drawing.Point(6, 182);
            this.ElevatorButton3.Name = "ElevatorButton3";
            this.ElevatorButton3.Size = new System.Drawing.Size(397, 54);
            this.ElevatorButton3.TabIndex = 3;
            this.ElevatorButton3.Text = "3";
            this.ElevatorButton3.UseVisualStyleBackColor = true;
            // 
            // ElevatorButton4
            // 
            this.ElevatorButton4.Location = new System.Drawing.Point(6, 242);
            this.ElevatorButton4.Name = "ElevatorButton4";
            this.ElevatorButton4.Size = new System.Drawing.Size(397, 54);
            this.ElevatorButton4.TabIndex = 4;
            this.ElevatorButton4.Text = "4";
            this.ElevatorButton4.UseVisualStyleBackColor = true;
            // 
            // ElevatorButtonn5
            // 
            this.ElevatorButton5.Location = new System.Drawing.Point(6, 302);
            this.ElevatorButton5.Name = "ElevatorButton5";
            this.ElevatorButton5.Size = new System.Drawing.Size(397, 54);
            this.ElevatorButton5.TabIndex = 5;
            this.ElevatorButton5.Text = "5";
            this.ElevatorButton5.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(855, 384);
            this.Controls.Add(this.ElevatorGroupBox);
            this.Controls.Add(this.FloorGroupBox);
            this.Name = "Form1";
            this.Text = "ООП л/р 4";
            this.FloorGroupBox.ResumeLayout(false);
            this.ElevatorGroupBox.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox FloorGroupBox;
        private MyButton FloorButton1;
        private MyButton FloorButton2;
        private MyButton FloorButton3;
        private MyButton FloorButton4;
        private MyButton FloorButton5;
        
        private System.Windows.Forms.GroupBox ElevatorGroupBox;
        private MyButton ElevatorButton1;
        private MyButton ElevatorButton2;
        private MyButton ElevatorButton3;
        private MyButton ElevatorButton4;
        private MyButton ElevatorButton5;
    }
}

