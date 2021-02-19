/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:52:49 by moel-mal          #+#    #+#             */
/*   Updated: 2021/02/19 18:06:58 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "game.h"

void	pixput(int x, int y, int color)
{
    //printf("okok");
	g_cub.img.data = (int *)mlx_get_data_addr(g_cub.img.img, &g_cub.img.bits_per_pixel,
			&g_cub.img.line_length, &g_cub.img.endian);
	if (x < g_cub.resolution.x && y < g_cub.resolution.y && x >= 0 && y >= 0)
    {
        //printf(">/n");
        //printf("%d", g_cub.resolution.x);
        g_cub.img.data[(y * g_cub.resolution.x) + x] = color;
    }
}

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
    while (angle < M_PI * 2)
    {
        ft_draw_ray(x, y, size, angle);
        angle = angle + c;
    }
}

void    ft_draw_rect(int x, int y, int heigh, int width)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < heigh)
    {
        i = 0;
        while (i < width)
        {
            pixput(x + i, y + j, ft_get_texture_1(x + i, y + j));
            //mlx_pixel_put(g_cub.mlx, g_cub.win, x + i, y + j, 0xC0C0C0);
            i++;
        }
        j++;
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
            pixput(x + i, y + j, 0xC0C0C0);
            //mlx_pixel_put(g_cub.mlx, g_cub.win, x + i, y + j, 200);
            i++;
        }
        j++;
    }
}
