/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   projection.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 15:22:41 by janeway       #+#    #+#                 */
/*   Updated: 2021/10/15 19:10:06 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	projection_xy(t_data *data)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			x = (data->matrix[i][j].x - data->matrix[i][j].y) * cos(M_PI / 6);
			y = (data->matrix[i][j].x + data->matrix[i][j].y) * sin(M_PI / 6)
				- data->matrix[i][j].z;
			data->matrix[i][j].x = x;
			data->matrix[i][j].y = y;
			j++;
		}
		i++;
	}
}

static void	scale_up_down(t_data *data, float scale)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			data->matrix[i][j].x = data->matrix[i][j].x * scale;
			data->matrix[i][j].y = data->matrix[i][j].y * scale;
			j++;
		}
		i++;
	}
}

	/*
	** scale up and then scale down
	*/

void	scale_projection(t_data *data)
{
	while (ft_fabs(find_largest_x(data) - find_smallest_x(data)) < data->width
		&& ft_fabs(find_largest_y(data) - find_smallest_y(data)) < data->height)
		scale_up_down(data, 1.5);
	while (ft_fabs(find_largest_x(data) - find_smallest_x(data)) > data->width
		|| ft_fabs(find_largest_y(data) - find_smallest_y(data)) > data->height)
		scale_up_down(data, 1 / 1.5);
}

void	create_projection(t_data *data)
{
	projection_xy(data);
	scale_projection(data);
	center_projection(data);
}
