using System;
using System.IO;
using nstu_lab.Game.Types;
using nstu_lab.Player;


namespace nstu_lab
{
    class Program
    {
        static int[] EnterCheckNumber(int min, int max)
        {
            int[] number = new int[2];
            string str;
            string[] numbers;
            while (true)
            {
                str = Console.ReadLine();

                numbers = str.Split(',');
                if (numbers.Length == 2)
                {
                    if (Convert.ToInt32(numbers[0]) <= max && Convert.ToInt32(numbers[0]) >= min && Convert.ToInt32(numbers[1]) <= max && Convert.ToInt32(numbers[1]) >= min)
                    {
                        break;
                    }
                }

                Console.WriteLine("Пара чисел введена неверно!");
            }

            number[0] = Convert.ToInt32(numbers[0]);
            number[1] = Convert.ToInt32(numbers[1]);


            return number;
        }

        static void Main(string[] args)
        {
            int count = 0;

            Console.WriteLine("Добро пожаловать в игру крестики нолики!\nВведите имя первого игрока (Нолики, игрок со случайными ходами):");
            string name = Console.ReadLine();
            RandomPlayer randomPlayer = new RandomPlayer(name);

            Console.WriteLine("Введите имя второго игрока (Крестики, думайющий игрок):");
            name = Console.ReadLine();
            SmartPlayer smartPlayer = new SmartPlayer(name);

            Console.WriteLine("\n == Начало игры! ==");

            Game.Game game = new Game.Game();
            while (!game.IsEndOfGame)
            {
                Console.WriteLine("Хотите взять управление ходом крестики? (yes/no)");
                string action = Console.ReadLine();
                count++;

                switch (action)
                {
                    case "yes":
                        Console.WriteLine("Введите два значения (x, y; от 0 до 2):");
                        int[] numbers = EnterCheckNumber(0, 2);
                        game.MakeStep(numbers[0], numbers[1], PlayerSign.CROSS);
                        Console.WriteLine($"Ход №{count} (крестики, {smartPlayer.Name})");
                        game.ShowBoard();
                        Console.WriteLine();
                        break;
                    default:
                        if (action != "no")
                        {
                            Console.WriteLine("Ничего не понял, воспринимаю как \"no\".");
                        }
                        int x = 0, y = 0;
                        smartPlayer.DoStep(ref x, ref y, ref game);
                        game.MakeStep(x, y, PlayerSign.CROSS);
                        Console.WriteLine($"Ход №{count} (крестики, {smartPlayer.Name})");
                        game.ShowBoard();
                        Console.WriteLine();
                        break;
                }

                if (game.IsEndOfGame)
                {
                    break;
                }

                Console.WriteLine("Хотите взять управление ходом ноликами? (yes/no)");
                action = Console.ReadLine();
                count++;

                switch (action)
                {
                    case "yes":
                        Console.WriteLine("Введите два значения (x, y; от 0 до 2):");
                        int[] numbers = EnterCheckNumber(0, 2);
                        game.MakeStep(numbers[0], numbers[1], PlayerSign.ZERO);
                        Console.WriteLine($"Ход №{count} (крестики, {smartPlayer.Name})");
                        game.ShowBoard();
                        Console.WriteLine();
                        break;
                    default:
                        if (action != "no")
                        {
                            Console.WriteLine("Ничего не понял, воспринимаю как \"no\".");
                        }
                        int x = 0, y = 0;
                        randomPlayer.DoStep(ref x, ref y, ref game);
                        game.MakeStep(x, y, PlayerSign.ZERO);
                        Console.WriteLine($"Ход №{count} (крестики, {smartPlayer.Name})");
                        game.ShowBoard();
                        Console.WriteLine();
                        break;
                }
            }

            using (var fWriter = new StreamWriter("last_game.txt"))
            {
                Console.WriteLine("Записываю игру в файл \"last_game.txt\"");
                game.Save(fWriter);
            }
        }
    }
}
