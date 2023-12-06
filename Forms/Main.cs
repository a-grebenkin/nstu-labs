using System;
using System.Windows.Forms;
using nstu_lab.Player;
using nstu_lab.Game.Types;

namespace nstu_lab.Forms
{
    public partial class Main : Form
    {
        private readonly Game.Game game = new Game.Game();
        private readonly BasePlayer[] players = new BasePlayer[2];
        private int turnCounter = 1;
        private int playerIndex = 0;
        private readonly bool[] humanPlayers = new bool[2];
        private readonly Button[,] field;

        public Main()
        {
            InitializeComponent();
            this.field = new Button[3,3] { {this.button00, this.button01,this.button02 }, { this.button10, this.button11, this.button12}, { this.button20, this.button21, this.button22, } };
            this.retry.Click += this.ClearTable;
            this.load.Click += this.LoadTable;
            this.save.Click += this.SaveFile;
        }

        private void FormShow(object sender, EventArgs e)
        {
            using (var form = new Players())
            {
                if (form.ShowDialog() != DialogResult.OK)
                {
                    this.Close();
                    return;
                }

                players[0] = form.CrossPlayer;
                players[1] = form.ZeroPlayer;
                humanPlayers[0] = form.HumanPlayers[0];
                humanPlayers[1] = form.HumanPlayers[1];
            }

            BotHandler();
        }

        private void UpdateStatus()
        {
            this.turn.Text = $"Ход: {turnCounter}";
            this.player.Text = $"Игрок: {players[playerIndex].Name}";
        }

        private void BotHandler()
        {
            if (humanPlayers[this.playerIndex] || game.IsEndOfGame)
            {
                return;
            }

            int x = 0, y = 0;
            this.players[this.playerIndex].DoStep(ref x, ref y, game);
            this.field[x, y].PerformClick();
        }

        private void FieldClick(object sender, EventArgs e)
        {
            if (game.IsEndOfGame)
            {
                MessageBox.Show("Игра уже закончена!");
                return;
            }

            string name = sender.GetType().GetProperty("Name").GetValue(sender).ToString();
            int[] coordinates = new int[2] { Convert.ToInt32(name[name.Length - 2].ToString()), Convert.ToInt32(name[name.Length - 1].ToString()) };

            PlayerSign sign = playerIndex == 0 ? PlayerSign.CROSS : PlayerSign.ZERO;
            this.game.MakeStep(coordinates[0], coordinates[1], sign);

            sender.GetType().GetProperty("Enabled").SetValue(sender, false);
            sender.GetType().GetProperty("Text").SetValue(sender, ((char)sign).ToString().ToUpper());

            this.UpdateStatus();
            
            switch (this.game.Result)
            {
                case GameResult.PLAYING:
                    this.turnCounter++;
                    this.playerIndex = (this.playerIndex + 1) % 2;
                    this.BotHandler();
                    break;
                case GameResult.CROSS:
                    MessageBox.Show($"Победили крестики! ({players[0].Name})", "Исход игры");
                    break;
                case GameResult.ZERO:
                    MessageBox.Show($"Победили нолики! ({players[1].Name})", "Исход игры");
                    break;
                case GameResult.DRAW:
                    MessageBox.Show("Ничья!", "Исход игры");
                    break;
            }
        }

        private void ClearTable(object sender, EventArgs e)
        {
            this.playerIndex = 0;
            this.turnCounter = 1;
            this.game.Clear();

            foreach (var button in field)
            {
                button.Enabled = true;
                button.Text = "";
            }

            UpdateStatus();
            BotHandler();
        }

        private void LoadTable(object sender, EventArgs e)
        {
            if (this.openFileDialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            using var reader = this.openFileDialog.OpenFile();
            this.game.Load(reader);

            int counterCross = 0, counterZero = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    this.field[i, j].Enabled = this.game.Board[i, j] == Value.SHARP ? true : false;
                    this.field[i, j].Text = this.game.Board[i, j] == Value.SHARP ? "" : ((char)this.game.Board[i, j]).ToString().ToUpper();

                    if (this.game.Board[i, j] == Value.CROSS)
                    {
                        counterCross++;
                    } 
                    else if (this.game.Board[i, j] == Value.ZERO) 
                    {
                        counterZero++;
                    }
                }
            }

            this.turnCounter = counterZero + counterCross + 1;
            this.playerIndex = counterZero == counterCross ? 0 : 1;

            this.UpdateStatus();

            switch (this.game.Result)
            {
                case GameResult.PLAYING:
                    this.BotHandler();
                    break;
                case GameResult.CROSS:
                    MessageBox.Show($"Победили крестики! ({players[0].Name})");
                    break;
                case GameResult.ZERO:
                    MessageBox.Show($"Победили нолики! ({players[1].Name})");
                    break;
                case GameResult.DRAW:
                    MessageBox.Show("Ничья!");
                    break;
            }
        }
    
        private void SaveFile(object sender, EventArgs e)
        {
            if (this.saveFileDialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            using var reader = this.saveFileDialog.OpenFile();
            this.game.Save(reader);

            MessageBox.Show("Игра сохранена!", "Сохранение");
        }
    }
}
