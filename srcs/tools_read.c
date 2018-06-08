/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 20:19:29 by curquiza          #+#    #+#             */
/*   Updated: 2018/06/08 20:19:54 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_start_middle_end(char *line, char **start, char **middle,
														char **end)
{
	*start = ft_strchr(line, ' ');
	if (!(*start))
		return (-1);
	*middle = ft_strchr(*start + 1, ' ');
	if (!(*middle))
		return (-1);
	*end = ft_strchr(*middle + 1, ':');
	if (!(*end))
		return (-1);
	return (0);
}
