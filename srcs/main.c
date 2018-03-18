#include "filler.h"

void	ft_calc_heat_weight(t_game *game)
{
	ft_first_heat_calc(game);
	ft_fill_heat_1(game);
	ft_fill_heat_2(game);
}

int		main(void)
{
	t_game	game;
	int		round;

	if (ft_first_init(&game) == -1)
		ft_exit("Read error", 2);
	round = 1;
	while (1)
	{
		if (ft_get_data(&game) == -1)
			break ;
		if (ft_heat_is_activate(game))
			ft_calc_heat_weight(&game);
		if (ft_put_piece(&game, round) == -1)
			break ;
		ft_strat_adjustment(&game);
		ft_clear_all(&game);
		round++;
	}
	ft_delete_all(&game);
	// while (1);
	return (0);
}
