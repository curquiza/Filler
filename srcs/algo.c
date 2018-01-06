#include "filler.h"

void	ft_calc_heat_weight(t_game *game)
{
	ft_first_heat_calc(game);
	ft_fill_heat_1(game);
	ft_fill_heat_2(game);
}

void	ft_get_place(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
			j++;
		}
		i++;
	}
}


int		ft_find_placement(t_game *game, int round)
{
	ft_calc_heat_weight(game);
	ft_put_stratmap(*game, round);
	ft_get_place(game);
	if (game->pos_x == -1)
		return (-1);
	return (0);
}
