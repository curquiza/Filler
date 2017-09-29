#include "filler.h"

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
	ft_putendl_fd("STRAT MAP: ", fd);
	ft_putnbr_fd(game.strat_map[1][1].x, fd);
	close(fd);
}

int		main(void)
{
	t_game	game;

	if (ft_get_first_data(&game) == -1)
		ft_exit("Read error", 2);
	ft_init_strat_map(&game, game.gross_map);
	ft_debug(game);
	//while (1);
	return (0);
}
