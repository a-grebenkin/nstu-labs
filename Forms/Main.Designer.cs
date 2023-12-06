namespace nstu_lab.Forms
{
    partial class Main
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
            this.menu = new System.Windows.Forms.MenuStrip();
            this.load = new System.Windows.Forms.ToolStripMenuItem();
            this.save = new System.Windows.Forms.ToolStripMenuItem();
            this.retry = new System.Windows.Forms.ToolStripMenuItem();
            this.status = new System.Windows.Forms.StatusStrip();
            this.turn = new System.Windows.Forms.ToolStripStatusLabel();
            this.player = new System.Windows.Forms.ToolStripStatusLabel();
            this.button00 = new System.Windows.Forms.Button();
            this.button01 = new System.Windows.Forms.Button();
            this.button02 = new System.Windows.Forms.Button();
            this.button10 = new System.Windows.Forms.Button();
            this.button11 = new System.Windows.Forms.Button();
            this.button12 = new System.Windows.Forms.Button();
            this.button20 = new System.Windows.Forms.Button();
            this.button21 = new System.Windows.Forms.Button();
            this.button22 = new System.Windows.Forms.Button();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.menu.SuspendLayout();
            this.status.SuspendLayout();
            this.SuspendLayout();
            // 
            // menu
            // 
            this.menu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.load,
            this.save,
            this.retry});
            this.menu.Location = new System.Drawing.Point(0, 0);
            this.menu.Name = "menu";
            this.menu.Size = new System.Drawing.Size(291, 24);
            this.menu.TabIndex = 0;
            this.menu.Text = "menu";
            // 
            // load
            // 
            this.load.Name = "load";
            this.load.Size = new System.Drawing.Size(66, 20);
            this.load.Text = "Открыть";
            // 
            // save
            // 
            this.save.Name = "save";
            this.save.Size = new System.Drawing.Size(78, 20);
            this.save.Text = "Сохранить";
            // 
            // retry
            // 
            this.retry.Name = "retry";
            this.retry.Size = new System.Drawing.Size(59, 20);
            this.retry.Text = "Заново";
            // 
            // status
            // 
            this.status.AllowMerge = false;
            this.status.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.turn,
            this.player});
            this.status.Location = new System.Drawing.Point(0, 283);
            this.status.Name = "status";
            this.status.Size = new System.Drawing.Size(291, 22);
            this.status.TabIndex = 1;
            this.status.Text = "statusStrip1";
            // 
            // turn
            // 
            this.turn.Name = "turn";
            this.turn.Size = new System.Drawing.Size(39, 17);
            this.turn.Text = "Ход: 0";
            // 
            // player
            // 
            this.player.Name = "player";
            this.player.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.player.Size = new System.Drawing.Size(44, 17);
            this.player.Text = "Игрок:";
            // 
            // button00
            // 
            this.button00.Font = new System.Drawing.Font("Segoe UI", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button00.Location = new System.Drawing.Point(12, 27);
            this.button00.Name = "button00";
            this.button00.Size = new System.Drawing.Size(85, 77);
            this.button00.TabIndex = 0;
            this.button00.UseVisualStyleBackColor = true;
            this.button00.Click += new System.EventHandler(this.FieldClick);
            // 
            // button01
            // 
            this.button01.Font = new System.Drawing.Font("Segoe UI", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button01.Location = new System.Drawing.Point(103, 27);
            this.button01.Name = "button01";
            this.button01.Size = new System.Drawing.Size(85, 77);
            this.button01.TabIndex = 1;
            this.button01.UseVisualStyleBackColor = true;
            this.button01.Click += new System.EventHandler(this.FieldClick);
            // 
            // button02
            // 
            this.button02.Font = new System.Drawing.Font("Segoe UI", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button02.Location = new System.Drawing.Point(194, 27);
            this.button02.Name = "button02";
            this.button02.Size = new System.Drawing.Size(85, 77);
            this.button02.TabIndex = 2;
            this.button02.UseVisualStyleBackColor = true;
            this.button02.Click += new System.EventHandler(this.FieldClick);
            // 
            // button10
            // 
            this.button10.Font = new System.Drawing.Font("Segoe UI", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button10.Location = new System.Drawing.Point(12, 110);
            this.button10.Name = "button10";
            this.button10.Size = new System.Drawing.Size(85, 77);
            this.button10.TabIndex = 3;
            this.button10.UseVisualStyleBackColor = true;
            this.button10.Click += new System.EventHandler(this.FieldClick);
            // 
            // button11
            // 
            this.button11.Font = new System.Drawing.Font("Segoe UI", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button11.Location = new System.Drawing.Point(103, 110);
            this.button11.Name = "button11";
            this.button11.Size = new System.Drawing.Size(85, 77);
            this.button11.TabIndex = 4;
            this.button11.UseVisualStyleBackColor = true;
            this.button11.Click += new System.EventHandler(this.FieldClick);
            // 
            // button12
            // 
            this.button12.Font = new System.Drawing.Font("Segoe UI", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button12.Location = new System.Drawing.Point(194, 110);
            this.button12.Name = "button12";
            this.button12.Size = new System.Drawing.Size(85, 77);
            this.button12.TabIndex = 5;
            this.button12.UseVisualStyleBackColor = true;
            this.button12.Click += new System.EventHandler(this.FieldClick);
            // 
            // button20
            // 
            this.button20.Font = new System.Drawing.Font("Segoe UI", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button20.Location = new System.Drawing.Point(12, 193);
            this.button20.Name = "button20";
            this.button20.Size = new System.Drawing.Size(85, 77);
            this.button20.TabIndex = 6;
            this.button20.UseVisualStyleBackColor = true;
            this.button20.Click += new System.EventHandler(this.FieldClick);
            // 
            // button21
            // 
            this.button21.Font = new System.Drawing.Font("Segoe UI", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button21.Location = new System.Drawing.Point(103, 193);
            this.button21.Name = "button21";
            this.button21.Size = new System.Drawing.Size(85, 77);
            this.button21.TabIndex = 7;
            this.button21.UseVisualStyleBackColor = true;
            this.button21.Click += new System.EventHandler(this.FieldClick);
            // 
            // button22
            // 
            this.button22.Font = new System.Drawing.Font("Segoe UI", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button22.Location = new System.Drawing.Point(194, 193);
            this.button22.Name = "button22";
            this.button22.Size = new System.Drawing.Size(85, 77);
            this.button22.TabIndex = 8;
            this.button22.UseVisualStyleBackColor = true;
            this.button22.Click += new System.EventHandler(this.FieldClick);
            // 
            // openFileDialog
            // 
            this.openFileDialog.DefaultExt = "txt";
            this.openFileDialog.Filter = "Текстовый файл|*.txt";
            this.openFileDialog.Title = "Загрузить игру";
            // 
            // saveFileDialog
            // 
            this.saveFileDialog.DefaultExt = "txt";
            this.saveFileDialog.Filter = "Текстовый файл|*.txt";
            this.saveFileDialog.Title = "Сохранить игру";
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(291, 305);
            this.Controls.Add(this.button22);
            this.Controls.Add(this.button21);
            this.Controls.Add(this.button20);
            this.Controls.Add(this.button12);
            this.Controls.Add(this.button11);
            this.Controls.Add(this.button10);
            this.Controls.Add(this.button02);
            this.Controls.Add(this.button01);
            this.Controls.Add(this.button00);
            this.Controls.Add(this.status);
            this.Controls.Add(this.menu);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menu;
            this.MaximizeBox = false;
            this.Name = "Main";
            this.Text = "Крестики-нолики";
            this.Shown += new System.EventHandler(this.FormShow);
            this.menu.ResumeLayout(false);
            this.menu.PerformLayout();
            this.status.ResumeLayout(false);
            this.status.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menu;
        private System.Windows.Forms.ToolStripMenuItem load;
        private System.Windows.Forms.ToolStripMenuItem save;
        private System.Windows.Forms.StatusStrip status;
        private System.Windows.Forms.ToolStripStatusLabel turn;
        private System.Windows.Forms.ToolStripStatusLabel player;
        private System.Windows.Forms.Button button00;
        private System.Windows.Forms.Button button01;
        private System.Windows.Forms.Button button02;
        private System.Windows.Forms.Button button10;
        private System.Windows.Forms.Button button11;
        private System.Windows.Forms.Button button12;
        private System.Windows.Forms.Button button20;
        private System.Windows.Forms.Button button21;
        private System.Windows.Forms.Button button22;
        private System.Windows.Forms.ToolStripMenuItem retry;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
    }
}