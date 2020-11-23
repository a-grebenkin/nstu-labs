using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using nstu_lab.Player;

namespace nstu_lab.Forms
{
    public partial class Players : Form
    {
        public BasePlayer CrossPlayer { get; private set; }
        public BasePlayer ZeroPlayer { get; private set; }
        public bool[] HumanPlayers { get; private set; }

        public Players()
        {
            InitializeComponent();
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            if (this.crossName.Text.Length == 0 || this.crossType.SelectedIndex == -1)
            {
                MessageBox.Show("Пожалуйста, заполните все поля у крестика!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            if (this.zeroName.Text.Length == 0 || this.zeroType.SelectedIndex == -1)
            {
                MessageBox.Show("Пожалуйста, заполните все поля у нолика!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            this.HumanPlayers = new bool[2] { false, false };
            switch (this.crossType.SelectedIndex)
            {
                case 0:
                    CrossPlayer = new SmartPlayer(this.crossName.Text);
                    this.HumanPlayers[0] = true;
                    break;
                case 1:
                    CrossPlayer = new RandomPlayer(this.crossName.Text);
                    break;
                case 2:
                    CrossPlayer = new SmartPlayer(this.crossName.Text);
                    break;
            }

            switch (this.zeroType.SelectedIndex)
            {
                case 0:
                    ZeroPlayer = new SmartPlayer(this.zeroName.Text);
                    this.HumanPlayers[1] = true;
                    break;
                case 1:
                    ZeroPlayer = new RandomPlayer(this.zeroName.Text);
                    break;
                case 2:
                    ZeroPlayer = new SmartPlayer(this.zeroName.Text);
                    break;
            }

            this.DialogResult = DialogResult.OK;
        }
    }
}
