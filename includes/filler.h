#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_map
{
	char	value;
	int		x;
	int		y;
	int		weight;
	int		heat;
	int		border;
}				t_map;

typedef struct	s_game
{
	char	my_coin;
	char	opp_coin;
	int		h_map;
	int		w_map;
	char	*gross_map;
	t_map	**strat_map;
	char	*piece;
	int		h_piece;
	int		w_piece;
}				t_game;

#endif
