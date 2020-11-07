/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:42:06 by moel-mal          #+#    #+#             */
/*   Updated: 2020/11/07 00:52:21 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ft_ray_facing(double angle)
{
    if (angle < M_PI_2 || angle > (3 * M_PI_2))
        g_wall.left = 0;
    else 
        g_wall.left = 1;
    if (angle > 0 && angle < M_PI)
        g_wall.down = 1;
    else
        g_wall.down = 0;
}

int ft_get_ray_size(int x, int y)
{
    int size;

   // size = (x - g_cub.player.x) / cos(angle);
    size = sqrt(pow(x - g_cub.player.x, 2) + pow(y - g_cub.player.y, 2));
    return (size);
}

int ft_is_there_a_wall(int x, int y)
{
    if (g_wall.down == 0)
        y--;
    x = x / g_cub.map.tile_size;
    y = y / g_cub.map.tile_size;
    if (!(y < g_cub.map.height && y > 0 && x > 0 && x < g_cub.map.width))
        return (1);
    if (g_cub.map.tab[y][x] == '1')
        return (1);
    else
        return (0);
}

int ft_horizontale(double angle)
{
    int first_x;
    int first_y;
    int x_step;
    int y_step;
    
    ft_ray_facing(angle);
    first_y = (g_cub.player.y / g_cub.map.tile_size) * g_cub.map.tile_size;
    if (g_wall.down == 1)
        first_y += g_cub.map.tile_size;
    first_x = g_cub.player.x + ((first_y - g_cub.player.y) / tan(angle));
    y_step = g_cub.map.tile_size;
    if (g_wall.down == 0)
        y_step *= -1;
    printf("%f\n",tan(angle));
    x_step = g_cub.map.tile_size / tan(angle);
    if ((g_wall.left == 1 && x_step > 0) || (g_wall.left == 0 && x_step < 0))
        x_step *= -1;
    while (ft_is_there_a_wall(first_x, first_y) == 0)
    {
        first_x += x_step;
        first_y += y_step;
    }
    return(ft_get_ray_size(first_x, first_y));
}
int ft_vertical(double angle)
{
    return (50);
}
int raycasting(double angle)
{
    int a;
    int b;
    ft_ray_facing(angle);
    a = ft_horizontale(angle);
    //b = ft_vertical();
    //if (a < b)
        return (a);
  //  else 
      //  return (b);
}