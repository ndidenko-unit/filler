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
	data.minh = 0;
	data.minw = 0;
	data.resh = 0;
	data.resw = 0;
	data.manhattan = 1234567890;
	data.min = 1234567890;
	return(data);
}

static void ft_player(t_data *data)
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

static void ft_parsmap(t_data *data)
{
	int h;

	h = 0;
	data->m_height = ft_atoi(&data->line[8]);
	data->m_width = ft_atoi(&data->line[11]) + 5;
	data->map = (char**)malloc(sizeof(char*) * (data->m_height + 1));
	get_next_line(data->fd, &data->line);
	while (h < data->m_height)
	{
		get_next_line(data->fd, &data->line);
		data->map[h] = ft_strjoin(ft_strsub(data->line, 4, data->m_width), "~~~~~");
		h++;
	}
	data->map[h] = 0;
}

static void ft_parstoken(t_data *data)
{
	int h;

	h = 0;
	get_next_line(data->fd, &data->line);
	data->t_height = ft_atoi(&data->line[6]);
	data->t_width = ft_atoi(&data->line[8]);
	data->token = (char**)malloc(sizeof(char*) * (data->t_height + 1));
	while (h < data->t_height)
	{
		get_next_line(data->fd, &data->line);
		data->token[h] = ft_strsub(data->line, 0, data->t_width);
		h++;
	}
	data->token[h] = 0;
}

// static void ft_printmap(t_data *data)
// {
// 	int h;
// 	int w;

// 	h = 0;
// 	w = 0;
// 	while (h < data->m_height)
// 	{
// 		printf("%d ", (int)data->map[h][w]);
// 		if (w < data->m_width)
// 			w++;
// 		else
// 		{
// 			w = 0;
// 			h++;
// 			printf("\n");
// 		}
// 	}
// }

// int main(int argc, char **argv)
int main()
{
	t_data data;
	// int i = 0;
	
	data = ft_init();
	// data.fd = open(argv[1], O_RDONLY, 0);
	get_next_line(data.fd, &data.line);
	ft_player(&data);
	while(get_next_line(data.fd, &data.line))
	{
		//write(2, &data.line, 10);
		ft_parsmap(&data);

		ft_parstoken(&data);
		ft_manhattan(&data);
		// ft_printmap(&data);
		ft_printcoord(&data);
	}

	
	// while (i < 15)
	// {
	// 	printf("%s\n", data.map[i]);
	// 	i++;
	// }
	
	
	return(0);

}

    // char *line;
    // int  fd;
    // int  i;
	// int j = argc;
	// j++;

    // i = 0;
    // fd = open(argv[1], O_RDONLY, 0);
	// i = get_next_line(fd, &line);
	// printf("%d\n", i);
	// printf("fd is %d\n", fd);
    // while (get_next_line(fd, &line) > 0)
    // {
	// 	printf("line[%i]: |%s|\n", i, line);
	// 	//ft_putendl(line);
	// 	//ft_putstr(line);
	// 	ft_strdel(&line);
	// 	i++;
    // }
	// close(fd);
    // return (0);