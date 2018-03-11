#include "filler.h"

static int		ft_get_coin(t_game *game)
{
	char	*line;

	if (get_next_line(0, &line) == -1)
		return (-1);
	if (line[10] == '1')
	{
		game->my_coin = 'o';
		game->opp_coin = 'x';
	}
	else
	{
		game->my_coin = 'x';
		game->opp_coin = 'o';
	}
	ft_strdel(&line);
	return (0);
}

static int		ft_get_map_size(t_game *game)
{
	char	*start;
	char	*middle;
	char	*end;
	char	*nbr;
	char	*line;

	if (get_next_line(0, &line) == -1)
		return (-1);
	if (!(start = ft_strchr(line, ' '))
		|| !(middle = ft_strchr(start + 1, ' '))
		|| !(end = ft_strchr(middle + 1, ':')))
	{
		ft_strdel(&line);
		return (-1);
	}
	nbr = ft_strsub(start + 1, 0, middle - start + 1);
	game->h_map = ft_atoi(nbr);
	ft_strdel(&nbr);
	nbr = ft_strsub(middle + 1, 0, end - middle + 1);
	game->w_map = ft_atoi(nbr);
	ft_strdel(&nbr);
	ft_strdel(&line);
	return (0);
}

void	ft_first_init_strat_map(t_game *game)
{
	int		i;
	int		j;

	game->strat_map = ft_memalloc(sizeof(*game->strat_map) * game->h_map);
	i = 0;
	while (i < game->h_map)
	{
		game->strat_map[i] = ft_memalloc(sizeof(**game->strat_map)
											* game->w_map);
		j = 0;
		while (j < game->w_map)
		{
			game->strat_map[i][j].x = i;
			game->strat_map[i][j].y = j;
			j++;
		}
		i++;
	}
}

static void	ft_init_coef(t_game *game)
{
	if (game->my_coin == 'x')
	{
		game->coef_heat = 0;
		game->coef_border = 1;
	}
	else
	{
		game->coef_heat = 1.0;
		game->coef_border = 0;
	}
}

int		ft_first_init(t_game *game)
{
	ft_bzero(game, sizeof(game));
	if (ft_get_coin(game) == -1)
		return (-1);
	if (ft_get_map_size(game) == -1)
		return (-1);
	game->gross_map = ft_memalloc(sizeof(*game->gross_map) *
				(game->h_map * game->w_map + game->h_map + 1));
	ft_first_init_strat_map(game);
	ft_calc_border_weight(game);
	ft_init_coef(game);
	ft_init_debug(*game); //debug
	return (0);
}
