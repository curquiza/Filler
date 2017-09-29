#include "filler.h"

int		ft_get_map(t_game *game)
{
	char	*line;
	char	*tmp;
	int		i;

	if (get_next_line(0, &line) == -1)
		return (-1);
	ft_strdel(&line);
	i = 0;
	while (i < game->h_map)
	{
		if (get_next_line(0, &line) == -1)
			return (-1);
		tmp = game->gross_map;
		if (game->gross_map)
			game->gross_map = ft_strjoin3(tmp, ft_strchr(line, ' ') + 1, "\n");
		else
			game->gross_map = ft_strjoin(ft_strchr(line, ' ') + 1, "\n");
		ft_strdel(&tmp);
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
}
