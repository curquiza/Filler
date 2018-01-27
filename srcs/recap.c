#include "filler.h"

void	ft_put_stratmap_coord(t_game game, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (i < game.h_map)
	{
		j = 0;
		while (j < game.w_map)
		{
			ft_putnbr_fd(game.strat_map[i][j].x, fd);
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(game.strat_map[i][j].y, fd);
			ft_putchar_fd(' ', fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}

void	ft_put_stratmap_value(t_game game, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (i < game.h_map)
	{
		j = 0;
		while (j < game.w_map)
		{
			ft_putchar_fd(game.strat_map[i][j].value, fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}

char	*ft_get_winner(void)
{
	char	*line;
	char	**split;
	char	*winner;
	int		input;

	input = open("filler.trace", O_RDONLY);
	if (input < 0)
		return (NULL);
	line = NULL;
	winner = ft_strdup("");
	if (get_next_line(input, &line) == -1)
		return (NULL);
	ft_strdel(&line);
	if (get_next_line(input, &line) == -1)
		return (NULL);
	split = ft_strsplit(line, ' ');
	if (split)
		winner = ft_strdup(split[0]);
	ft_strdel(&line);
	ft_tabdel(&split);
	return (winner);
}

void	ft_put_winner(char *winner, int fd)
{
	char	*tmp;
	ft_putstr_fd("The winner is.... ", fd);
	if (winner)
	{
		if ((tmp = ft_strrchr(winner, '/')))
			ft_putstr_fd(tmp + 1, fd);
		else
			ft_putstr_fd(winner, fd);
		ft_putendl_fd("", fd);
	}
}

void	ft_put_score(int fd)
{
	int		input;
	char 	*line;
	char	**split;

	input = open("filler.trace", O_RDONLY);
	if (input < 0)
		return ;
	line = NULL;
	if (get_next_line(input, &line) == -1)
		return ;
	ft_strdel(&line);
	if (get_next_line(input, &line) == -1)
		return ;
	split = ft_strsplit(line, 'T');
	if (split)
	{
		ft_putstr_fd("O -> ", fd);
		ft_putnbr_fd(ft_atoi(split[0]), fd);
		ft_putstr_fd("\nX -> ", fd);
		ft_putendl_fd(split[1], fd);
	}
	ft_strdel(&line);
	ft_tabdel(&split);
}

void	ft_put_recap(t_game game)
{
	int		fd;
	char	*winner;

	fd = open("recap", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		return ;
	ft_putstr_fd("my_coin : ", fd);
	ft_putchar_fd(game.my_coin, fd);
	ft_putendl_fd("", fd);
	ft_putstr_fd("opp_coin : ", fd);
	ft_putchar_fd(game.opp_coin, fd);
	ft_putendl_fd("", fd);
	ft_putstr_fd("h_map : ", fd);
	ft_putnbr_fd(game.h_map, fd);
	ft_putendl_fd("", fd);
	ft_putstr_fd("w_map : ", fd);
	ft_putnbr_fd(game.w_map, fd);
	ft_putendl_fd("", fd);
	winner = ft_get_winner();
	ft_putendl_fd("\nSCORE:", fd);
	ft_put_score(fd);
	ft_put_winner(winner, fd);
	//ft_putendl_fd("GROSS_MAP : ", fd);
	//ft_putstr_fd(game.gross_map, fd);
	//ft_putstr_fd("h_piece : ", fd);
	//ft_putnbr_fd(game.h_piece, fd);
	//ft_putendl_fd("", fd);
	//ft_putstr_fd("w_piece : ", fd);
	//ft_putnbr_fd(game.w_piece, fd);
	//ft_putendl_fd("", fd);
	//ft_putendl_fd("PIECE : ", fd);
	//ft_putstr_fd(game.piece, fd);
	//ft_putendl_fd("STRAT MAP VALUE: ", fd);
	//ft_put_stratmap_value(game, fd);
	//ft_putendl_fd("STRAT MAP X-Y: ", fd);
	//ft_put_stratmap_coord(game, fd);
	ft_strdel(&winner);
	close(fd);
}
