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
	ft_putendl("STRAT_MAP COORD:");
	ft_put_stratmap_coord(game, 1);
	ft_putchar('\n');
	ft_putendl("STRAT_MAP VALUE:");
	ft_put_stratmap_value(game, 1);
	ft_putchar('\n');
}

static void	ft_init(t_game *game, char *av, char *coin)
{
	if (ft_read_input(game, av) == -1)
		ft_exit("Read error", 2);
	ft_get_coin(game, coin);
	ft_first_init_strat_map(game);
	ft_init_strat_map(game, game->gross_map);
	ft_put_init(*game);
}

int		main(int ac, char **av)
{
	t_game game;
	
	ft_bzero(&game, sizeof(game));
	if (ac <= 1)
		ft_exit("No input", 2);
	ft_init(&game, av[1], av[2]);
	ft_calc_heat_weight(&game);
	ft_putendl("STRAT_MAP HEAT:");
	ft_put_stratmap_heat(game, 1);
	ft_putendl("\nSTRAT_MAP WEIGHT:");
	ft_put_stratmap_weight(game, 1);
	return (0);
}
