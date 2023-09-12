/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:18:44 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/12 19:51:36 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_42/libft.h"
#include  "../minilibx_opengl/mlx.h"
#include "../so_long.h"

void window_init(t_map *map)
{
    // Inicializar las variables para la ventana y el contexto de MLX
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    if (!mlx)
        ft_mlx_perror(1, map); // Manejar errores si mlx_init falla

    // Crear una nueva ventana de MLX con dimensiones y título
    mlx_win = mlx_new_window(mlx, map->cols * map->render->resolution, map->rows * map->render->resolution, "So_Long");
    if (!mlx_win)
        ft_mlx_perror(1, map); // Manejar errores si mlx_new_window falla

    // Asignar los valores de mlx y mlx_win a la estructura de renderizado
    map->render->mlx = mlx;
    map->render->mlx_win = mlx_win;

    // Llamar a la función para renderizar sprites
    render_sprites(map);

    // Renderizar el mapa inicial
    render_map(map);

    // Configurar el manejo de eventos de teclado
    mlx_key_hook(map->render->mlx_win, key_hook, map);
    mlx_hook(map->render->mlx_win, 17, 0, (void *)exit, map);

    // Iniciar el bucle principal de MLX
    mlx_loop(mlx);

    return;
}


void render_sprites(t_map *map)
{
    int img_size;
    

    // Cargar las imágenes desde archivos XPM y asignarlas a la estructura de imágenes
    map->img->background = mlx_xpm_file_to_image(map->render->mlx, "textures/backgroun.xpm", &img_size, &img_size);
    if (!map->img->background)
        ft_mlx_perror(4, map);
    map->img->collectibles = mlx_xpm_file_to_image(map->render->mlx, "textures/collectibles.xpm", &img_size, &img_size);
    if (!map->img->collectibles)
        ft_mlx_perror(5, map);
    map->img->exit = mlx_xpm_file_to_image(map->render->mlx, "textures/exit.xpm", &img_size, &img_size);
    if (!map->img->exit)
        ft_mlx_perror(6, map);
    map->img->player = mlx_xpm_file_to_image(map->render->mlx, "textures/player.xpm", &img_size, &img_size);
    if (!map->img->player)
        ft_mlx_perror(7, map);
    map->img->wall = mlx_xpm_file_to_image(map->render->mlx, "textures/wall.xpm", &img_size, &img_size);
    if (!map->img->wall)
        ft_mlx_perror(8, map);
}

void render_map(t_map *map)
{
    
    int y;
    int x;
    char    character;
    int     resolution;
    
    y = 0;    
    while (y < map->rows)
    {
        x = 0;
        
        while(x < map->cols)
        {
            character = map->data[y][x];
            //printf("Character at (%d, %d) is '%c'\n", y * resolution, x * resolution, character);
            resolution = map->render->resolution;
            mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->background, x * resolution, y * resolution);
            if (character == '1')
                mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->wall, x * resolution, y * resolution);
            else if (character == 'P')
                mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->player, x * resolution, y * resolution);
            else if (character == 'E')
               mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->exit, x * resolution, y * resolution);
            else if (character == 'C')
                mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->collectibles, x * resolution, y * resolution);
            x++;
        }
         y++; 
    }

}



