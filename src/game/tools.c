/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 18:32:53 by moel-mal          #+#    #+#             */
/*   Updated: 2020/11/11 17:23:58 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static double ft_0_to_2pi(double angle)
{
    if (angle < 0)
        angle = angle + (M_PI * 2);
    else if (angle >  (M_PI * 2))
        angle = angle - (M_PI * 2);
    return (angle);
}

void    ft_draw_feld_view()
{
    int i;
    int n_ray;
    double angle;
    double j;
    
    j = 0;
    i = 0;
    n_ray = g_cub.resolution.x / (M_PI / 3);
    angle = (M_PI / 3) / n_ray;
    j = g_cub.player.angle - (M_PI / 6);
    while (i < n_ray)
    {
        ft_draw_ray(g_cub.player.x, g_cub.player.y,raycasting(j), j);
        j = j + angle;
        j = ft_0_to_2pi(j);
        i++;
    }
}

void    ft_select_player(int x, int y, int r)
{
    if (g_cub.map.tab[y][x] == 'N')
        g_cub.player.angle = (3 * M_PI_2);
    else if (g_cub.map.tab[y][x] == 'S')
        g_cub.player.angle = (M_PI_2);
    else if (g_cub.map.tab[y][x] == 'E')
        g_cub.player.angle = (0);
    else if (g_cub.map.tab[y][x] == 'W')
        g_cub.player.angle = (M_PI);
    g_cub.player.x = r * x + (r / 2);
    g_cub.player.y = r * y + (r / 2);
    g_cub.player.o = 1;
}

void ft_put_player()
{   
    ft_draw_cercle(g_cub.player.x, g_cub.player.y, (g_cub.map.tile_size / 8));
    ft_draw_feld_view();
    ft_draw_ray(g_cub.player.x, g_cub.player.y,raycasting(g_cub.player.angle), g_cub.player.angle);
}