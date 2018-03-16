#include "filler.h"

int   ft_border_is_activate(t_game game)
{
  if (game.coef_border == 1)
    return (1);
  return (0);
}

void  ft_desactivate_border(t_game *game)
{
  game->coef_heat = 1.0;
  game->coef_border = 0;
  ft_clear_border_weight(game);
}

void  ft_activate_border(t_game *game)
{
  game->coef_heat = 0;
  game->coef_border = 1.0;
}

int 	ft_check_the_top(t_game game)
{
	int		j;
	int		opp_coin;

	j = 0;
	opp_coin = 0;
	while (j < game.w_map)
	{
		if (ft_is_opp(game, game.strat_map[0][j].value))
			opp_coin++;
		if (ft_is_me(game, game.strat_map[0][j].value))
			return (1);
		j++;
	}
	if (opp_coin >= (game.w_map / 2 + 2))
		return (1);
	return (0);
}

int 	ft_check_the_bottom(t_game game)
{
	int		j;
	int		opp_coin;

	j = 0;
	opp_coin = 0;
	while (j < game.w_map)
	{
		if (ft_is_opp(game, game.strat_map[game.h_map - 1][j].value))
			opp_coin++;
		if (ft_is_me(game, game.strat_map[game.h_map - 1][j].value))
			return (1);
		j++;
	}
	if (opp_coin >= (game.w_map / 2 + 2))
		return (-1);
	return (0);
}

int 	ft_check_the_right(t_game game)
{
	int		i;
	int		opp_coin;

	i = 0;
	opp_coin = 0;
	while (i < game.h_map)
	{
		if (ft_is_opp(game, game.strat_map[i][game.w_map - 1].value))
			opp_coin++;
		if (ft_is_me(game, game.strat_map[i][game.w_map - 1].value))
			return (1);
		i++;
	}
	if (opp_coin >= (game.w_map / 2 + 2))
		return (1);
	return (0);
}

void	ft_check_border(t_game *game)
{
  if (ft_border_is_activate(*game))
  {
    if (game->border.top == 1 && ft_check_the_top(*game))
  	{
      game->border.bottom = 1;
      game->border.top = 0;
      ft_border_weight_from_bottom(game);
  	}
    if (game->border.bottom == 1)
    {
      if (ft_check_the_bottom(*game) == 1)
      {
        ft_desactivate_border(game);
        game->border.bottom = 0;
      }
      else if (ft_check_the_bottom(*game) == -1)
      {
        game->border.bottom = 0;
        game->border.right = 1;
        ft_border_weight_from_right(game);
      }
    }
    if (game->border.right == 1 && ft_check_the_right(*game))
    {
      ft_desactivate_border(game);
      game->border.right = 0;
    }
  }
}
