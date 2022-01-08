#include "get_next_line.h"

char	*ft_calloc(int count, int size)
{
	char	*rtn;
	int		i;

	i = 0;
	rtn = (char *) malloc(count * size);
	if (rtn == NULL)
		return (NULL);
	while (i < (count * size))
	{
		rtn[i] = '\0';
		i++;
	}
	return (rtn);
}

char	*ft_alloc_for_keep(char *str)
{
	char	*rtn;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || (str[i] == '\n' && !str[i + 1]))
		rtn = ft_calloc ((ft_strlen(str) - i), sizeof(char));
	return (rtn);
}

int	ft_strlen(char *s)
{
	int	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

void	ft_del_content(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = 0;
	free (str);
}

char	*ft_split_rtn(char *str, char *keep)
{
	int		i;
	char	*rtn;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	rtn = ft_calloc ((i + 1), sizeof(char));
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = str[i];
	while (str[++i])
		keep[j++] = str[i];
	ft_del_content (str);
	return (rtn);
}
