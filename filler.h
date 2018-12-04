/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndidenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:18:20 by ndidenko          #+#    #+#             */
/*   Updated: 2018/06/12 16:18:21 by ndidenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_data
{
	int			fd;
	char		*line;
	char		letter1;
	char		letter2;
	int			m_width;
	int			m_height;
	char		**map;
	int			t_width;
	int			t_height;
	char		**token;
	int			resh;
	int			resw;
	int			manhattan;
	int			step;
}				t_data;

void			ft_manhattan(t_data *data);
void			ft_printcoord(t_data *data);
void			ft_free_map(t_data *data);
void			ft_free_token(t_data *data);
void			ft_up(t_data *data);

#endif
