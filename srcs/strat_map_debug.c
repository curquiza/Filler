#include "filler.h"

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
				//ft_putnbr_fd(game.strat_map[i][j].weight, fd);
				dprintf(fd, "%.2f", game.strat_map[i][j].weight);
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
	ft_putstr_fd("ROUND: ", fd);
	ft_putnbr_fd(round, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("HEAT: ", fd);
	ft_put_stratmap_heat(game, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("PIECE: ", fd);
	ft_putstr_fd("h = ", fd);
	ft_putnbr_fd(game.h_piece, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("w = ", fd);
	ft_putnbr_fd(game.w_piece, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd(game.piece, fd);
	ft_putendl_fd("-------------------------\n", fd);
}
