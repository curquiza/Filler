/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:33:35 by curquiza          #+#    #+#             */
/*   Updated: 2018/05/25 17:33:37 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_border_weight_from_top(t_game *game)
{
	int		i;
	int		j;
	int		value;
	int		max_border;

	max_border = ft_max(game->h_map, game->w_map);
	i = 0;
	value = max_border;
	while (i < game->h_map)
	{
		j = 0;
		while (j < game->w_map)
		{
			game->strat_map[i][j].border = value;
			j++;
		}
		i++;
		value--;
	}
}

void	ft_border_weight_from_bottom(t_game *game)
{
	int		i;
	int		j;
	int		value;
	int		max_border;

	max_border = ft_max(game->h_map, game->w_map);
	i = game->h_map - 1;
	value = max_border;
	while (i >= 0)
	{
		j = 0;
		while (j < game->w_map)
		{
			game->strat_map[i][j].border = value;
			j++;
		}
		i--;
		value--;
	}
}

void	ft_border_weight_from_right(t_game *game)
{
	int		i;
	int		j;
	int		value;
	int		max_border;

	max_border = ft_max(game->h_map, game->w_map);
	j = game->w_map - 1;
	value = max_border;
	while (j >= 0)
	{
		i = 0;
		while (i < game->h_map)
		{
			game->strat_map[i][j].border = value;
			i++;
		}
		j--;
		value--;
	}
}

void	ft_border_weight_from_left(t_game *game)
{
	int		i;
	int		j;
	int		value;
	int		max_border;

	max_border = ft_max(game->h_map, game->w_map);
	j = 0;
	value = max_border;
	while (j < game->w_map)
	{
		i = 0;
		while (i < game->h_map)
		{
			game->strat_map[i][j].border = value;
			i++;
		}
		j++;
		value--;
	}
}
