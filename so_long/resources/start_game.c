/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:18:44 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/03 18:56:29 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_42/libft.h"
#include  "../minilibx_opengl/mlx.h"
#include "../so_long.h"

void window_init(void *struct_map)
{
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    if (!mlx)
        ft_mlx_perror(2);
    mlx_win = mlx_new_window(mlx, 500, 300, "So_Long");
    if (!mlx_win)
        ft_mlx_perror(3);
    t_render *render = (t_render *)ft_calloc(1, sizeof(t_render));
    if (!render)
        ft_lst_perror(MALLOC_ERROR, (t_map *)struct_map);
    mlx_loop(mlx);
    
    render->mlx = mlx;
    render->mlx_win = mlx_win;
    render_sprites(render);
}

void render_sprites(t_render *render)
{
    int img_size;

    t_img *img = (t_img *)ft_calloc(1, sizeof(t_img));
    if (!img)
        ft_mlx_perror(4);
        
    render->img->background = mlx_xpm_file_to_image(render->mlx, "textures/backgroun.xpm", &img_size, &img_size);
    render->img->collectibles = mlx_xpm_file_to_image(render->mlx, "textures/collectibles.xpm", &img_size, &img_size);
    render->img->exit = mlx_xpm_file_to_image(render->mlx, "textures/exit.xpm", &img_size, &img_size);
    render->img->exit = mlx_xpm_file_to_image(render->mlx, "textures/player.xpm", &img_size, &img_size);
    render->img->wall = mlx_xpm_file_to_image(render->mlx, "textures/wall.xpm", &img_size, &img_size);
    if (!render->img->background || !render->img->collectibles || !render->img->exit \
     || !render->img->exit || !render->img->wall)
        ft_mlx_perror(5);
}