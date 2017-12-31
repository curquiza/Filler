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
			ft_putnbr_fd(game.strat_map[i][j].heat, fd);
			ft_putchar_fd(' ', fd);
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
		fd = open("strat_map_debug", O_RDWR | O_CREAT | O_TRUNC, 0666);
	else
		fd = open("strat_map_debug", O_RDWR | O_CREAT | O_APPEND, 0666);
	ft_putstr_fd("ROUND: ", fd);
	ft_putnbr_fd(round, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("HEAT: ", fd);
	ft_put_stratmap_heat(game, fd);
	ft_putchar_fd('\n', fd);
}
