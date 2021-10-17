/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <cpopa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 14:28:07 by cpopa         #+#    #+#                 */
/*   Updated: 2021/10/17 17:16:24 by cpopa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	my_mlx_pixel_put(t_window *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	get_steps(t_data *data)
{
	int		dx;
	int		dy;

	dx = (int)data->array[2] - (int)data->array[0];
	dy = (int)data->array[3] - (int)data->array[1];
	if (ft_abs(dx) > ft_abs(dy))
		data->steps = ft_abs(dx);
	else
		data->steps = ft_abs(dy);
	data->x_next = dx / data->steps;
	data->y_next = dy / data->steps;
}

static void	draw_line(t_window img, int color, t_data *data)
{
	int		i;
	float	x;
	float	y;

	get_steps(data);
	i = 0;
	x = data->array[0];
	y = data->array[1];
	while (i < data->steps)
	{
		x = x + data->x_next;
		y = y + data->y_next;
		my_mlx_pixel_put(&img, x, y, color);
		i++;
	}
}

void	draw_horizontal(t_data *data, int row, t_window img)
{
	int	i;
	int	color;

	i = 0;
	while (i < data->column - 1)
	{
		if (data->matrix[row][i].z != 0 || data->matrix[row][i + 1].z != 0)
			color = 0x00FF0000;
		else
			color = 0x0000FF00;
		data->array[0] = data->matrix[row][i].x;
		data->array[1] = data->matrix[row][i].y;
		data->array[2] = data->matrix[row][i + 1].x;
		data->array[3] = data->matrix[row][i + 1].y;
		draw_line(img, color, data);
		i++;
	}
}

void	draw_vertical(t_data *data, int col, t_window img)
{
	int	i;
	int	color;

	i = 0;
	while (i < data->row - 1)
	{
		if (data->matrix[i][col].z != 0 || data->matrix[i + 1][col].z != 0)
			color = 0x00FF0000;
		else
			color = 0x0000FF00;
		data->array[0] = data->matrix[i][col].x;
		data->array[1] = data->matrix[i][col].y;
		data->array[2] = data->matrix[i + 1][col].x;
		data->array[3] = data->matrix[i + 1][col].y;
		draw_line(img, color, data);
		i++;
	}
}
