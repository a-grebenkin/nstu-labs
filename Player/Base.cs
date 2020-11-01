using nstu_lab.Game;

namespace nstu_lab.Player
{
    abstract class BasePlayer
    {
        private string _name;

        public BasePlayer(string name)
        {
            _name = name;
        }

        public string Name => _name;

        public abstract void DoStep(ref int x, ref int y, ref Game.Game game);
    }
}