#include "filler.h"

void	ft_delete_all(t_game *game)
{
	int		i;

	ft_strdel(&game->piece);
	ft_strdel(&game->gross_map);
	i = 0;
	while (i < game->h_map)
	{
		free(game->strat_map[i]);
		game->strat_map[i] = NULL;
		i++;
	}
	free(game->strat_map);
	ft_bzero(game, sizeof(*game));
}
