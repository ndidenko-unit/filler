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

static int ft_abs(int x)
{
    return(x < 0 ? (-1 * x) : x);
}

// static void ft_mincord(t_data *data, int enemy_h, int enemy_w)
// {
//     int my_h;
//     int my_w;

//     my_h = 0;
//     my_w = 0;
//     while (my_h < data->m_height)
//     {
//         if (data->map[my_h][my_w] == data->letter1)
//         {
//             if (ft_abs(my_h - enemy_h) + ft_abs(my_w - enemy_w) < data->min)
//             {
//                 data->min = ft_abs(my_h - enemy_h) + ft_abs(my_w - enemy_w);
//                 data->minh = enemy_h;
//                 data->minw = enemy_w;
//                 // printf("\nmin cord %d %d||min = %d||\n", data->minh, data->minw, data->min);
//             }
//         }
//         if (my_w < data->m_width)
//             my_w++;
//         else
//         {
//             my_w = 0;
//             my_h++;
//         }
//     }
// }

static void ft_numbers(t_data *data, int enemy_h, int enemy_w)
{
    int h;
    int w;

    h = 0;
    w = 0;
    while (h < data->m_height)
    {
        if (data->map[h][w] != data->letter1 && data->map[h][w] != data->letter2 && data->map[h][w] != '~')
        {
            if (ft_abs(h - enemy_h) > ft_abs(w - enemy_w))
            {
                if(ft_abs(h - enemy_h) < data->map[h][w])
                    data->map[h][w] = ft_abs(h - enemy_h);
            }
            else
            {
                if(ft_abs(w - enemy_w) < data->map[h][w])
                    data->map[h][w] = ft_abs(w - enemy_w);
            }
            // if (absres == data->letter1 || absres == data->letter2)
            //     absres += 1;
            // absres = ft_abs(h - data->minh) + ft_abs(w - data->minw);
            // data->map[h][w] = absres;
        }
        if (w < data->m_width)
            w++;
        else
        {
            w = 0;
            h++;
        }
    }
    // printf("datamap %d", (int)data->map[11][13]);
}

void ft_manhattan(t_data *data)
{
    int h;
    int w;

    h = 0;
    w = 0;
    data->min = 1234567890;
    while (h < data->m_height)
    {
        if (data->map[h][w] == data->letter2)
            // ft_mincord(data, h, w);
            ft_numbers(data, h, w);
        if (w < data->m_width)
            w++;
        else
        {
            w = 0;
            h++;
        }
    }
    // printf("min h %d, min w %d", data->minh, data->minw);
}