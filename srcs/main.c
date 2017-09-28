#include "filler.h"
#include <fcntl.h>

void	ft_fill_coin(char player, t_game *game)
{
	if (player == '1')
	{
		game->my_coin = 'o';
		game->opp_coin = 'x';
	}
	else
	{
		game->my_coin = 'x';
		game->opp_coin = 'o';
	}
}

int		ft_fill_map_size(char *line, t_game *game)
{
	char	*start;
	char	*middle;
	char	*end;
	char	*nbr;

	if ((start = ft_strchr(line, ' ')) == NULL)
		return (-1);
	if ((middle = ft_strchr(start + 1, ' ')) == NULL)
		return (-1);
	if ((end = ft_strchr(middle + 1, ':')) == NULL)
		return (-1);
	nbr = ft_strsub(start + 1, 0, middle - start + 1);
	game->h_map = ft_atoi(nbr);
	ft_strdel(&nbr);
	nbr = ft_strsub(middle + 1, 0, end - middle + 1);
	game->w_map = ft_atoi(nbr);
	ft_strdel(&nbr);
	return (0);
}

int		ft_get_first_data(t_game *game)
{
	char	*line;

	if (get_next_line(0, &line) == -1)
		return (-1);
	ft_fill_coin(line[10], game);
	ft_strdel(&line);
	if (get_next_line(0, &line) == -1)
		return (-1);
	ft_fill_map_size(line, game);
	return (0);
}

void	ft_debug(t_game game)
{
	int		fd;

	fd = open("debug", O_RDWR | O_CREAT, 0666);
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
	close(fd);
}

int		main(void)
{
	t_game	game;

	ft_get_first_data(&game);
	ft_debug(game);
	return (0);
}

/*int		main(void)
{
	char	line[10001];
	int		fd;

	//get_next_line(0, &line);
	ft_bzero(line, 10001);
	read(0, line, 10000);
	fd = open("debug", O_RDWR | O_CREAT | O_APPEND, 0666);
	ft_putendl_fd("--- NOUVELLE LECTURE ---", fd);
	ft_putendl_fd(line, fd);
	ft_putendl("8 2");
	//sleep(2);
	ft_putendl_fd("--- NOUVELLE LECTURE ---", fd);
	ft_bzero(line, 10001);
	//ft_putnbr_fd(read(0, line, 10000), fd);
	read(0, line, 10000);
	ft_putendl_fd(line, fd);
	//sleep(2);
	//ft_putendl("8 2");
	//close (fd);
	return (0);
}*/
