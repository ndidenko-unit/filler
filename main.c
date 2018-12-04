/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndidenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:00:44 by ndidenko          #+#    #+#             */
/*   Updated: 2018/06/06 14:00:46 by ndidenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

static t_data	ft_init(void)
{
	t_data data;

	data.fd = 0;
	data.line = 0;
	data.letter1 = 0;
	data.letter2 = 0;
	data.m_width = 0;
	data.m_height = 0;
	data.map = 0;
	data.t_width = 0;
	data.t_height = 0;
	data.token = 0;
	data.resh = 0;
	data.resw = 0;
	data.manhattan = 1234567890;
	data.step = 0;
	return (data);
}

static void		ft_player(t_data *data)
{
	if (data->line[10] == '1')
	{
		data->letter1 = 'O';
		data->letter2 = 'X';
	}
	else
	{
		data->letter1 = 'X';
		data->letter2 = 'O';
	}
}

static void		ft_parsmap(t_data *data)
{
	int		h;
	char	*tmp;

	h = 0;
	ft_free_map(data);
	data->m_height = ft_atoi(&data->line[8]);
	data->m_width = ft_atoi(&data->line[11]) + 10;
	data->map = (char**)malloc(sizeof(char*) * (data->m_height + 1));
	ft_strdel(&data->line);
	get_next_line(data->fd, &data->line);
	ft_strdel(&data->line);
	while (h < data->m_height)
	{
		get_next_line(data->fd, &data->line);
		tmp = ft_strsub(data->line, 4, data->m_width);
		data->map[h] = ft_strjoin(tmp, "~~~~~~~~~~");
		h++;
		ft_strdel(&data->line);
		ft_strdel(&tmp);
	}
	data->map[h] = 0;
}

static void		ft_parstoken(t_data *data)
{
	int h;

	h = 0;
	ft_free_token(data);
	get_next_line(data->fd, &data->line);
	data->t_height = ft_atoi(&data->line[6]);
	data->t_width = ft_atoi(&data->line[8]);
	data->token = (char**)malloc(sizeof(char*) * (data->t_height + 1));
	ft_strdel(&data->line);
	while (h < data->t_height)
	{
		get_next_line(data->fd, &data->line);
		data->token[h] = ft_strsub(data->line, 0, data->t_width);
		h++;
		ft_strdel(&data->line);
	}
	data->token[h] = 0;
}

int				main(void)
{
	t_data data;

	data = ft_init();
	get_next_line(data.fd, &data.line);
	ft_player(&data);
	ft_strdel(&data.line);
	while (get_next_line(data.fd, &data.line))
	{
		ft_parsmap(&data);
		ft_parstoken(&data);
		if (data.letter1 == 'X' && data.step < 12 && data.m_height < 20)
			ft_up(&data);
		else
			ft_manhattan(&data);
		ft_printcoord(&data);
		data.step++;
	}
	return (0);
}
