using System;
using System.IO;
using nstu_lab.Game.Types;

namespace nstu_lab.Game
{
    class Game
    {
        private Value[,] _board = new Value[3, 3];

        public Game()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    _board[i, j] = Value.SHARP;
                }
            }
        }

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
                for (int i = 0; i < 3; i++)
                {
                    //если хоть один игрок заполнил строку крестиками или ноликами
                    if ((Board[i, 0] == Board[i, 1]) && (Board[i, 0] == Board[i, 2]) && (Board[i, 0] != Value.SHARP))
                    {
                        if (Board[i, 0] == Value.CROSS)
                        {
                            Console.WriteLine("Победили крестики!");
                        }
                        else
                        {
                            Console.WriteLine("Победили нолики!");
                        }
                        return true;
                    }
                    //если хоть один игрок заполнил столбец крестиками или ноликами

                    if ((Board[0, i] == Board[1, i]) && (Board[0, i] == Board[2, i]) && (Board[0, i] != Value.SHARP))

                    {

                        if (Board[0, i] == Value.CROSS)
                        {
                            Console.WriteLine("Победили крестики!");
                        }
                        else
                        {
                            Console.WriteLine("Победили нолики!");
                        }
                        return true;
                    }
                }

                //если заполнена главная диагональ

                if ((Board[0, 0] == Board[1, 1]) && (Board[0, 0] == Board[2, 2]) && (Board[0, 0] != Value.SHARP))

                {
                    if (Board[0, 0] == Value.CROSS)
                    {
                        Console.WriteLine("Победили крестики!");
                    }
                    else
                    {
                        Console.WriteLine("Победили нолики!");
                    }
                    return true;

                }

                //если заполнена побочная диагональ

                if ((Board[0, 2] == Board[1, 1]) && (Board[0, 2] == Board[2, 0]) && (Board[0, 2] != Value.SHARP))

                {

                    if (Board[0, 2] == Value.CROSS)
                    {
                        Console.WriteLine("Победили крестики!");
                    }
                    else
                    {
                        Console.WriteLine("Победили нолики!");
                    }
                    return true;
                }

                //если заполнены все ячейки, но никто не победил

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (Board[i, j] == Value.SHARP)
                        {
                            return false;
                        }
                    }
                }
                Console.WriteLine("Ничья!");

                return true;
            }
        }

        public void Load(StreamReader reader)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int letter = reader.Read();

                    if (letter == -1)
                    {
                        throw new ArgumentOutOfRangeException("invalid stream to read");
                    }

                    _board[i, j] = (Value)letter;
                }

            }
        }

        public void Save(StreamWriter writer)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    writer.Write((char)Board[i, j]);
                }

            }
        }
    }
}