/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:47:17 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/13 16:43:47 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_vsprintf(char *buf, const char *format, va_list ap)
{
	t_output	*output;
	int			print_count;

	output = parse_string(format, ap);
	if (!output || !output->buffer)
		return (0);
	ft_strncpy(buf, output->buffer, output->print_count);
	free(output->buffer);
	print_count = output->print_count;
	free(output);
	return (print_count);
}
