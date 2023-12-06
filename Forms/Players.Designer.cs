namespace nstu_lab.Forms
{
    partial class Players
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.crossName = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.crossType = new System.Windows.Forms.ComboBox();
            this.zeroType = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.zeroName = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.okButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(58, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "Крестики";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(13, 32);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(31, 15);
            this.label3.TabIndex = 1;
            this.label3.Text = "Имя";
            // 
            // crossName
            // 
            this.crossName.Location = new System.Drawing.Point(13, 51);
            this.crossName.Name = "crossName";
            this.crossName.Size = new System.Drawing.Size(195, 23);
            this.crossName.TabIndex = 0;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(13, 81);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(103, 15);
            this.label4.TabIndex = 3;
            this.label4.Text = "Кто будет играть?";
            // 
            // crossType
            // 
            this.crossType.FormattingEnabled = true;
            this.crossType.Items.AddRange(new object[] {
            "Человек",
            "Глупый бот",
            "Умный бот"});
            this.crossType.Location = new System.Drawing.Point(13, 100);
            this.crossType.Name = "crossType";
            this.crossType.Size = new System.Drawing.Size(195, 23);
            this.crossType.TabIndex = 1;
            // 
            // zeroType
            // 
            this.zeroType.DisplayMember = "0";
            this.zeroType.FormattingEnabled = true;
            this.zeroType.Items.AddRange(new object[] {
            "Человек",
            "Глупый бот",
            "Умный бот"});
            this.zeroType.Location = new System.Drawing.Point(240, 100);
            this.zeroType.Name = "zeroType";
            this.zeroType.Size = new System.Drawing.Size(195, 23);
            this.zeroType.TabIndex = 3;
            this.zeroType.ValueMember = "0";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(240, 81);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(103, 15);
            this.label2.TabIndex = 3;
            this.label2.Text = "Кто будет играть?";
            // 
            // zeroName
            // 
            this.zeroName.Location = new System.Drawing.Point(240, 51);
            this.zeroName.Name = "zeroName";
            this.zeroName.Size = new System.Drawing.Size(195, 23);
            this.zeroName.TabIndex = 2;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(240, 32);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(31, 15);
            this.label5.TabIndex = 1;
            this.label5.Text = "Имя";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(240, 13);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(50, 15);
            this.label6.TabIndex = 0;
            this.label6.Text = "Нолики";
            // 
            // okButton
            // 
            this.okButton.Location = new System.Drawing.Point(359, 138);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(75, 23);
            this.okButton.TabIndex = 5;
            this.okButton.Text = "ОК";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // Players
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(446, 173);
            this.Controls.Add(this.okButton);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.zeroName);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.zeroType);
            this.Controls.Add(this.crossType);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.crossName);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Players";
            this.ShowInTaskbar = false;
            this.Text = "Players";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox crossName;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox crossType;
        private System.Windows.Forms.ComboBox zeroType;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox zeroName;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button okButton;
    }
}