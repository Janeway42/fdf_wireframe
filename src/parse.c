/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <cpopa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/03 14:39:59 by cpopa         #+#    #+#                 */
/*   Updated: 2021/10/13 12:28:32 by cpopa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	count_columns(char *line, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] != c && (line[i + 1] == c || line[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	allocate_memory(t_data *data, int fd)
{
	char	*line;
	int		i;

	get_next_line(fd, &line);
	data->column = count_columns(line, ' ');
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		data->row++;
		free(line);
	}
	data->matrix = (t_points **)ft_calloc(sizeof(t_points *), data->row);
	if (!data->matrix)
		error_free_exit_data("failed malloc", data);
	i = 0;
	while (i < data->row)
	{
		data->matrix[i] = (t_points *)ft_calloc(sizeof(t_points), data->column);
		if (!data->matrix[i])
			error_free_exit_data("failed malloc", data);
		i++;
	}
	free(line);
}

static void	insert_input(t_data *data, int fd)
{
	char	*line;
	char	**split_line;
	int		col;
	int		row;

	row = 0;
	while (get_next_line(fd, &line) > 0)
	{
		split_line = ft_split(line, ' ');
		col = 0;
		{
			while (split_line[col])
			{
				data->matrix[row][col].x = col;
				data->matrix[row][col].y = row;
				data->matrix[row][col].z = ft_atoi(split_line[col]);
				free(split_line[col]);
				col++;
			}
			free(split_line);
			free(line);
		}
		row++;
	}
}

int	open_fd(char *filename, t_data *data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 1)
		error_free_exit_data("fd error", data);
	return (fd);
}

void	parse_map(char *filename, t_data *data)
{
	int	fd;

	fd = open_fd(filename, data);
	allocate_memory(data, fd);
	close(fd);
	fd = open_fd(filename, data);
	insert_input(data, fd);
	close (fd);
	create_projection(data);
}
