using System;
using System.IO;
using System.Text;
using nstu_lab.Game.Types;

namespace nstu_lab.Game
{
    public class Game
    {
        private Value[,] _board = new Value[3, 3];

        public Game()
        {
            this.Clear();
        }

        public GameResult Result { get
            {
                for (int i = 0; i < 3; i++)
                {
                    //если хоть один игрок заполнил строку крестиками или ноликами
                    if ((Board[i, 0] == Board[i, 1]) && (Board[i, 0] == Board[i, 2]) && (Board[i, 0] != Value.SHARP))
                    {
                        if (Board[i, 0] == Value.CROSS)
                        {
                            return GameResult.CROSS;
                        }
                        else
                        {
                            return GameResult.ZERO;
                        }
                    }
                    //если хоть один игрок заполнил столбец крестиками или ноликами

                    if ((Board[0, i] == Board[1, i]) && (Board[0, i] == Board[2, i]) && (Board[0, i] != Value.SHARP))

                    {

                        if (Board[0, i] == Value.CROSS)
                        {
                            return GameResult.CROSS;
                        }
                        else
                        {
                            return GameResult.ZERO;
                        }
                    }
                }

                //если заполнена главная диагональ

                if ((Board[0, 0] == Board[1, 1]) && (Board[0, 0] == Board[2, 2]) && (Board[0, 0] != Value.SHARP))

                {
                    if (Board[0, 0] == Value.CROSS)
                    {
                        return GameResult.CROSS;
                    }
                    else
                    {
                        return GameResult.ZERO;
                    }

                }

                //если заполнена побочная диагональ

                if ((Board[0, 2] == Board[1, 1]) && (Board[0, 2] == Board[2, 0]) && (Board[0, 2] != Value.SHARP))

                {

                    if (Board[0, 2] == Value.CROSS)
                    {
                        return GameResult.CROSS;
                    }
                    else
                    {
                        return GameResult.ZERO;
                    }
                }

                //если заполнены все ячейки, но никто не победил

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (Board[i, j] == Value.SHARP)
                        {
                            return GameResult.PLAYING;
                        }
                    }
                }

                return GameResult.DRAW;
            } }

        public void ShowBoard()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Console.Write((char)Board[i, j]);
                }
                Console.Write('\n');
            }
        }

        public void Clear()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    _board[i, j] = Value.SHARP;
                }
            }
        }

        public bool MakeStep(int x, int y, PlayerSign val)
        {
            if (_board[x, y] == Value.SHARP)
            {
                _board[x, y] = (Value)val;
                return true;
            }

            return false;
        }

        public bool IsBoardFilled
        {
            get
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (_board[i, j] != Value.SHARP)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
        }

        public Value[,] Board => _board;

        public bool IsEndOfGame
        {
            get
            {
                return this.Result != GameResult.PLAYING;
            }
        }

        public void Load(Stream reader)
        {
            byte[] array = new byte[9];
            reader.Read(array);
            string field = System.Text.Encoding.Default.GetString(array);

            try
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        _board[i, j] = (Value)field[(i * 3) + j];
                    }
                }
            }
            catch (Exception)
            {
                throw new ArgumentException("invalid stream");
            }
        }

        public void Save(Stream writer)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    writer.Write(Encoding.Default.GetBytes(((char)Board[i, j]).ToString()));
                }

            }
        }
    }
}