/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mal <moel-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:52:13 by moel-mal          #+#    #+#             */
/*   Updated: 2021/02/19 19:04:21 by moel-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		on_keypress(int key)
{
	if (key == 13)
		g_cub.key.up = 1;
	if (key == 1)
		g_cub.key.down = 1;
	if (key == 0)
		g_cub.key.left = 1;
	if (key == 2)
		g_cub.key.right = 1;
	if (key == 53)
		g_cub.key.esc = 1;
	return (0);
}

int ft_detect_wall_colision(int x, int y)
{
    int a;
    int b;

    a = x / g_cub.map.tile_size;
    b = y / g_cub.map.tile_size;
    if (g_cub.map.tab[b][a] == '1')
        return (0);
    else
        return (1);
}

int		on_keyup(int key)
{
	if (key == 13)
		g_cub.key.up = 0;
	if (key == 1)
		g_cub.key.down = 0;
	if (key == 0)
		g_cub.key.left = 0;
	if (key == 2)
		g_cub.key.right = 0;
	if (key == 53)
		g_cub.key.esc = 0;
	return (0);
}

int deal_key(int key, void *prm)
{
    mlx_destroy_image ( g_cub.mlx, g_cub.img.img);
     g_cub.img.img = mlx_new_image(g_cub.mlx, g_cub.resolution.x, g_cub.resolution.y);
    ft_move_player();
    
   
//game_2D();
    game_3D();
    mlx_put_image_to_window(g_cub.mlx, g_cub.win, g_cub.img.img, 0, 0);
   
    return(0);
}

void ft_move_player(void)
{
    double p;
    float x;
    float y;

    p = M_PI_4 / 8;
    if (g_cub.key.up){
        y = g_cub.player.y + (sin(g_cub.player.angle) * 2);
        x = g_cub.player.x + (cos(g_cub.player.angle) * 2);
        if (ft_detect_wall_colision(x, y))
        {
            g_cub.player.y = y;
            g_cub.player.x = x;
        }
    }
    if (g_cub.key.down)
    {
        y = g_cub.player.y - sin(g_cub.player.angle) * 2;
        x = g_cub.player.x - cos(g_cub.player.angle) * 2;
        if (ft_detect_wall_colision(x, y))
        {
            g_cub.player.y = y;
            g_cub.player.x = x;
        }
    }
    if (g_cub.key.right)
    {
        g_cub.player.angle +=  p;
        if (g_cub.player.angle > (2 * M_PI))
            g_cub.player.angle -= (2 * M_PI);
    }
     if (g_cub.key.left)
    {
        g_cub.player.angle -= p;
        if (g_cub.player.angle < 0)
            g_cub.player.angle += (2 * M_PI);
    }
}