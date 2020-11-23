namespace nstu_lab.Game.Types
{
    public enum PlayerSign
    {
        CROSS = Value.CROSS,
        ZERO = Value.ZERO
    }

    public enum Value
    {
        CROSS = 'x',
        ZERO = 'o',
        SHARP = '#'
    }

    public enum GameResult
    {
        PLAYING,
        CROSS,
        ZERO,
        DRAW
    }
}