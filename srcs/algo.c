#include "filler.h"

void	ft_calc_heat_weight(t_game *game)
{
	ft_first_heat_calc(game);
	ft_fill_heat_1(game);
	ft_fill_heat_2(game);
}

void	ft_deplacement(char piece_value, int *i, int *j, int init_j)
{
	if (piece_value == '\n')
	{
		*j = init_j;
		(*i)++;
	}
	else
		(*j)++;
}

int 	ft_calc_score(t_game game, int i, int j)
{
	float	score;
	int		my_coin;
	int		init_j;

	score = 0;
	my_coin = 0;
	init_j = j;
	while (*game.piece)
	{
		if (game.piece == '*')
		{
			if (j >= game.w || i >= game.w)
				return (0);
			if (ft_is_me(game, game.strat_map[i][j].value) && my_coin == 0)
				my_coin = 1
			else if (ft_is_me(game, game.strat_map[i][j].value) && my_coin == 1)
				return (0);
			else if (ft_is_opp(game, game.strat_map[i][j].value))
				return (0);
			else if (ft_is_empty(game, game.strat_map[i][j].value))
				score += game.strat_map[i][j].weight;
		}
		game.piece++;
		ft_deplacement(*game.piece, i, j, init_j);
	}
	return (score);
}

void	ft_get_place(t_game *game)
{
	int		i;
	int		j;
	float	best_score;

	best_score = 0;
	i = 0;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
			if (ft_calc_score(*game, i, j) > best_score)
			{
				game->pos_x = i;
				game->pos_y = j;
			}
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
