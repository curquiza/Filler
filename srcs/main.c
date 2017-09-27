#include "libft.h"
#include <fcntl.h>

int		main(void)
{
	//char	*line;
	char	line[10001];
	int		fd;

	//get_next_line(0, &line);
	ft_bzero(line, 10001);
	read(0, line, 10000);
	fd = open("debug", O_RDWR | O_CREAT | O_APPEND, 0666);
	ft_putendl_fd("--- NOUVELLE LECTURE ---", fd);
	ft_putendl_fd(line, fd);
	ft_putendl("8 2");
	//sleep(2);
	ft_putendl_fd("--- NOUVELLE LECTURE ---", fd);
	ft_bzero(line, 10001);
	//ft_putnbr_fd(read(0, line, 10000), fd);
	read(0, line, 10000);
	ft_putendl_fd(line, fd);
	//sleep(2);
	//ft_putendl("8 2");
	close (fd);
	return (0);
}
