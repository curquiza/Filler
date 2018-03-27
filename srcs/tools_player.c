#include "filler.h"

int		ft_is_me(t_game game, char value)
{
	return (value == game.my_coin || value == game.my_coin - 32);
}

int		ft_is_opp(t_game game, char value)
{
	return (value == game.opp_coin || value == game.opp_coin - 32);
}

int		ft_is_empty(char value)
{
	return (value == '.');
}

int		ft_is_top_player(t_game game)
{
	return (game.player_position == 1);
}