#include "filler.h"

int   ft_border_is_activate(t_game game)
{
  if (game.coef_border == 1)
    return (1);
  return (0);
}

int   ft_heat_is_activate(t_game game)
{
  if (game.coef_heat == 1)
    return (1);
  return (0);
}

void  ft_activate_heat(t_game *game)
{
  game->coef_heat = 1.0;
  game->coef_border = 0;
}

void  ft_activate_border(t_game *game)
{
  game->coef_heat = 0;
  game->coef_border = 1.0;
}

void  ft_desactivate_border(t_game *game)
{
  ft_activate_heat(game);
  ft_clear_border_weight(game);
}

int   ft_is_top_player(t_game game)
{
  if (game.player_position == 1)
    return (1);
  return (0);
}