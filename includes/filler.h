#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <fcntl.h>

# define COEF_HEAT 0.90
# define COEF_BORDER 0.10

typedef struct	s_map
{
	char	value;
	int		x;
	int		y;
	float	weight;
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

//typedef struct	s_heat_map
//{
//	int		side;
//	int		diag;
//	int		heat;
//}				t_heat_map;

/*
** Tools
*/
int		ft_is_me(t_game game, char value);
int		ft_is_opp(t_game game, char value);
int		ft_is_empty(char value);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

/*
** Filler
*/
int		ft_first_init(t_game *game);
int		ft_get_data(t_game *game);

int		ft_find_placement(t_game *game, int round);

void	ft_first_heat_calc(t_game *game);
void	ft_fill_heat_1(t_game *game);
void	ft_fill_heat_2(t_game *game);

void	ft_calc_weight(t_map *point, int h_map, int w_map);

void	ft_clear_all(t_game *game);
void	ft_delete_all(t_game *game);

/*
** Debug
*/
void	ft_put_stratmap(t_game game, int round);
void	ft_init_debug(t_game game);

/*
** Test part
*/
void	ft_first_init_strat_map(t_game *game);
void	ft_init_strat_map(t_game *game, char *gross_map);
void	ft_calc_heat_weight(t_game *game);
void	ft_put_stratmap_value(t_game game, int fd);
void	ft_put_stratmap_coord(t_game game, int fd);
void	ft_put_stratmap_heat(t_game game, int fd);
void	ft_put_stratmap_weight(t_game game, int fd);

#endif
