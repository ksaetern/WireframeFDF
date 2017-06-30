/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:16:43 by ksaetern          #+#    #+#             */
/*   Updated: 2017/04/27 16:16:45 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*ft_newsplit(char **s, int w)
{
	int		*map;
	int		j;

	j = 0;
	map = (int *)malloc(sizeof(int) * (w + 1));
	while (j < w)
	{
		map[j] = ft_atoi(&s[j][0]);
		j++;
	}
	return (map);
}

void	ft_zvalue(int fd, t_map *m)
{
	int		x;
	int		j;
	char	**coord;
	char	*line;

	x = 0;
	m->hmax = 0;
	m->hmin = 0;
	m->map = (int **)malloc(sizeof(int *) * (m->h + 1));
	while (ft_get_next_line(fd, &line))
	{
		coord = ft_strsplit(line, ' ');
		m->map[x] = ft_newsplit(coord, m->w);
		free(coord);
		free(line);
		j = 0;
		while (j < m->w)
		{
			m->hmax = m->map[x][j] > m->hmax ? m->map[x][j] : m->hmax;
			m->hmin = m->map[x][j] < m->hmin ? m->map[x][j] : m->hmin;
			j++;
		}
		x++;
	}
	close(fd);
}

int		ft_findw(char **coord)
{
	int		x;

	x = 0;
	while (coord[x])
		x++;
	return (x);
}

/* open my fd once to get my dimenions for my int array malloc and.... to get dimenions */
void	ft_findwh(int fd, t_map *list)
{
	char	*line;
	char	**coord;
	int		y;

	y = 0;
	if (ft_get_next_line(fd, &line))
	{
		y++;
		coord = ft_strsplit(line, ' ');
		list->w = ft_findw(coord);
		free(coord);
		free(line);
	}
	while (ft_get_next_line(fd, &line))
	{
		y++;
		free(line);
	}
	list->h = y;
	close(fd);
}

void	ft_store(char *av, t_map *list)
{
	int		fd;

	if ((fd = open(av, O_RDONLY)) == -1)
		ft_error("Error Opening\n");
	ft_findwh(fd, list);
	fd = open(av, O_RDONLY);
	ft_zvalue(fd, list);
}
