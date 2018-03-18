#include "filler.h"

void	ft_strat_adjustment(t_game *game)
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
