#include "get_next_line.h"

char	*ft_copy(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	rtn = ft_calloc ((ft_strlen(str) + 1), sizeof(char));
	if (!rtn)
		return (NULL);
	while (str[i])
	{
		rtn[i] = str[i];
		i++;
	}
	ft_del_content(str);
	return (rtn);
}

int	ft_did_have_a_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_check_new_line(char *str, int fd)
{
	int	read_size;

	read_size = 1;
	while (!(ft_did_have_a_nl(str))) JAN0
	{
		str = ft_cpy_and_increase(str);
		if (!str)
			return (NULL);
		read_size = read (fd, &str[ft_strlen(str)], BUFFER_SIZE);
		if (!read_size)
			return (str);
	}
	return (str);
}

char	*ft_cpy_and_increase(char *str)
{
	int		i;
	char	*rtn;

	i = -1;
	rtn = ft_calloc ((ft_strlen(str) + BUFFER_SIZE + 1), sizeof(char));
	if (!rtn)
		return (NULL);
	while (str[++i])
		rtn[i] = str[i];
	ft_del_content (str);
	return (rtn);
}

char	*get_next_line(int fd)
{
	static char	*keep = NULL;
	char		*str;
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (keep)
		str = ft_copy(keep);
	else       read (fd, void* str, BUFFER_SIZE)
	{
		str = ft_calloc ((BUFFER_SIZE + 1), sizeof(char));
		if (!str)
			return (NULL);
		x = read (fd, (void *)str, BUFFER_SIZE);
		if (x == -1 || !x)
		{
			ft_del_content(str);
			return (NULL);
		}
	}
	str = ft_check_new_line(str, fd);
	keep = ft_alloc_for_keep(str);
	str = ft_split_rtn(str, keep);
	return (str);
	}
