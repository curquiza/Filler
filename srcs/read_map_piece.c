#include "filler.h"

int		ft_fill_map(t_game *game)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) == -1)
		return (-1);
	ft_strdel(&line);
	i = 0;
	while (i < game->h_map)
	{
		if (get_next_line(0, &line) == -1)
			return (-1);
		ft_strcat(game->gross_map, ft_strchr(line, ' ') + 1);
		ft_strcat(game->gross_map, "\n");
		ft_strdel(&line);
		i++;
	}
	return (0);
}

int		ft_get_piece_size(t_game *game)
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
	game->h_piece = ft_atoi(nbr);
	ft_strdel(&nbr);
	nbr = ft_strsub(middle + 1, 0, end - middle + 1);
	game->w_piece = ft_atoi(nbr);
	ft_strdel(&nbr);
	ft_strdel(&line);
	return (0);
}

int		ft_get_piece(t_game *game)
{
	char	*line;
	int		i;

	game->piece = ft_memalloc(sizeof(*game->piece) *
				(game->h_piece * game->w_piece + game->h_piece + 1));
	i = 0;
	while (i < game->h_piece)
	{
		if (get_next_line(0, &line) == -1)
			return (-1);
		ft_strcat(game->piece, line);
		ft_strcat(game->piece, "\n");
		ft_strdel(&line);
		i++;
	}
	return (0);
}

/*int		ft_get_piece(t_game *game)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	while (i < game->h_piece)
	{
		if (get_next_line(0, &line) == -1)
			return (-1);
		tmp = game->piece;
		if (game->piece)
			game->piece = ft_strjoin3(tmp, line, "\n");
		else
			game->piece = ft_strjoin(line, "\n");
		ft_strdel(&tmp);
		ft_strdel(&line);
		i++;
	}
	return (0);
}*/
