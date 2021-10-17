/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/15 13:57:23 by janeway       #+#    #+#                 */
/*   Updated: 2021/10/15 19:15:58 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../includes/libft.h"
# include "../includes/get_next_line.h"
# include <stdio.h>

typedef struct s_points
{
	float	x;
	float	y;
	float	z;
}
				t_points;

typedef struct s_data
{
	int			column;
	int			row;
	float		width;
	float		height;
	int			*col;
	float		steps;
	float		x_next;
	float		y_next;
	float		*array;
	t_points	**matrix;
}				t_data;

typedef struct t_window
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_window;

int			open_fd(char *filename, t_data *data);

/*
** verify
*/
int			count_columns(char *line, char c);

/*
** projection & render
*/
void		parse_map(char *filename, t_data *data);
void		create_projection(t_data *data);
void		projection_xy(t_data *data);
void		scale_projection(t_data *data);
float		find_smallest_x(t_data *data);
float		find_largest_x(t_data *data);
float		find_smallest_y(t_data *data);
float		find_largest_y(t_data *data);
void		center_projection(t_data *data);
void		render(t_data *data);
void		draw(t_data *data, t_window img);
void		draw_horizontal(t_data *data, int row, t_window img);
void		draw_vertical(t_data *data, int col, t_window img);

/*
** utils
*/
int			ft_abs(int x);
float		ft_fabs(float x);

/*
** error / free / exit
*/
void		error_exit(char *str);
void		error_free_exit_data(char *str, t_data *data);
void		error_free_exit(char *str, t_data *data);
void		free_all(t_data *data);

/*
** print stuff - to be erased
*/

void		print_map(t_data *data);

#endif
