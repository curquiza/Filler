#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <fcntl.h>

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
	int		pos_x;
	int		pos_y;
}				t_game;


int		ft_fill_map(t_game *game);
int		ft_get_piece_size(t_game *game);
int		ft_get_piece(t_game *game);
int		ft_get_first_data(t_game *game);

void	ft_init_strat_map(t_game *game, char *gross_map);

void	ft_clear_all(t_game *game)
void	ft_first_init_strat_map(t_game *game, char *gross_map);

void	ft_delete_all(t_game *game);

#endif
