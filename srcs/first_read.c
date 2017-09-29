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

int		ft_get_first_data(t_game *game)
{
	if (ft_get_coin(game) == -1)
		return (-1);
	if (ft_get_map_size(game) == -1)
		return (-1);
	game->gross_map = ft_memalloc(sizeof(*game->gross_map) *
				(game->h_map * game->w_map + game->h_map + 1));
	if (ft_fill_map(game) == -1)
		return (-1);
	if (ft_get_piece_size(game) == -1)
		return (-1);
	if (ft_get_piece(game) == -1)
		return (-1);
	return (0);
}
