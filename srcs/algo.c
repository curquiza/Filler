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

float	ft_calc_score(t_game game, int i, int j)
{
	float	score;
	int		my_coin;
	int		init_j;

	score = 0;
	my_coin = 0;
	init_j = j;
	while (*game.piece)
	{
		if (*game.piece == '*')
		{
			if (j >= game.w_map || i >= game.h_map || j < 0 || i < 0)
				return (0);
			if (ft_is_me(game, game.strat_map[i][j].value) && my_coin == 0)
				my_coin = 1;
			else if (ft_is_me(game, game.strat_map[i][j].value) && my_coin == 1)
				return (0);
			else if (ft_is_opp(game, game.strat_map[i][j].value))
				return (0);
			else if (ft_is_empty(game.strat_map[i][j].value))
				score += game.strat_map[i][j].weight;
		}
		ft_deplacement(*game.piece, &i, &j, init_j);
		game.piece++;
	}
	return (my_coin == 1 ? score : 0);
}

void	ft_get_place(t_game *game)
{
	int		i;
	int		j;
	float	best_score;
	float	tmp;

	best_score = 0;
	i = 0 - game->h_piece;
	while (i < game->h_map)
	{
		j = 0 - game->w_piece;
		while (j < game->w_map)
		{
			tmp = ft_calc_score(*game, i, j);
			if (tmp != 0)
				ft_put_place_score(tmp, i, j); // debug
			if (tmp > best_score)
			{
				best_score = tmp;
				game->pos_x = i;
				game->pos_y = j;
				game->place_found = 1;
			}
			j++;
		}
		i++;
	}
}

int		ft_put_piece(t_game *game, int round)
{
	ft_calc_heat_weight(game);
	ft_put_stratmap(*game, round); // debug
	ft_get_place(game);
	ft_printf("%d %d\n", game->pos_x, game->pos_y);
	ft_put_best_place(game->pos_x, game->pos_y); // debug
	if (game->place_found == 0)
		return (-1);
	return (0);
}
