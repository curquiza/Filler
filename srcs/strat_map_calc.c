#include "filler.h"

static void	ft_calc_global_weight(t_map *point, t_game game)
{
	int		max_heat;
	int		max_border;

	max_heat = ft_max(game.h_map, game.w_map) * 4;
	max_border = ft_max(game.h_map, game.w_map);
	point->weight = (game.coef_heat * point->heat / max_heat
					+ game.coef_border * point->border / max_border)
					* 100;
}

static void	ft_init_coef(t_game *game)
{
	if (ft_is_top_player(*game))
		ft_desactivate_border(game);
	else
	{
		game->border.top = 1;
		ft_activate_border(game);
		ft_border_weight_from_top(game);
	}
}

static void	ft_get_position(t_game *game)
{
	char	*tmp;

	tmp = game->gross_map;
	while (*tmp)
	{
		if (ft_is_me(*game, *tmp))
		{
			game->player_position = 1;
			break;
		}
		if (ft_is_opp(*game, *tmp))
		{
			game->player_position = -1;
			break;
		}
		tmp++;
	}
}

void		ft_strat_map_calc(t_game *game)
{
	int		i;
	int		j;

	if (!game->player_position)
	{
		ft_get_position(game);
		ft_init_coef(game);
	}
	if (ft_heat_is_activate(*game))
		ft_calc_heat_weight(game);
	i = 0;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
			if (!ft_is_opp(*game, game->strat_map[i][j].value))
				ft_calc_global_weight(&game->strat_map[i][j], *game);
			j++;
		}
		i++;
	}
}
