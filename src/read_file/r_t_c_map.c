/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_t_c_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 11:38:33 by moel-mal          #+#    #+#             */
/*   Updated: 2020/12/07 18:07:44 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int	ft_get_map(char *line, char **tmp)
{
	if (!*tmp)
		*tmp = ft_strdup("");
	if (g_cub.map.width < ft_strlen(line))
		g_cub.map.width = ft_strlen(line);
	*tmp = ft_strjoin(*tmp, line);
	*tmp = ft_strjoin(*tmp, "*");
	g_cub.map.height++;
	g_cub.map.check = 1;
	return (0);
}

int	ft_get_color(char **info)
{
	int		r;
	int		g;
	int		b;
	char	**tab;

	if (ft_check_color(info[0]) == -1)
		return(-1);
	tab = ft_split(info[1], ',');
	if (ft_calcule_2d_tab(tab) != 3)
	{
		// free_2d(tab);
		return(-1);
	}
	r = ft_atoi(tab[0]);
	g = ft_atoi(tab[1]);
	b = ft_atoi(tab[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b > 255 || b < 0)
	{
		// free_2d(tab);
		return (-1);
	}
	if (ft_strncmp(info[0], "F", 3) == 0)
		g_cub.floor = r * pow(256, 2) + g * 256 + b;
	else if (ft_strncmp(info[0], "C", 3) == 0)
		g_cub.ceiling = r * pow(256, 2) + g * 256 + b;
	// free_2d(tab);
	return (0);
}

int	ft_get_texture(char **info)
{
	if (ft_check_texture(info[0]) == -1)
		return(-1);
	if ((ft_strncmp(info[0], "NO", 3) == 0) &&
	(ft_calcule_2d_tab(info) == 2))
		g_cub.texture.nord = ft_strdup(info[1]);
	else if ((ft_strncmp(info[0], "SO", 3) == 0) &&
	(ft_calcule_2d_tab(info) == 2))
		g_cub.texture.south = ft_strdup(info[1]);
	else if ((ft_strncmp(info[0], "WE", 3) == 0 &&
	(ft_calcule_2d_tab(info) == 2)))
		g_cub.texture.west = ft_strdup(info[1]);
	else if ((ft_strncmp(info[0], "EA", 3) == 0 &&
	(ft_calcule_2d_tab(info) == 2)))
		g_cub.texture.east = ft_strdup(info[1]);
	else if ((ft_strncmp(info[0], "S", 3) == 0 &&
	(ft_calcule_2d_tab(info) == 2)))
		g_cub.texture.sprite = ft_strdup(info[1]);
	else
		return (-1);
	return (0);
}

int	ft_get_resolution(char **info)
{
	int i;

	if (ft_calcule_2d_tab(info) != 3)
		return (-1);
	i = ft_atoi(info[1]);
	if (i > 5120)
		i = 5120;
	if (i > 0)
		g_cub.resolution.x = i;
	else
		return (-1);
	i = ft_atoi(info[2]);
	if (i > 2880)
		i = 2880;
	if (i > 0)
		g_cub.resolution.y = i;
	else
		return (-1);
	return (0);
}
