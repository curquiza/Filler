#include "filler.h"

static void	ft_init_heat_map(t_game *game, t_heat_map ***heat_map)
{
	int		i;

	*heat_map = ft_memalloc(sizeof(**heat_map) * game->h_map);
	i = 0;
	while (i < game->h_map)
	{
		(*heat_map)[i] = ft_memalloc(sizeof(***heat_map) * game->w_map);
		i++;
	}
}

void	ft_calculate_heat_weight(t_game *game)
{
	t_heat_map **heat;

	ft_init_heat_map(game, &heat);
}

int		ft_put_piece(t_game *game)
{
	ft_calculate_heat_weight(game);
	return (0);
}
