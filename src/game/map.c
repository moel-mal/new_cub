/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:38:27 by moel-mal          #+#    #+#             */
/*   Updated: 2020/10/30 14:12:26 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "game.h"


int ft_check_wall(int i, int j)
{

    if (!g_cub.map.tab[j][i])
        return (-1);
    if (g_cub.map.tab[j][i] == '1')
        return(1);
    else
        return(0);
}

static int ft_tile_size()
{
    if (g_cub.map.height > g_cub.map.width)
        g_cub.map.tile_size = g_cub.resolution.y / g_cub.map.height;
    else
        g_cub.map.tile_size = g_cub.resolution.x / g_cub.map.width;
        return(g_cub.map.tile_size);
}

int ft_put_map(void)
{
    int i;
    int j;
    int r;
    
    j = 0;
    r = ft_tile_size();
    while (j < g_cub.map.height && g_cub.map.tab[j])
	{
		i = 0;
		while (i < g_cub.map.width && g_cub.map.tab[j][i])
		{
			if (ft_check_wall(i, j) == 1)
				ft_draw_cub(i * r, j * r, r);
            if (ft_strchr("NSEW", g_cub.map.tab[j][i]) && g_cub.player.o == 0)
                ft_select_player(i, j, r);
			i++;
		}
		j++;
	}
    return (0);
}