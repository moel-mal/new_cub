/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:42:32 by moel-mal          #+#    #+#             */
/*   Updated: 2020/10/20 17:26:42 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"


int	ft_check_error_map_1(int i, int j)
{
	if (!ft_strchr("012NSEW ", g_cub.map.tab[j][i]))
		return (-1);
	if (ft_strchr("NSEW", g_cub.map.tab[j][i]))
	{
		if (g_cub.player_check == 1)
			return(-1);
		g_cub.player_check = 1;
	}
	if (i == 0 || j == 0 || j == g_cub.map.height - 1 ||
			i == ft_strlen(g_cub.map.tab[j]) - 1)
	{
		if (!(ft_strchr("1 ", g_cub.map.tab[j][i])))
			return (-1);
	}
	else if (ft_strchr("02NSEW", g_cub.map.tab[j][i]))
	{
		if (g_cub.map.tab[j][i - 1] == ' ' || g_cub.map.tab[j][i + 1] == ' ' ||
				g_cub.map.tab[j - 1][i] == ' ' ||
				g_cub.map.tab[j + 1][i] == ' ') 
			return (-1);
		if (!g_cub.map.tab[j][i - 1] || !g_cub.map.tab[j][i + 1] ||
		 !g_cub.map.tab[j - 1][i] || !g_cub.map.tab[j + 1][i])
			return (-1);
		return (0);
	}
	return (0);
}

int	ft_check_error_map(void)
{
	int i;
	int j;
	
	j = 0;
	while (j < g_cub.map.height && g_cub.map.tab[j])
	{
		i = 0;
		while (i < g_cub.map.width && g_cub.map.tab[j][i])
		{
			if (ft_check_error_map_1(i, j) == -1)
				return (-1);
			i++;
		}
		if (g_cub.map.width < i)
			g_cub.map.width = i;
		j++;
	}
	return (0);
}
