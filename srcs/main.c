#include "filler.h"
#include <fcntl.h>

char 	*ft_get_data(void)
{
	//char	*line;
	char	line[11];
	char	*data;
	char	*tmp;
	int		ret;

	//line = ft_memalloc(4096);
	//read(0, line, 4065);
	//return (line);
	data = NULL;
	ft_bzero(line, 11);
	while ((ret = read(0, line, 10)) > 0)
	{
		ft_putnbr_fd(ret, 2);
		ft_putendl_fd("", 2);
		tmp = data;
		data = ft_strjoin(tmp, line);
		ft_strdel(&tmp);
		ft_bzero(line, 11);
	}
	return (data);
}

int		main(void)
{
	char	*data;
	int		fd;

	data = ft_get_data();
	fd = open("debug", O_RDWR | O_CREAT, 0666);
	ft_putendl_fd(data, fd);
	close(fd);
}

/*int		main(void)
{
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
	//close (fd);
	return (0);
}*/
