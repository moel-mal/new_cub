/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:42:06 by moel-mal          #+#    #+#             */
/*   Updated: 2021/02/19 19:09:11 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void ft_ray_facing(double angle)
{
    if (angle > 0 && angle < M_PI)
        g_wall.down = 1;
    else 
        g_wall.down = 0;
    if (angle < M_PI_2 || angle > (M_PI_2 * 3))
        g_wall.right = 1;
    else
        g_wall.right = 0;
}

int ft_is_there_wall(float x, float y, int i)
{
    int a;
    int b;

    if (g_wall.down == 0 && i == 1)
        y--;
    if (g_wall.right == 0 && i == 0)
        x--;
    a = (int)floor(x) / g_cub.map.tile_size;
    b = (int)floor(y) / g_cub.map.tile_size;
    if (a < 0 || b < 0 || a >= g_cub.map.width || b >= g_cub.map.height)
        return (1);
    if (g_cub.map.tab[b][a] == '1')
        return (1);
    else 
        return (0);    
}

float   ft_horizontale(double angle)
{
    float first_x;
    float first_y;
    float x_step;
    float y_step;

    first_y = floor(g_cub.player.y / g_cub.map.tile_size) * g_cub.map.tile_size;
    if (g_wall.down == 1)
        first_y += g_cub.map.tile_size;
    first_x = g_cub.player.x + (first_y - g_cub.player.y) / tan(angle);
    y_step = g_cub.map.tile_size;
    if (g_wall.down == 0)
        y_step *= -1;
    x_step = g_cub.map.tile_size / tan(angle);
    if (g_wall.right == 0 && x_step > 0)
        x_step *= -1;
    if (g_wall.right == 1 && x_step < 0)
        x_step *= -1;

    while (first_x >= 0 && first_x <= g_cub.resolution.x && first_y >= 0 && first_y <= g_cub.resolution.y)
    {
        if (ft_is_there_wall(first_x, first_y, 1) == 1)
        {
           break;
        }
        else
        {
            first_y += y_step;
            first_x += x_step;
        } 
    }
    return (sqrtf(powf((g_cub.player.x - first_x), 2) + powf((g_cub.player.y - first_y), 2)));
}

float   ft_verticale(double angle)
{
    float first_x;
    float first_y;
    float x_step;
    float y_step;

    first_x = floor(g_cub.player.x / g_cub.map.tile_size) * g_cub.map.tile_size;
    if (g_wall.right == 1)
        first_x += g_cub.map.tile_size;
    first_y = g_cub.player.y + (first_x - g_cub.player.x) * tan(angle);
    
    x_step = g_cub.map.tile_size;
    if (g_wall.right == 0)
        x_step *= -1; 
    y_step = g_cub.map.tile_size * tan(angle);
    if (g_wall.down == 0 && y_step > 0)
        y_step *= -1;
    if (g_wall.down == 1 && y_step < 0)
        y_step *= -1;

    while (first_x >= 0 && first_x <= g_cub.resolution.x && first_y >= 0 && first_y <= g_cub.resolution.y)
    {
        if (ft_is_there_wall(first_x, first_y, 0) == 1)
           break; 
        else
        {
            first_y += y_step;
            first_x += x_step;
        } 
    }
    return (sqrtf(powf((g_cub.player.x - first_x), 2) + powf((g_cub.player.y - first_y), 2)));
}

float raycasting(double angle)
{
    float a;
    float b;
    
    ft_ray_facing(angle);
    a = ft_horizontale(angle);
    b = ft_verticale(angle);
    if (a < b)
    {
        g_wall.v = 0;
        return (a);
    }
    else
    { 
        g_wall.v = 1;
        return (b);
    }
}
