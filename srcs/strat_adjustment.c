/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_adjustment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:52:55 by curquiza          #+#    #+#             */
/*   Updated: 2018/06/08 19:53:05 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_top_player_adjustment(t_game *game)
{
	if (game->border.bottom == 1 && ft_check_the_bottom(*game))
	{
		game->border.top = 1;
		game->border.bottom = 0;
		ft_border_weight_from_top(game);
	}
	if (game->border.top == 1)
	{
		if (ft_check_the_top(*game) == 1)
		{
			ft_desactivate_border(game);
			game->border.top = 0;
		}
		else if (ft_check_the_top(*game) == -1)
		{
			game->border.top = 0;
			game->border.left = 1;
			ft_border_weight_from_left(game);
		}
	}
	if (game->border.left == 1 && ft_check_the_left(*game))
	{
		ft_desactivate_border(game);
		game->border.left = 0;
	}
}

static void	ft_bottom_player_adjustment(t_game *game)
{
	if (game->border.top == 1 && ft_check_the_top(*game))
	{
		game->border.bottom = 1;
		game->border.top = 0;
		ft_border_weight_from_bottom(game);
	}
	if (game->border.bottom == 1)
	{
		if (ft_check_the_bottom(*game) == 1)
		{
			ft_desactivate_border(game);
			game->border.bottom = 0;
		}
		else if (ft_check_the_bottom(*game) == -1)
		{
			game->border.bottom = 0;
			game->border.right = 1;
			ft_border_weight_from_right(game);
		}
	}
	if (game->border.right == 1 && ft_check_the_right(*game))
	{
		ft_desactivate_border(game);
		game->border.right = 0;
	}
}

void		ft_strat_adjustment(t_game *game)
{
	if (ft_border_is_activate(*game))
	{
		if (ft_is_top_player(*game))
			ft_top_player_adjustment(game);
		else
			ft_bottom_player_adjustment(game);
	}
}
