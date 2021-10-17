/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <cpopa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/13 12:25:29 by cpopa         #+#    #+#                 */
/*   Updated: 2021/10/13 12:57:54 by cpopa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_abs(int x)
{
	if (x < 0)
		x = x * -1;
	return (x);
}

float	ft_fabs(float x)
{
	if (x < 0)
		x = x * -1;
	return (x);
}
