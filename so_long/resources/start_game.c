/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:18:44 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/07 13:29:54 by aroca-pa         ###   ########.fr       */
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
        ft_mlx_perror(2); // Manejar errores si mlx_init falla

    // Crear una nueva ventana de MLX con dimensiones 500x300 y título "So_Long"
    mlx_win = mlx_new_window(mlx, map->cols * map->render->resolution, map->rows * map->render->resolution, "So_Long");
    if (!mlx_win)
        ft_mlx_perror(3); // Manejar errores si mlx_new_window falla
    
    // Asignar los valores de mlx y mlx_win a la estructura de renderizado
    map->render->mlx = mlx;
    map->render->mlx_win = mlx_win;
    
    // Llamar a la función para renderizar sprites
    render_sprites(map);
    
    render_map(map);
    printf("%s", "ESTOY AQUI\n");
    
    conect_hook(map);
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
        perror("Error cargando la textura de fondo.\n");
    map->img->collectibles = mlx_xpm_file_to_image(map->render->mlx, "textures/collectibles.xpm", &img_size, &img_size);
    if (!map->img->collectibles)
        perror("Error cargando la texturas de coleccionables.\n");
    map->img->exit = mlx_xpm_file_to_image(map->render->mlx, "textures/exit.xpm", &img_size, &img_size);
    if (!map->img->exit)
        perror("Error cargando la textura de la exit.\n");
    map->img->player = mlx_xpm_file_to_image(map->render->mlx, "textures/player.xpm", &img_size, &img_size);
    if (!map->img->player)
        perror("Error cargando la textura de player.\n");
    map->img->wall = mlx_xpm_file_to_image(map->render->mlx, "textures/wall.xpm", &img_size, &img_size);
    if (!map->img->wall)
        perror("Error cargando la textura de paredes.\n");
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



