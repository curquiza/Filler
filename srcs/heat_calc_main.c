/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_calc_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:44:47 by curquiza          #+#    #+#             */
/*   Updated: 2018/06/08 18:44:48 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_calc_heat_weight(t_game *game)
{
	ft_first_heat_calc(game);
	ft_fill_heat_1(game);
	ft_fill_heat_2(game);
}
