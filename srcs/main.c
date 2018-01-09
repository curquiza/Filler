#include "filler.h"

int		main(void)
{
	t_game	game;
	int		round;

	ft_bzero(&game, sizeof(game));
	if (ft_first_init(&game) == -1)
		ft_exit("Read error", 2);
	ft_init_debug(game);
	round = 1;
	while (1)
	{
		if (ft_get_data(&game) == -1)
			break ;
		if (ft_put_piece(&game, round) == -1)
			break ;
		//else
		//	ft_printf("%d %d\n", 12, 14);
		ft_clear_all(&game);
		round++;
	}
	ft_delete_all(&game);
	//while (1);
	return (0);
}
