/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:53:43 by curquiza          #+#    #+#             */
/*   Updated: 2018/06/08 19:53:45 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_min(int a, int b)
{
	return (a <= b ? a : b);
}

int		ft_max(int a, int b)
{
	return (a >= b ? a : b);
}
