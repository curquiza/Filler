#include "filler.h"

int   ft_is_top_player(t_game game)
{
  if (game.player_position == 1)
    return (1);
  return (0);
}