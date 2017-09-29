#include "filler.h"
#include <fcntl.h>

int		ft_get_coin(t_game *game)
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

int		ft_get_map_size(t_game *game)
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

int		ft_get_first_data(t_game *game)
{
	if (ft_get_coin(game) == -1)
		return (-1);
	if (ft_get_map_size(game) == -1)
		return (-1);
	if (ft_get_map(game) == -1)
		return (-1);
	if (ft_get_piece_size(game) == -1)
		return (-1);
	if (ft_get_piece(game) == -1)
		return (-1);
	return (0);
}

void	ft_debug(t_game game)
{
	int		fd;

	fd = open("debug", O_RDWR | O_CREAT | O_TRUNC, 0666);
	ft_putstr_fd("my_coin : ", fd);
	ft_putchar_fd(game.my_coin, fd);
	ft_putendl_fd("", fd);
	ft_putstr_fd("opp_coin : ", fd);
	ft_putchar_fd(game.opp_coin, fd);
	ft_putendl_fd("", fd);
	ft_putstr_fd("h_map : ", fd);
	ft_putnbr_fd(game.h_map, fd);
	ft_putendl_fd("", fd);
	ft_putstr_fd("w_map : ", fd);
	ft_putnbr_fd(game.w_map, fd);
	ft_putendl_fd("", fd);
	ft_putendl_fd("GROSS_MAP : ", fd);
	ft_putstr_fd(game.gross_map, fd);
	ft_putstr_fd("h_piece : ", fd);
	ft_putnbr_fd(game.h_piece, fd);
	ft_putendl_fd("", fd);
	ft_putstr_fd("w_piece : ", fd);
	ft_putnbr_fd(game.w_piece, fd);
	ft_putendl_fd("", fd);
	ft_putendl_fd("PIECE : ", fd);
	ft_putstr_fd(game.piece, fd);
	close(fd);
}

int		main(void)
{
	t_game	game;

	if (ft_get_first_data(&game) == -1)
		ft_exit("Read error", 2);
	ft_debug(game);
	//while (1);
	return (0);
}
