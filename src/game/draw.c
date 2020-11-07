/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:52:49 by moel-mal          #+#    #+#             */
/*   Updated: 2020/11/02 17:28:11 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "game.h"

void ft_draw_ray(int x, int y, int size, double angle)
{
    int i;
    int a;
    int b;

    i = 0;
    while (i < size)
    {
        a = x + (cos(angle) * i);
        b = y + (sin(angle) * i);
        mlx_pixel_put(g_cub.mlx, g_cub.win, a, b, 16711680);
        i++;
    }
}
        

void    ft_draw_cercle(int x, int y, int size)
{
    double angle;
    double c;

    angle = 0;
    c =  M_PI * 2 / 360;
    while (angle < M_PI *2)
    {
        ft_draw_ray(x,y,size, angle);
        angle = angle + c;
    }
}

void    ft_draw_cub(int x, int y, int size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < size)
    {
        i = 0;
        while (i < size)
        {
            mlx_pixel_put(g_cub.mlx, g_cub.win, x + i, y + j, 200);
            i++;
        } 
        j++;
    }
}