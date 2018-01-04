#include "filler.h"

void		ft_calc_weight(t_map *point, int h_map, int w_map)
{
	int		max_heat;

	max_heat = ft_max(h_map, w_map) * 4;
	point->weight = (COEF_HEAT * point->heat / max_heat
					+ COEF_BORDER * point->border)
					* 100;
}
