/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:43:24 by curquiza          #+#    #+#             */
/*   Updated: 2018/06/08 17:43:27 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_clear_border_weight(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
			game->strat_map[i][j].border = 0;
			j++;
		}
		i++;
	}
}
