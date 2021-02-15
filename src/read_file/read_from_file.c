/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:13:48 by moel-mal          #+#    #+#             */
/*   Updated: 2021/01/28 07:44:32 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int		ft_get_struct1(char *line)
{
	char **info;
	int i;

	info = ft_split(line, ' ');
	if (ft_strncmp(info[0], "R", 2) == 0 )
	{
		if (g_cub.resolution.check == 0)
			i = ft_get_resolution(info);
		else
			return(-1);
		g_cub.resolution.check = 1;
	}
	else if ((ft_strncmp(info[0], "NO", 3) == 0) ||
		(ft_strncmp(info[0], "SO", 3) == 0) ||
		(ft_strncmp(info[0], "WE", 3) == 0) ||
		(ft_strncmp(info[0], "EA", 3) == 0) ||
		(ft_strncmp(info[0], "S", 3) == 0))
		i = ft_get_texture(info);
	else if (((ft_strncmp(info[0], "F", 3) == 0) ||
		(ft_strncmp(info[0], "C", 3) == 0)) &&
		ft_calcule_2d_tab(info) == 2)
		i = ft_get_color(info);
	else
		i = -1;
	//free_2d(info);
	return (i);
}

int		ft_get_struct(char *line, char **tmp)
{
	int		i;
	char	**info;

	i = 0;
	if (!line)
		return (0);
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (0);
	if (line[i] != '1' && g_cub.map.check == 0)
		return (ft_get_struct1(line));
	else if (line[i] == '1')
		return (ft_get_map(line, tmp));
	else
		return (-1);
	return (0);
}

int		ft_read_file(char *av)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		i;

	fd = open(av, O_RDWR);
	tmp = ft_strdup("");
	while ((i = get_next_line(fd, &line)))
	{
		if ((i == -1) || (ft_get_struct(line, &tmp) == -1))
		{
			printf("error in file");
			return (-1);
		}
	}
	g_cub.map.tab = ft_split(tmp, '*');
	free(tmp);
	if (ft_check_error_map() == -1)
	{
		printf("error in map");
		return (-1);
	}
	return (0);
}
