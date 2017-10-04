#include "filler.h"

int		ft_is_opp(t_game *game, char value)
{
	if (value == game->opp_coin || value == game->opp_coin - 32)
		return (1);
	return (0);
}

int		ft_is_empty(char value)
{
	if (value == '.')
		return (1);
	return (0);
}

static void	ft_init_heat_map(t_game *game, t_heat_map ***heat_map)
{
	int		i;

	*heat_map = ft_memalloc(sizeof(**heat_map) * game->h_map);
	i = 0;
	while (i < game->h_map)
	{
		(*heat_map)[i] = ft_memalloc(sizeof(***heat_map) * game->w_map);
		i++;
	}
}

void	ft_go_down(t_game *game, t_heat_map **map)
{
	int		i;
	int		j;
	int		w;

	w = game->h_map;
	j = 0;
	while (j < game->w_map)
	{
		i = 0;
		w = game->h_map;
		while (i < game->h_map)
		{
			if (i != 0
				&& ft_is_empty(game->strat_map[i][j].value)
				&& ft_is_opp(game, game->strat_map[i - 1][j].value))
				map[i][j].down = w;
			w--;
			if (ft_is_opp(game, game->strat_map[i][j].value))
				w = game->h_map;
			i++;
		}
		j++;
	}
}

void	ft_calculate_heat_weight(t_game *game)
{
	t_heat_map **heat;

	ft_init_heat_map(game, &heat);
	ft_go_down(game, heat);
}

int		ft_put_piece(t_game *game)
{
	ft_calculate_heat_weight(game);
	return (0);
}
