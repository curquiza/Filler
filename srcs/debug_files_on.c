#include "filler.h"

void	ft_put_border_target(t_game game, int fd)
{
	ft_putstr_fd("Border target : ", fd);
	if (game.border.top == 1)
		ft_putstr_fd("TOP", fd);
	else if (game.border.bottom == 1)
		ft_putstr_fd("BOTTOM", fd);
	else if (game.border.right == 1)
		ft_putstr_fd("RIGHT", fd);
	else
		ft_putstr_fd("NONE", fd);
	ft_putstr_fd("\n", fd);
}

void	ft_put_stratmap_weight(t_game game, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (i < game.h_map)
	{
		j = 0;
		while (j < game.w_map)
		{
			if (ft_is_me(game, game.strat_map[i][j].value)
				|| ft_is_opp(game, game.strat_map[i][j].value))
				ft_putchar_fd(game.strat_map[i][j].value, fd);
			else
				dprintf(fd, "%.2f", game.strat_map[i][j].weight); // WARNING
			ft_putchar_fd('\t', fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}

void	ft_put_stratmap_border(t_game game, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (i < game.h_map)
	{
		j = 0;
		while (j < game.w_map)
		{
			if (ft_is_opp(game, game.strat_map[i][j].value)
				|| ft_is_me(game, game.strat_map[i][j].value))
				ft_putchar_fd(game.strat_map[i][j].value, fd);
			else
				ft_putnbr_fd(game.strat_map[i][j].border, fd);
			ft_putchar_fd('\t', fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}

void	ft_put_stratmap_heat(t_game game, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (i < game.h_map)
	{
		j = 0;
		while (j < game.w_map)
		{
			if (ft_is_opp(game, game.strat_map[i][j].value)
				|| ft_is_me(game, game.strat_map[i][j].value))
				ft_putchar_fd(game.strat_map[i][j].value, fd);
			else
				ft_putnbr_fd(game.strat_map[i][j].heat, fd);
			ft_putchar_fd('\t', fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}

void	ft_put_stratmap(t_game game, int round)
{
	int		fd;

	if (round == 1)
		fd = open("debug_strat_map", O_RDWR | O_CREAT | O_TRUNC, 0666);
	else
		fd = open("debug_strat_map", O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd < 0 )
		return ;
	ft_putendl_fd("\n-------------------------\n", fd);
	ft_putstr_fd("ROUND: ", fd);
	ft_putnbr_fd(round, fd);
	ft_putendl_fd("\n", fd);
	ft_putendl_fd("HEAT: ", fd);
	ft_put_stratmap_heat(game, fd);
	ft_putchar_fd('\n', fd);
	ft_put_border_target(game, fd);
	ft_putendl_fd("BORDER: ", fd);
	ft_put_stratmap_border(game, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("WEIGHT: ", fd);
	ft_put_stratmap_weight(game, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("PIECE: ", fd);
	ft_putstr_fd("h = ", fd);
	ft_putnbr_fd(game.h_piece, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("w = ", fd);
	ft_putnbr_fd(game.w_piece, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd(game.piece, fd);
	ft_putendl_fd("VALID PLACES WITH SCORES : ", fd);
	close(fd);
}

void	ft_put_place_score(int score, int i, int j)
{
	int		fd;

	fd = open("debug_strat_map", O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd < 0 )
		return ;
	ft_putstr_fd("i = ", fd);
	ft_putnbr_fd(i, fd);
	ft_putstr_fd(" \tj = ", fd);
	ft_putnbr_fd(j, fd);
	ft_putstr_fd(" \t--> ", fd);
	ft_putnbr_fd(score, fd);
	ft_putendl_fd("", fd);
	close(fd);
}

void	ft_put_best_place(int i, int j)
{
	int		fd;

	fd = open("debug_strat_map", O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd < 0 )
		return ;
	ft_putendl_fd("BEST PLACE : ", fd);
	ft_putstr_fd("i = ", fd);
	ft_putnbr_fd(i, fd);
	ft_putstr_fd(" \tj = ", fd);
	ft_putnbr_fd(j, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
}

void	ft_init_debug(t_game game)
{
	int		fd;

	fd = open("debug_init", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0 )
		return ;
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

// void ft_test()
// {
// 	int fd;
//
// 	fd = open("yo", O_RDWR | O_CREAT | O_APPEND, 0666);
// 	if (fd < 0 )
// 		return ;
// 	ft_putstr_fd("yo", fd);
// 	close(fd);
// }
