#ifndef READ_FILE_H
# define READ_FILE_H
# include "../cub/cub3d.h"


//r_t_c_map
int	ft_get_map(char *line, char **tmp);
int	ft_get_color(char **info);
int	ft_get_texture(char **info);
int	ft_get_resolution(char **info);

//read_from_file
int		ft_read_file(char *av);
int		ft_get_struct1(char *line);
int		ft_get_struct(char *line, char **tmp);
int	ft_get_texture(char **info);

//file
char *ft_hexa(char *tab);

//free
void free_2d(char **tab);

//error
int	ft_check_error_map_1(int i, int j);
int	ft_check_error_map(void);

//struct
int		ft_calcule_2d_tab(char **tab);

//check_repetetion
void initiale(void);
char *ft_Repetition(char *tab, char c);
int ft_check_texture(char *tab);
int ft_check_color(char *tab);


#endif