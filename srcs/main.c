/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:29:57 by curquiza          #+#    #+#             */
/*   Updated: 2018/05/25 15:02:13 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
		ft_strat_map_calc(&game);
		if (ft_put_piece(&game, round) == -1)
			break ;
		ft_strat_adjustment(&game);
		ft_clear_all(&game);
		round++;
	}
	ft_delete_all(&game);
	return (0);
}
