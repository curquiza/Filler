#include "filler.h"

static void	ft_calc_heat_weight(t_game *game)
{
	ft_first_heat_calc(game);
	ft_fill_heat_1(game);
	ft_fill_heat_2(game);
}

int		ft_put_piece(t_game *game, int round)
{
	(void)round;
	ft_calc_heat_weight(game);
	//ft_put_stratmap(*game, round);
	return (0);
}
