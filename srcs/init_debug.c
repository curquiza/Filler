#include "filler.h"

void	ft_put_stratmap_coord(t_game game, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (i < game.h_map)
	{
		j = 0;
		while (j < game.w_map)
		{
			ft_putnbr_fd(game.strat_map[i][j].x, fd);
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(game.strat_map[i][j].y, fd);
			ft_putchar_fd(' ', fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}

void	ft_put_stratmap_value(t_game game, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (i < game.h_map)
	{
		j = 0;
		while (j < game.w_map)
		{
			ft_putchar_fd(game.strat_map[i][j].value, fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}

void	ft_init_debug(t_game game)
{
	int		fd;

	fd = open("debug_init", O_RDWR | O_CREAT | O_TRUNC, 0666);
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
	//ft_putendl_fd("GROSS_MAP : ", fd);
	//ft_putstr_fd(game.gross_map, fd);
	//ft_putstr_fd("h_piece : ", fd);
	//ft_putnbr_fd(game.h_piece, fd);
	//ft_putendl_fd("", fd);
	//ft_putstr_fd("w_piece : ", fd);
	//ft_putnbr_fd(game.w_piece, fd);
	//ft_putendl_fd("", fd);
	//ft_putendl_fd("PIECE : ", fd);
	//ft_putstr_fd(game.piece, fd);
	//ft_putendl_fd("STRAT MAP VALUE: ", fd);
	//ft_put_stratmap_value(game, fd);
	ft_putendl_fd("STRAT MAP X-Y: ", fd);
	ft_put_stratmap_coord(game, fd);
	close(fd);
}
