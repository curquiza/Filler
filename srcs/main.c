#include "filler.h"

int 	ft_check_the_top(t_game game)
{
	int		j;
	int		opp_coin;

	j = 0;
	opp_coin = 0;
	while (j < game.w_map)
	{
		if (ft_is_opp(game, game.strat_map[0][j].value))
			opp_coin++;
		if (ft_is_me(game, game.strat_map[0][j].value))
			return (1);
		j++;
	}
	if (opp_coin >= (game.w_map / 2 + 2))
		return (1);
	return (0);
}

void	ft_check_border(t_game *game)
{
	if (game->touch_border == 0 && ft_check_the_top(*game))
	{
		game->touch_border = 1;
		game->coef_heat = 1.0;
		game->coef_border = 0;
	}
}

int		main(void)
{
	t_game	game;
	int		round;

	if (ft_first_init(&game) == -1)
		ft_exit("Read error", 2);
	round = 1;
	while (1)
	{
		if (ft_get_data(&game) == -1)
			break ;
		if (ft_put_piece(&game, round) == -1)
			break ;
		ft_check_border(&game);
		ft_clear_all(&game);
		round++;
	}
	ft_delete_all(&game);
	// while (1);
	return (0);
}
