/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <cpopa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/03 14:30:24 by cpopa         #+#    #+#                 */
/*   Updated: 2021/10/17 17:24:37 by cpopa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	check_column_lenght(char *filename)
{
	char	*line;
	int		fd;
	int		x;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 1)
		error_exit("fd error\n");
	get_next_line(fd, &line);
	x = count_columns(line, ' ');
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		y = count_columns(line, ' ');
		if (x != y)
			return (1);
		free(line);
	}
	return (0);
}

static t_data	*initialize_data(void)
{
	t_data	*temp;

	temp = ft_calloc(1, sizeof(t_data));
	if (!temp)
		error_exit("malloc failure\n");
	temp->column = 0;
	temp->row = 1;
	temp->width = 1080;
	temp->height = 1080;
	temp->steps = 0;
	temp->x_next = 0;
	temp->y_next = 0;
	temp->array = ft_calloc(5, sizeof(float));
	if (!temp->array)
		error_free_exit("malloc failure\n", temp);
	return (temp);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		error_exit("not enough arguments\n");
	if (check_column_lenght(argv[1]) == 1)
		error_exit("map format incorect\ntry again!");
	data = initialize_data();
	parse_map(argv[1], data);
	render(data);
	free_all(data);
	return (0);
}
