/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndidenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:19:06 by ndidenko          #+#    #+#             */
/*   Updated: 2018/06/12 15:19:07 by ndidenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

void		ft_free_map(t_data *data)
{
	int		h;
	char	*str;

	if (!data->map)
		return ;
	h = 0;
	while (h < data->m_height)
	{
		str = data->map[h];
		ft_strdel(&str);
		h++;
	}
	ft_memdel((void **)&data->map);
}

void		ft_free_token(t_data *data)
{
	int		h;
	char	*str;

	if (!data->token)
		return ;
	h = 0;
	while (h < data->t_height)
	{
		str = data->token[h];
		ft_strdel(&str);
		h++;
	}
	ft_memdel((void **)&data->token);
}
