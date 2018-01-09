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
			if (j >= game.w_map || i >= game.h_map)
			{
				ft_putendl_fd("Map out", 2);
				return (0);
			}
			if (ft_is_me(game, game.strat_map[i][j].value) && my_coin == 0)
				my_coin = 1;
			else if (ft_is_me(game, game.strat_map[i][j].value) && my_coin == 1)
			{
				ft_putendl_fd("my_coin twice", 2);
				return (0);
			}
			else if (ft_is_opp(game, game.strat_map[i][j].value))
			{
				ft_putendl_fd("opp_coin", 2);
				return (0);
			}
			else if (ft_is_empty(game.strat_map[i][j].value))
				score += game.strat_map[i][j].weight;
		}
		ft_deplacement(*game.piece, &i, &j, init_j);
		game.piece++;
	}
	if (my_coin == 1)
	{
		ft_putendl_fd("yeah", 2);
		ft_putstr_fd("score is : ", 2);
		ft_putnbr_fd(score, 2);
		ft_putchar_fd('\n', 2);
		return (score);
	}
	else
	{
		ft_putendl_fd("no my_coin", 2);
		return (0);
	}
	//return (my_coin == 1 ? score : 0);
}

void	ft_get_place(t_game *game)
{
	int		i;
	int		j;
	float	best_score;
	float	tmp;

	best_score = 0;
	i = 0;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
				ft_putstr_fd("i = ", 2);
				ft_putnbr_fd(i, 2);
				ft_putchar_fd('\n', 2);
				ft_putstr_fd("j = ", 2);
				ft_putnbr_fd(j, 2);
				ft_putchar_fd('\n', 2);
			if ((tmp = ft_calc_score(*game, i, j)) > best_score)
			{
				ft_putendl_fd("FOUND", 2);
				ft_putnbr_fd(tmp, 2);
				ft_putchar_fd('\n', 2);
				best_score = tmp;
				game->pos_x = i;
				game->pos_y = j;
				game->place_found = 1;
			}
				ft_putendl_fd("-----", 2);
			j++;
		}
		i++;
	}
}

int		ft_put_piece(t_game *game, int round)
{
	ft_calc_heat_weight(game);
	ft_put_stratmap(*game, round);
	ft_get_place(game);
	ft_putstr_fd("pos_x = ", 2);
	ft_putnbr_fd(game->pos_x, 2);
	ft_putstr_fd("\npos_y = ", 2);
	ft_putnbr_fd(game->pos_y, 2);
	ft_putchar_fd('\n', 2);
	ft_printf("%d %d\n", game->pos_x, game->pos_y);
	if (game->place_found == 0)
		return (-1);
	return (0);
}
