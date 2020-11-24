/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:43:27 by moel-mal          #+#    #+#             */
/*   Updated: 2020/11/24 20:21:47 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "game.h"


void ft_draw_screen(float angle, int i, int width_rec)
{
    float plyr_to_screen;
    float wall_size;
    
    plyr_to_screen = (g_cub.resolution.x /2) * (tan(M_PI / 6));
    wall_size = (g_cub.map.tile_size / raycasting(angle)) * plyr_to_screen;
    ft_draw_rect(i * width_rec, 
                (g_cub.resolution.y /2) - (wall_size /2),
                wall_size,
                width_rec);  
}

void game_3D(void)
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
       // ft_draw_ray(g_cub.player.x, g_cub.player.y,raycasting(j), j);
        ft_draw_screen(j, i, (g_cub.resolution.x / n_ray));
        j = j + angle;
        j = ft_0_to_2pi(j);
        i++;
    }
}