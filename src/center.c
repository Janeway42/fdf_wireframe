/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   align.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <cpopa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 15:42:43 by cpopa         #+#    #+#                 */
/*   Updated: 2021/10/13 12:57:21 by cpopa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	find_smallest_x(t_data *data)
{
	int		i;
	int		j;
	float	smallest_x;

	i = 0;
	smallest_x = data->matrix[0][0].x;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			if (smallest_x > data->matrix[i][j].x)
				smallest_x = data->matrix[i][j].x;
			j++;
		}
		i++;
	}
	return (smallest_x);
}

float	find_largest_x(t_data *data)
{
	int		i;
	int		j;
	float	largest_x;

	i = 0;
	largest_x = data->matrix[0][0].x;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			if (largest_x < data->matrix[i][j].x)
				largest_x = data->matrix[i][j].x;
			j++;
		}
		i++;
	}
	return (largest_x);
}

float	find_smallest_y(t_data *data)
{
	int		i;
	int		j;
	float	smallest_y;

	i = 0;
	smallest_y = data->matrix[0][0].y;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			if (smallest_y > data->matrix[i][j].y)
				smallest_y = data->matrix[i][j].y;
			j++;
		}
		i++;
	}
	return (smallest_y);
}

float	find_largest_y(t_data *data)
{
	int		i;
	int		j;
	float	largest_y;

	i = 0;
	largest_y = data->matrix[0][0].y;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			if (largest_y < data->matrix[i][j].y)
				largest_y = data->matrix[i][j].y;
			j++;
		}
		i++;
	}
	return (largest_y);
}

void	center_projection(t_data *data)
{
	int		i;
	int		j;
	float	relocate_x;
	float	relocate_y;

	relocate_x = (data->width / 2)
		- ((find_largest_x(data) + find_smallest_x(data)) / 2);
	relocate_y = (data->height / 2)
		- ((find_largest_y(data) + find_smallest_y(data)) / 2);
	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			data->matrix[i][j].x = data->matrix[i][j].x + relocate_x;
			data->matrix[i][j].y = data->matrix[i][j].y + relocate_y;
			j++;
		}
		i++;
	}
}
