/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:42:06 by moel-mal          #+#    #+#             */
/*   Updated: 2020/11/11 19:00:01 by moel-mal         ###   ########.fr       */
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

float ft_get_ray_size(int x, int y)
{
    float size;

   // size = (x - g_cub.player.x) / cos(angle);
    size = sqrt(pow(x - g_cub.player.x, 2) + pow(y - g_cub.player.y, 2));
    return (size);
}
int ft_tools(float x, float y, int a, int b)
{
    float i;
    float j;


    i = x / g_cub.map.tile_size;
    j = y / g_cub.map.tile_size;
    if (i == (float)a && j == (float)b)
        return (1);
    else 
        return (0);
}
int ft_is_there_a_wall(float x, float y, int i)
{
    int a;
    int b;
    
    if (g_wall.left == 1 && ft_tools(x, y, a, b) == 0 && i == 0 )
        x--;
    if (g_wall.down == 0 && ft_tools(x, y, a, b) == 0 && i == 1)
        y--;
    a = (int)(floor(x / (float)(g_cub.map.tile_size)));
    b = (int)(floor(y / (float)g_cub.map.tile_size));
    
    if (!(b < g_cub.map.height && b > 0 && a > 0 && a < g_cub.map.width))
        return (1);
    if (g_cub.map.tab[b][a] == '1')
        return (1);
    else
        return (0);
}

float ft_horizontale(double angle)
{
    float first_x;
    float first_y;
    float x_step;
    float y_step;
    
    ft_ray_facing(angle);
    first_y = floor((g_cub.player.y / g_cub.map.tile_size)) * g_cub.map.tile_size;
    if (g_wall.down == 1)
        first_y += g_cub.map.tile_size;
    first_x = g_cub.player.x + ((first_y - g_cub.player.y) / tan(angle));
    y_step = g_cub.map.tile_size;
    if (g_wall.down == 0)
        y_step *= -1;
    x_step = g_cub.map.tile_size / tan(angle);
    if ((g_wall.left == 1 && x_step > 0) || (g_wall.left == 0 && x_step < 0))
        x_step *= -1;
    
    while (ft_is_there_a_wall(first_x, first_y, 1) == 0)
    {
        first_x += x_step;
        first_y += y_step;
    }
    return(ft_get_ray_size(first_x, first_y));
}

float ft_verticale(double angle)
{
    int first_x;
    int first_y;
    int x_step;
    int y_step;
    
    first_x = floor((g_cub.player.x / g_cub.map.tile_size)) * g_cub.map.tile_size;
    if (g_wall.left == 0)
        first_x += g_cub.map.tile_size;
    first_y = g_cub.player.y + ((first_x - g_cub.player.x) * tan(angle));
    x_step = g_cub.map.tile_size;
    if (g_wall.left == 1)
        x_step *= -1;
    y_step = g_cub.map.tile_size * tan(angle);
    if ((g_wall.down == 0 && y_step > 0) || (g_wall.down == 1 && y_step < 0))
        y_step *= -1;
     
    while (ft_is_there_a_wall(first_x, first_y, 0) == 0)
    {
        first_x += x_step;
        first_y += y_step;
    }
    return(ft_get_ray_size(first_x, first_y));
}

float raycasting(double angle)
{
    float a;
    float b;
    ft_ray_facing(angle);
    a = ft_horizontale(angle);
    b = ft_verticale(angle);
    if (a < b)
        return (a);
  else 
       return (b);
}