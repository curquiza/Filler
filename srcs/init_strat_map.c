#include "filler.h"

void	ft_init_strat_map(t_game *game, char *gross_map)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
			game->strat_map[i][j].value = *gross_map;
			gross_map++;
			j++;
		}
		gross_map++;
		i++;
	}
}
