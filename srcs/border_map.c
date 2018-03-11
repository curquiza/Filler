#include "filler.h"

void	ft_fill_from_top(t_game *game)
{
	int		i;
	int		j;
	int		value;
	int		max_border;

	max_border = ft_max(game->h_map, game->w_map);
	i = 0;
	value = max_border;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
			game->strat_map[i][j].border += value;
			j++;
		}
		i++;
		value--;
	}
}

void	ft_fill_from_left(t_game *game)
{
	int		i;
	int		j;
	int		value;
	int		max_border;

	max_border = ft_max(game->h_map, game->w_map);
	j = 0;
	value = max_border;
	while (j < game->w_map)
	{
		i = 0;
		while (i < game->h_map)
		{
			game->strat_map[i][j].border += value;
			i++;
		}
		j++;
		value--;
	}
}

void	ft_calc_border_weight(t_game *game)
{
  if (game->my_coin == 'x')
		ft_fill_from_top(game);
}
