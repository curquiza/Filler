#include "filler.h"

void		ft_calc_weight(t_map *point, int h_map, int w_map)
{
	int		max_heat;
	int		max_border;

	max_heat = ft_max(h_map, w_map) * 4;
	max_border = ft_max(h_map, w_map) * 2;
	point->weight = (COEF_HEAT * point->heat / max_heat
					// + COEF_BORDER * point->border
					+ COEF_BORDER * point->border / max_border)
					* 100;
}
