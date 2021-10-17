/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 18:53:03 by janeway       #+#    #+#                 */
/*   Updated: 2021/10/15 19:12:46 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw(t_data *data, t_window img)
{
	int	i;

	i = 0;
	while (i < data->row)
	{
		draw_horizontal(data, i, img);
		i++;
	}
	i = 0;
	while (i < data->column)
	{
		draw_vertical(data, i, img);
		i++;
	}
}

static int	key_hook(int keycode)
{
	if (keycode == 53)
		exit (0);
	return (0);
}

void	render(t_data *data)
{
	void		*mlx;
	void		*mlx_win;
	t_window	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, data->width, data->height, "Hello FDF");
	img.img = mlx_new_image(mlx, data->width, data->height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_lenght, &img.endian);
	draw(data, img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_hook, &img);
	mlx_loop(mlx);
	mlx_destroy_image(mlx_win, img.img);
}
