#include "filler.h"

int		ft_is_me(t_game game, char value)
{
	if (value == game.my_coin || value == game.my_coin - 32)
		return (1);
	return (0);
}

int		ft_is_opp(t_game game, char value)
{
	if (value == game.opp_coin || value == game.opp_coin - 32)
		return (1);
	return (0);
}

int		ft_is_empty(char value)
{
	if (value == '.')
		return (1);
	return (0);
}

int   ft_is_top_player(t_game game)
{
  if (game.player_position == 1)
    return (1);
  return (0);
}