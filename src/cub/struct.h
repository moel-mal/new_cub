#ifndef STRUCT_H
# define STRUCT_H

typedef struct  s_resulotion
{
	int 	x;
	int 	y;
	int 	check;
}               t_resolution;

typedef struct  s_texture
{
	char    *nord;
	char    *south;
	char    *west;
	char    *east;
	char    *sprite;
	char	*check;
}               t_texture;

typedef	struct	s_map
{
	int			check;
	char		**tab;
	int			height;
	int			width;
	int			tile_size;
}				t_map;

typedef	struct s_player
{
	int 		o;
	float 		x;
	float		y;
	double		angle;
}				t_player;

typedef struct s_key
{
	int 		up;
	int 		down;
	int 		left;
	int 		right;
	int 		esc;
}				t_key;

typedef	struct s_img
{
	void		*img;
	int			*data;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

struct  		s_cub
{
	t_resolution	resolution;
	t_texture		texture;
	t_player		player;
	t_img			img;
	void 			*mlx;
	void			*win;
	int				floor;
	int				ceiling;
	char			*color;
	int				player_check;
	t_map			map;
	t_key			key;
}               	g_cub;

#endif