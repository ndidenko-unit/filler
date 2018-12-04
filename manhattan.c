/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manhattan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndidenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:14:03 by ndidenko          #+#    #+#             */
/*   Updated: 2018/06/07 17:14:05 by ndidenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

static int		ft_abs(int x)
{
	return (x < 0 ? (-1 * x) : x);
}

static void		printnum1(t_data *data, int h, int w, int enemy_h)
{
	if (ft_abs(h - enemy_h) < data->map[h][w])
		data->map[h][w] = ft_abs(h - enemy_h);
}

static void		printnum2(t_data *data, int h, int w, int enemy_w)
{
	if (ft_abs(w - enemy_w) < data->map[h][w])
		data->map[h][w] = ft_abs(w - enemy_w);
}

static void		ft_numbers(t_data *data, int enemy_h, int enemy_w)
{
	int h;
	int w;

	h = 0;
	w = 0;
	while (h < data->m_height)
	{
		if (data->map[h][w] != data->letter1 &&
			data->map[h][w] != data->letter2 && data->map[h][w] != '~')
		{
			if (ft_abs(h - enemy_h) > ft_abs(w - enemy_w))
				printnum1(data, h, w, enemy_h);
			else
				printnum2(data, h, w, enemy_w);
		}
		if (w < data->m_width)
			w++;
		else
		{
			w = 0;
			h++;
		}
	}
}

void			ft_manhattan(t_data *data)
{
	int h;
	int w;

	h = 0;
	w = 0;
	while (h < data->m_height)
	{
		if (data->map[h][w] == data->letter2)
			ft_numbers(data, h, w);
		if (w < data->m_width)
			w++;
		else
		{
			w = 0;
			h++;
		}
	}
}
