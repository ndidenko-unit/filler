/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndidenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:12:14 by ndidenko          #+#    #+#             */
/*   Updated: 2018/06/08 15:12:15 by ndidenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

static int ft_place(t_data *data, int map_h, int map_w)
{
	int h;
	int w;
	int count;

	count = 0;
	h = 0;
	w = 0;
	while (h < data->t_height)
	{
		if (data->token[h][w] == '*' && map_h + h < data->m_height && map_w + w < data->m_width)
		{
			if(data->map[map_h + h][map_w + w] == data->letter1)
				count++;
			if (data->map[map_h + h][map_w + w] == data->letter2 || 
				data->map[map_h + h][map_w + w] == '~' || count == 2)
				return(0);
		}
		if (w < data->t_width)
			w++;
		else
		{
			w = 0;
			h++;
		}
	} 
	return(count);
}

static void ft_bestplace(t_data *data, int map_h, int map_w)
{
	int h;
	int w;

	h = 0;
	w = 0;

	while (h < data->t_height)
	{
		if (data->token[h][w] == '*' && data->map[h + map_h][w + map_w] <= data->manhattan)
		{
			data->manhattan = data->map[h + map_h][w + map_w];
			data->resh = map_h;
			data->resw = map_w;
			// printf("\nreshw %d %d||manhattan = %d||\n", data->resh, data->resw, data->manhattan);
		}
		if (w < data->t_width)
			w++;
		else
		{
			w = 0;
			h++;
		}
	}
}

void ft_printcoord(t_data *data)
{
	int h;
	int w;

	h = 0;
	w = 0;
	data->manhattan = 1234567890;
	while (h < data->m_height)
	{
		// if (data->map[h][w] != data->letter1 && data->map[h][w] != data->letter2)
		if (h + data->t_height < data->m_height && w + data->t_width < data->m_width)
		{
			if (ft_place(data, h, w) == 1)
			{
				// printf("valid coord is %d %d\n", h, w);
				ft_bestplace(data, h, w);
			}

		}
		if (w < data->m_width)
			w++;
		else
		{
			w = 0;
			h++;
		}
	}
	ft_putnbr(data->resh);
	write(1, " ", 1);
	ft_putnbr(data->resw);
	write(1, "\n", 1);
	// printf("%s\n", data->line);
}