/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_files_others_on.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:43:59 by curquiza          #+#    #+#             */
/*   Updated: 2018/06/08 17:45:01 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_put_place_score(int score, int i, int j)
{
	int		fd;

	fd = open("debug_strat_map", O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd < 0)
		return ;
	ft_putstr_fd("i = ", fd);
	ft_putnbr_fd(i, fd);
	ft_putstr_fd(" \tj = ", fd);
	ft_putnbr_fd(j, fd);
	ft_putstr_fd(" \t--> ", fd);
	ft_putnbr_fd(score, fd);
	ft_putendl_fd("", fd);
	close(fd);
}

void	ft_put_best_place(int i, int j)
{
	int		fd;

	fd = open("debug_strat_map", O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd < 0)
		return ;
	ft_putendl_fd("BEST PLACE : ", fd);
	ft_putstr_fd("i = ", fd);
	ft_putnbr_fd(i, fd);
	ft_putstr_fd(" \tj = ", fd);
	ft_putnbr_fd(j, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
}

void	ft_init_debug(t_game game)
{
	int		fd;

	fd = open("debug_init", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		return ;
	ft_putstr_fd("my_coin : ", fd);
	ft_putchar_fd(game.my_coin, fd);
	ft_putendl_fd("", fd);
	ft_putstr_fd("opp_coin : ", fd);
	ft_putchar_fd(game.opp_coin, fd);
	ft_putendl_fd("", fd);
	ft_putstr_fd("h_map : ", fd);
	ft_putnbr_fd(game.h_map, fd);
	ft_putendl_fd("", fd);
	ft_putstr_fd("w_map : ", fd);
	ft_putnbr_fd(game.w_map, fd);
	ft_putendl_fd("", fd);
	close(fd);
}
