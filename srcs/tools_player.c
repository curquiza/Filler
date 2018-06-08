/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:53:53 by curquiza          #+#    #+#             */
/*   Updated: 2018/06/08 19:54:03 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_is_me(t_game game, char value)
{
	return (value == game.my_coin || value == game.my_coin - 32);
}

int		ft_is_opp(t_game game, char value)
{
	return (value == game.opp_coin || value == game.opp_coin - 32);
}

int		ft_is_empty(char value)
{
	return (value == '.');
}

int		ft_is_top_player(t_game game)
{
	return (game.player_position == 1);
}
