#include "filler.h"

void ft_opposite_borders(t_game *game) // TEMPORAIRE !!!
{
	if (game->my_coin == 'o')
	{
		game->border.bottom = 1;
		game->border.right = 1;
	}
	else
	{
		game->border.top = 1;
		game->border.left = 1;
	}
}

void ft_calc_border_weight(t_game *game)
{
  (void)game;
}
