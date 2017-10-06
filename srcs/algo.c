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

int		ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

static void	ft_init_heat_map(t_game *game, t_heat_map ***map)
{
	int		i;

	*map = ft_memalloc(sizeof(**map) * game->h_map);
	i = 0;
	while (i < game->h_map)
	{
		(*map)[i] = ft_memalloc(sizeof(***map) * game->w_map);
		i++;
	}
}

int		ft_get_sides(t_game *game, t_heat_map **map, int i, int j)
{
	if (i != 0 && ft_is_opp(game, game->strat_map[i - 1][j].value))
		map[i][j].side++;
	if (j != 0 && ft_is_opp(game, game->strat_map[i][j + 1].value))
		map[i][j].side++;
	if (i != game->h_map - 1
		&& ft_is_opp(game, game->strat_map[i + 1][j].value))
		map[i][j].side++;
	if (j != game->w_map - 1
		&& ft_is_opp(game, game->strat_map[i][j + 1].value))
		map[i][j].side++;
	return (map[i][j].side != 0 ? 1 : 0);
}

void	ft_get_diag(t_game *game, t_heat_map **map, int i, int j)
{
	if (i != 0 && j != 0
		&& ft_is_opp(game, game->strat_map[i - 1][j - 1].value))
		map[i][j].diag++;
	if (i != 0 && j != game->w_map - 1
		&& ft_is_opp(game, game->strat_map[i - 1][j + 1].value))
		map[i][j].diag++;
	if (i != game->h_map - 1 && j != 0
		&& ft_is_opp(game, game->strat_map[i + 1][j - 1].value))
		map[i][j].diag++;
	if (i != game->h_map - 1 && j != game->w_map
		&& ft_is_opp(game, game->strat_map[i + 1][j + 1].value))
		map[i][j].diag++;
}

void	ft_first_calc(t_game *game, t_heat_map **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
			if (ft_is_empty(game->strat_map[i][j].value)
				&& map[i][j].heat == 0)
			{
				if (ft_get_sides(game, map, i, j) == 1)
					map[i][j].heat = ft_min(game->h_map, game->w_map);
				ft_get_diag(game, map, i, j);
			}
			j++;
		}
		i++;
	}
}

void	ft_calculate_heat_weight(t_game *game)
{
	t_heat_map **heat_map;

	ft_init_heat_map(game, &heat_map);
	ft_first_calc(game, heat_map);
}

int		ft_put_piece(t_game *game)
{
	ft_calculate_heat_weight(game);
	return (0);
}
