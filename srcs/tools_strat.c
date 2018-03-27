#include "filler.h"

int		ft_border_is_activate(t_game game)
{
	return (game.coef_border == 1);
}

int		ft_heat_is_activate(t_game game)
{
	return (game.coef_heat == 1);
}

void	ft_activate_heat(t_game *game)
{
	game->coef_heat = 1.0;
	game->coef_border = 0;
}

void	ft_activate_border(t_game *game)
{
	game->coef_heat = 0;
	game->coef_border = 1.0;
}

void	ft_desactivate_border(t_game *game)
{
	ft_activate_heat(game);
	ft_clear_border_weight(game);
}
