/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:12:34 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/11 18:44:00 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Free all the pointers and exit the program
*/

int			exit_fractol(t_data *data, t_bool free)
{
	if (free)
		free_all(data);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

/*
** Error function : print a custom error message, free all pointers
** dynamically allocated and exit the program
*/

int			error(t_data *data, char *error_msg)
{
	ft_dprintf(STDERR_FILENO, "Error : %s\n", error_msg);
	free_all(data);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
