#include "filler.h"

void		ft_calc_weight(t_map *point, t_game game)
{
	int		max_heat;
	int		max_border;

	max_heat = ft_max(game.h_map, game.w_map) * 4;
	max_border = ft_max(game.h_map, game.w_map);
	point->weight = (game.coef_heat * point->heat / max_heat
					+ game.coef_border * point->border / max_border)
					* 100;
}
