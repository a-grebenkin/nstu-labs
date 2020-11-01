using System;
using nstu_lab.Game.Types;

namespace nstu_lab.Player
{
    class SmartPlayer : BasePlayer
    {
        public SmartPlayer(string name) : base(name) { }

        public override void DoStep(ref int x, ref int y, ref Game.Game game)
        {
            int count = 0;

            //подсчитываем количество крестиков в каждой строке
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (game.Board[i, j] == Value.CROSS)
                    {
                        count++;
                    }
                }
                //если встречено два крестика
                if (count == 2)
                {

                    for (int j = 0; j < 3; j++)
                    {
                        if (game.Board[i, j] == Value.SHARP)
                        {
                            x = i;
                            y = j;
                            return;
                        }
                    }

                }
                count = 0;
            }

            for (int j = 0; j < 3; j++)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (game.Board[i, j] == Value.CROSS)
                    {
                        count++;
                    }
                }

                //если встречено два крестика
                if (count == 2)
                {

                    for (int i = 0; i < 3; i++)
                    {
                        if (game.Board[i, j] == Value.SHARP)
                        {
                            x = i;
                            y = j;
                            return;
                        }
                    }

                }
                count = 0;
            }

            for (int i = 0; i < 3; i++)
            {
                int j = i;
                if (game.Board[i, j] == Value.CROSS)
                {
                    count++;
                }
            }
            //если встречено два крестика
            if (count == 2)
            {

                for (int i = 0; i < 3; i++)
                {
                    int j = i;
                    if (game.Board[i, j] == Value.SHARP)
                    {
                        x = i;
                        y = j;
                        return;
                    }
                }

            }
            count = 0;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 2; j > 0; j--)
                {
                    if (game.Board[i, j] == Value.CROSS)
                    {
                        count++;
                    }
                }


                if (count == 2)
                {

                    for (int k = 0; k < 3; k++)
                    {
                        for (int j = 2; j > 0; j--)
                        {
                            if (game.Board[k, j] == Value.SHARP)
                            {
                                x = i;
                                y = j;
                                return;
                            }
                        }
                    }

                }
                count = 0;
            }
            Random rnd = new Random();
            if (count == 0)
            {
                do
                {
                    x = rnd.Next(3);
                    y = rnd.Next(3);
                    if (game.Board[x, y] == Value.SHARP)
                    {
                        break;
                    }
                }
                while (true);
            }
        }
    }
}