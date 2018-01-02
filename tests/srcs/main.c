#include "filler.h"

static	int	ft_read_input(t_game *game, char *av)
{
	char	*line;
	char	*tmp;
	int		cpt;
	int		len;
	int		fd;

	if ((fd = open(av, O_RDONLY)) <= 0)
		return (-1);
	cpt = 0;
	len = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (cpt == 0 && line)
			len = ft_strlen(line);
		else if (line && len != (int)ft_strlen(line))
		{
			ft_putendl_fd("Width error", 2);
			return (-1);
		}
		tmp = game->gross_map;
		game->gross_map = ft_strjoin3(tmp, line, "\n");
		ft_strdel(&tmp);
		ft_strdel(&line);
		cpt++;
	}
	game->h_map = cpt;
	game->w_map = len;
	return (0);
}

static void	ft_get_coin(t_game *game, char *coin)
{
	if (!coin || (coin && coin[0] == 'x'))
	{
		game->my_coin = 'x';
		game->opp_coin = 'o';
	}
	else
	{
		game->my_coin = 'o';
		game->opp_coin = 'x';
	}
}

static void	ft_put_init(t_game game)
{
	ft_putstr("my_coin = ");
	ft_putchar(game.my_coin);
	ft_putchar('\n');
	ft_putstr("opp_coin = ");
	ft_putchar(game.opp_coin);
	ft_putchar('\n');
	ft_putnbr2("h_map = ", game.h_map);
	ft_putnbr2("w_map = ", game.w_map);
	ft_putendl2_fd("\nGROSS_MAP :\n", game.gross_map, 1);
}

static void	ft_calc_heat_weight(t_game *game)
{
	ft_first_heat_calc(game);
	ft_fill_heat_1(game);
	ft_fill_heat_2(game);
}

int		main(int ac, char **av)
{
	t_game game;
	
	if (ac <= 1)
		ft_exit("No input", 2);
	if (ft_read_input(&game, av[1]) == -1)
		ft_exit("Read error", 2);
	ft_get_coin(&game, av[2]);
	ft_put_init(game);
	ft_calc_heat_weight(&game);
	return (0);
}
