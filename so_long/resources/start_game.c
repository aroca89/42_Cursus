/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:18:44 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/04 21:19:33 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_42/libft.h"
#include  "../minilibx_opengl/mlx.h"
#include "../so_long.h"

t_render *window_init(t_map *map)
{
    // Inicializar las variables para la ventana y el contexto de MLX
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    if (!mlx)
        ft_mlx_perror(2); // Manejar errores si mlx_init falla

    // Crear una nueva ventana de MLX con dimensiones 500x300 y título "So_Long"
    mlx_win = mlx_new_window(mlx, 500, 300, "So_Long");
    if (!mlx_win)
        ft_mlx_perror(3); // Manejar errores si mlx_new_window falla
    
   
    
    
    // Reservar memoria para la estructura de renderizado
    t_render *render = (t_render *)ft_calloc(1, sizeof(t_render));
        if (!render)
            ft_lst_perror(MALLOC_ERROR, map); // Manejar errores de asignación de memoria
    
    // Asignar los valores de mlx y mlx_win a la estructura de renderizado
    render->mlx = mlx;
    render->mlx_win = mlx_win;

    // Llamar a la función para renderizar sprites
    render_sprites(render);
    
    
    // Iniciar el bucle principal de MLX
    mlx_loop(mlx);
    return render;
}

void render_sprites(t_render *render)
{
    int img_size;

    // Reservar memoria para la estructura de imágenes
    t_img *img = (t_img *)ft_calloc(1, sizeof(t_img));
    if (!img)
        ft_mlx_perror(4); // Manejar errores de asignación de memoria

    // Cargar las imágenes desde archivos XPM y asignarlas a la estructura de imágenes
    render->img->background = mlx_xpm_file_to_image(render->mlx, "textures/backgroun.xpm", &img_size, &img_size);
    render->img->collectibles = mlx_xpm_file_to_image(render->mlx, "textures/collectibles.xpm", &img_size, &img_size);
    render->img->exit = mlx_xpm_file_to_image(render->mlx, "textures/exit.xpm", &img_size, &img_size);
    render->img->exit = mlx_xpm_file_to_image(render->mlx, "textures/player.xpm", &img_size, &img_size);
    render->img->wall = mlx_xpm_file_to_image(render->mlx, "textures/wall.xpm", &img_size, &img_size);

    // Verificar si alguna imagen no se cargó correctamente y manejar el error
    if (!render->img->background || !render->img->collectibles || !render->img->exit \
     || !render->img->exit || !render->img->wall)
        ft_mlx_perror(5);
}

void read_map(t_map *map, t_render *render)
{
    int i;
    int j;
    //char    character;
    
    i = 0; 
    while (map->data[i])
    {
        j = 0;
        while(map->data[i][j] != '\0')
        {
            if(map->data[i][j] == '0')
                mlx_put_image_to_window(render->mlx, render->mlx_win, render->img->background, i, j);
            else if (map->data[i][j] == '1')
                mlx_put_image_to_window(render->mlx, render->mlx_win,render->img->wall, i, j);
        
            j++;
        }
         i++; 
    }

}



