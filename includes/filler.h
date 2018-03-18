#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <fcntl.h>

typedef struct	s_map
{
	char	value;
	float	weight;
	int		heat;
	int		border;
}				t_map;

typedef struct	s_border
{
	int		top;
	int		bottom;
	int		right;
}				t_border;

typedef struct	s_game
{
	char		my_coin;
	char		opp_coin;
	int			h_map;
	int			w_map;
	char		*gross_map;
	t_map		**strat_map;
	char		*piece;
	int			h_piece;
	int			w_piece;
	int			pos_x;
	int			pos_y;
	int			place_found;
	t_border border;
	float		coef_heat;
	float		coef_border;
}				t_game;

/*
** Tools
*/
int		ft_is_me(t_game game, char value);
int		ft_is_opp(t_game game, char value);
int		ft_is_empty(char value);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

int   ft_border_is_activate(t_game game);
int   ft_heat_is_activate(t_game game);
void  ft_desactivate_border(t_game *game);
void  ft_activate_border(t_game *game);

/*
** Filler
*/
int		ft_first_init(t_game *game);
int		ft_get_data(t_game *game);

void	ft_first_heat_calc(t_game *game);
void	ft_fill_heat_1(t_game *game);
void	ft_fill_heat_2(t_game *game);
void	ft_calc_heat_weight(t_game *game);
void	ft_border_weight_from_top(t_game *game);
void	ft_border_weight_from_bottom(t_game *game);
void	ft_border_weight_from_right(t_game *game);
void	ft_clear_border_weight(t_game *game);
void	ft_strat_map_calc(t_game *game);

int		ft_put_piece(t_game *game, int round);

int 	ft_check_the_top(t_game game);
int 	ft_check_the_bottom(t_game game);
int 	ft_check_the_right(t_game game);
void	ft_strat_adjustment(t_game *game);

void	ft_clear_all(t_game *game);
void	ft_delete_all(t_game *game);

/*
** Debug
*/
void	ft_init_debug(t_game game);
void	ft_put_stratmap_weight(t_game game, int fd); //del
void	ft_put_stratmap_heat(t_game game, int fd); //del
void	ft_put_stratmap(t_game game, int round);
void	ft_put_place_score(int score, int i, int j);
void	ft_put_best_place(int i, int j);

/*
** Test part
*/
void	ft_first_init_strat_map(t_game *game);
void	ft_init_strat_map(t_game *game, char *gross_map);
void	ft_calc_heat_weight(t_game *game);
void	ft_put_stratmap_value(t_game game, int fd);

#endif
