#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_copy(char *str);
void	ft_del_content(char *str);
char	*ft_check_new_line(char *str, int fd);
int		ft_did_have_a_nl(char *str);
char	*ft_cpy_and_increase(char *str);
int		ft_strlen(char *s);
char	*ft_alloc_for_keep(char *str);
char	*ft_split_rtn(char *str, char *keep);
char	*ft_calloc(int count, int size);

#endif
