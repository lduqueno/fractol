/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:46:23 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/13 16:42:13 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_sprintf(char *buf, const char *format, ...)
{
	va_list		ap;
	t_output	*output;
	int			print_count;

	va_start(ap, format);
	output = parse_string(format, ap);
	if (!output || !output->buffer || !buf)
	{
		va_end(ap);
		return (0);
	}
	ft_strncpy(buf, output->buffer, output->print_count);
	free(output->buffer);
	print_count = output->print_count;
	free(output);
	va_end(ap);
	return (print_count);
}
