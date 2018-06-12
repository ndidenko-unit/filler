#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_data
{
	int			fd;
	char        *line;
	char		letter1;
    char		letter2;
    int         m_width;
    int         m_height;
    char        **map;
    int         t_width;
    int         t_height;
    char        **token;
    int         minh;
    int         minw;
    int         resh;
    int         resw;
    int         manhattan;
    int         min;
}				t_data;

void ft_manhattan(t_data *data);
void ft_printcoord(t_data *data);

#endif
