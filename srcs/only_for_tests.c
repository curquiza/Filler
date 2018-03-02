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
