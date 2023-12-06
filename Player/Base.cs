using nstu_lab.Game;

namespace nstu_lab.Player
{
    public abstract class BasePlayer
    {
        private string _name;

        public BasePlayer(string name)
        {
            _name = name;
        }

        public string Name => _name;

        public abstract void DoStep(ref int x, ref int y, Game.Game game);
    }
}