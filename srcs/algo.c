#include "filler.h"

void	ft_calc_heat_weight(t_game *game)
{
	ft_first_heat_calc(game);
	ft_fill_heat_1(game);
	ft_fill_heat_2(game);
}

int		ft_find_placement(t_game *game, int round)
{
	ft_calc_heat_weight(game);
	ft_put_stratmap(*game, round);
	return (0);
}
