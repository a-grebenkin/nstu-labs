using System;
using nstu_lab.Game.Types;

namespace nstu_lab.Player
{
    class RandomPlayer : BasePlayer
    {
        public RandomPlayer(string name) : base(name) { }

        public override void DoStep(ref int x, ref int y, Game.Game game)
        {
            Random rnd = new Random();

            do
            {
                int i = rnd.Next(3), j = rnd.Next(3);
                if (game.Board[i, j] == Value.SHARP)
                {
                    x = i;
                    y = j;
                    break;
                }
            } while (true);
        }
    }
}