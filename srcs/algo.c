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

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

//static void	ft_init_heat_map(t_game *game, t_heat_map ***map)
//{
//	int		i;
//
//	*map = ft_memalloc(sizeof(**map) * game->h_map);
//	i = 0;
//	while (i < game->h_map)
//	{
//		(*map)[i] = ft_memalloc(sizeof(***map) * game->w_map);
//		i++;
//	}
//}

//int		ft_get_sides(t_game *game, t_heat_map **map, int i, int j)
//{
//	if (i != 0 && ft_is_opp(game, game->strat_map[i - 1][j].value))
//		map[i][j].side++;
//	if (j != 0 && ft_is_opp(game, game->strat_map[i][j - 1].value))
//		map[i][j].side++;
//	if (i != game->h_map - 1
//		&& ft_is_opp(game, game->strat_map[i + 1][j].value))
//		map[i][j].side++;
//	if (j != game->w_map - 1
//		&& ft_is_opp(game, game->strat_map[i][j + 1].value))
//		map[i][j].side++;
//	return (map[i][j].side != 0 ? 1 : 0);
//}
//
//void	ft_get_diag(t_game *game, t_heat_map **map, int i, int j)
//{
//	if (i != 0 && j != 0
//		&& ft_is_opp(game, game->strat_map[i - 1][j - 1].value))
//		map[i][j].diag++;
//	if (i != 0 && j != game->w_map - 1
//		&& ft_is_opp(game, game->strat_map[i - 1][j + 1].value))
//		map[i][j].diag++;
//	if (i != game->h_map - 1 && j != 0
//		&& ft_is_opp(game, game->strat_map[i + 1][j - 1].value))
//		map[i][j].diag++;
//	if (i != game->h_map - 1 && j != game->w_map - 1
//		&& ft_is_opp(game, game->strat_map[i + 1][j + 1].value))
//		map[i][j].diag++;
//}
//
//void	ft_get_heat_with_sides(t_game *game, t_heat_map **map, int i, int j)
//{
//	int		check;
//
//	check = 0;
//	map[i][j].heat = ft_max(game->h_map, game->w_map);
//	if (i != 0 && map[i - 1][j].heat != 0)
//	{
//		map[i][j].heat = ft_min(map[i][j].heat, map[i - 1][j].heat);
//		check = 1;
//	}
//	if (j != 0 && map[i][j - 1].heat != 0)
//	{
//		map[i][j].heat = ft_min(map[i][j].heat, map[i][j - 1].heat);
//		check = 1;
//	}
//	if (i != game->h_map - 1 && map[i + 1][j].heat != 0)
//	{
//		map[i][j].heat = ft_min(map[i][j].heat, map[i + 1][j].heat);
//		check = 1;
//	}
//	if (j != game->w_map - 1 && map[i][j + 1].heat != 0)
//	{
//		map[i][j].heat = ft_min(map[i][j].heat, map[i][j + 1].heat);
//		check = 1;
//	}
//	map[i][j].heat = (check == 1 ? map[i][j].heat - 1 : 0);
//}
//
//void	ft_first_calc_old(t_game *game, t_heat_map **map)
//{
//	int		i;
//	int		j;
//
//	i = 0;
//	while (i < game->h_map)
//	{
//		j = 0;
//		while (j < game->w_map)
//		{
//			if (ft_is_empty(game->strat_map[i][j].value)
//				&& map[i][j].heat == 0)
//			{
//				if (ft_get_sides(game, map, i, j) == 1)
//					map[i][j].heat = ft_max(game->h_map, game->w_map);
//				ft_get_diag(game, map, i, j);
//				if (map[i][j].heat == 0)
//					ft_get_heat_with_sides(game, map, i, j);
//			}
//			j++;
//		}
//		i++;
//	}
//}

int		ft_has_opp_side(t_game *game, int i, int j)
{
	if (i != 0 && ft_is_opp(game, game->strat_map[i - 1][j].value))
		return (1);
	if (j != 0 && ft_is_opp(game, game->strat_map[i][j - 1].value))
		return (1);
	if (i != game->h_map - 1
		&& ft_is_opp(game, game->strat_map[i + 1][j].value))
		return (1);
	if (j != game->w_map - 1
		&& ft_is_opp(game, game->strat_map[i][j + 1].value))
		return (1);
	return (0);
}

void	ft_first_heat_calc(t_game *game)
{
	int		i;
	int		j;
	int		max_val;

	max_val = ft_max(game->h_map, game->w_map);
	i = 0;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
			if (ft_is_empty(game->strat_map[i][j].value)
				&& ft_has_opp_side(game, i, j))
				game->strat_map[i][j].heat = max_val;
			j++;
		}
		i++;
	}
}
void	ft_calculate_heat_weight(t_game *game)
{
	//t_heat_map **heat_map;

	//ft_init_heat_map(game, &heat_map);
	ft_first_heat_calc(game);
	ft_fill_heat_1(game);
}

int		ft_put_piece(t_game *game, int round)
{
	ft_calculate_heat_weight(game);
	ft_put_stratmap(*game, round);
	return (0);
}
