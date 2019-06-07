/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:12:31 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/13 18:36:30 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_output	*output;
	int			print_count;

	output = parse_string(format, ap);
	if (!output || !output->buffer)
		return (0);
	write(fd, output->buffer, output->print_count);
	free(output->buffer);
	print_count = output->print_count;
	free(output);
	return (print_count);
}
