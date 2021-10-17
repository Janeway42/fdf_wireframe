/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_free_exit.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/04 13:06:23 by janeway       #+#    #+#                 */
/*   Updated: 2021/10/13 14:37:51 by cpopa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error_exit(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

void	error_free_exit_data(char *str, t_data *data)
{
	free(data);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->row)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
	free(data);
}

void	error_free_exit(char *str, t_data *data)
{
	free_all(data);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}
