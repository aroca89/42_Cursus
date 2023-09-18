/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:18:44 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/18 18:08:31 by aroca-pa         ###   ########.fr       */
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
    //mlx_loop(mlx);

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
    char character;
    int resolution;

    y = 0;
    while (y < map->rows)
    {
        x = 0;
        while (x < map->cols)
        {
            character = map->data[y][x];
            resolution = map->render->resolution;

            // Calcula las coordenadas en las que se debe renderizar el elemento
            int render_x = x * resolution;
            int render_y = y * resolution;

            // Comprueba si el elemento está dentro de los límites de la ventana
            if (render_x >= 0 && render_x < map->render->window_width && render_y >= 0 && render_y < map->render->window_height)
            {
                // Renderiza el elemento solo si está dentro de la ventana

                // Primero, renderiza el fondo (background)
                mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->background, render_x, render_y);

                // Aquí puedes añadir lógica para renderizar otros elementos, como paredes, coleccionables, salida, jugador, etc.
                if (character == '1')
                    mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->wall, render_x, render_y);
                else if (character == 'C')
                    mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->collectibles, render_x, render_y);
                // Verifica si es la posición de la salida
                if (character == 'E')
                {
                    // Renderiza la salida en la posición actual
                    mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->exit, render_x, render_y);

                    // Verifica si también es la posición del jugador
                    if (map->character_position_col == x && map->character_position_row == y)
                    {
                        // Renderiza al jugador encima de la salida
                        mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->player, render_x, render_y);
                    }
                }

                // Renderiza al jugador si es 'P'
                if (character == 'P')
                {
                    mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->player, render_x, render_y);
                }

                // Puedes continuar aquí para renderizar otros elementos como coleccionables y paredes
            }

            x++;
        }
        y++;
    }
}


// void render_map(t_map *map)
// {
//     int render_x;       // Coordenada X en la ventana de renderización
//     int render_y;       // Coordenada Y en la ventana de renderización
//     char character;     // Carácter actual en los datos del mapa
//     int x;              // Índice de columna en los datos del mapa
//     int y;              // Índice de fila en los datos del mapa

//     // Calcula el punto de inicio para la renderización basado en la posición del jugador
//     int start_x = map->character_x - map->render->window_width / (2 * map->render->resolution);
//     int start_y = map->character_y - map->render->window_height / (2 * map->render->resolution);
	
//     // Asegura que las coordenadas de inicio no sean menores que 0
//     start_x = fmax(0, start_x);
//     start_y = fmax(0, start_y);

//     // Calcula el punto de finalización para la renderización
//     int end_x = start_x + map->render->window_width / map->render->resolution;
//     int end_y = start_y + map->render->window_height / map->render->resolution;

//     // Asegura que las coordenadas de finalización no superen los límites del mapa
//     end_x = fmin(map->cols, end_x);
//     end_y = fmin(map->rows, end_y);

//     // Bucle para iterar a través de las filas desde start_y hasta end_y
//     y = start_y;
//     while (y < end_y)
//     {
//         // Bucle para iterar a través de las columnas desde start_x hasta end_x
//         x = start_x;
//         while (x < end_x)
//         {
//             // Calcula las coordenadas de renderización en la ventana
//             render_x = (x - start_x) * map->render->resolution;
//             render_y = (y - start_y) * map->render->resolution;

//             // Verifica que las coordenadas estén dentro de los límites de la ventana
//             if (render_x >= 0 && render_x < map->render->window_width && render_y >= 0 && render_y < map->render->window_height)
//             {
//                 // Renderiza el fondo y el carácter en la posición actual
//                 mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->background, render_x, render_y);
//                 character = map->data[y][x];
//                 select_put_img(map, render_x, render_y, character);
//             }
//             x++;
//         }
//         y++;
//     }
// }



