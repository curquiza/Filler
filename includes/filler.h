#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <fcntl.h>

typedef struct	s_map
{
	char	value;
	int		x;
	int		y;
	float	weight;
	float	heat;
	float	border;
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
	int		pos_x;
	int		pos_y;
}				t_game;

typedef struct	s_heat_map
{
	int		side;
	int		diag;
	int		heat;
}				t_heat_map;

int		ft_first_init(t_game *game);
int		ft_get_data(t_game *game);

int		ft_put_piece(t_game *game, int round);

void	ft_clear_all(t_game *game);
void	ft_delete_all(t_game *game);

void	ft_put_stratmap(t_game game, int round);

#endif
