#include "read_file.h"
void initiale(void)
{
    g_cub.texture.check = ft_strdup("NSsWE");
    g_cub.color = ft_strdup("FC");
    g_cub.player_check = 0;
}

char *ft_Repetition(char *tab, char c)
{
    char *new_tab;
    int j;
    int s;
    int i;
    
    i = 0;
    j = 0;
    s = 0;
    while (i < ft_strlen(tab) - 1 && tab[i] != c)
        i++;
    if (!tab || i > ft_strlen(tab) - 1)
        return (NULL);
    new_tab = malloc(sizeof(char) *ft_strlen(tab) - 1);
    while (j < ft_strlen(tab) - 1)
    {
        if (i == j)
            s++;
        new_tab[j] = tab[j + s];
        j++;
    }
    return (new_tab);
}

int ft_check_texture(char *tab)
{
    int i;

    i = 0;
    if ((ft_strncmp(tab, "S", 3) == 0))
            tab = ft_strdup("s");
    if ((!ft_strchr(g_cub.texture.check, tab[i]) || !g_cub.texture.check))
        return (-1);
    g_cub.texture.check = ft_Repetition(g_cub.texture.check, tab[i]);
    return (0);
}
int ft_check_color(char *tab)
{
    int i;

    i = 0;
    if ((!ft_strchr(g_cub.color, tab[i]) || !g_cub.color))
        return (-1);
    g_cub.color = ft_Repetition(g_cub.color, tab[i]);
    return (0);
}