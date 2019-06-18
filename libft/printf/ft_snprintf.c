/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:25:54 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/18 14:05:50 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_snprintf(char *buf, size_t size, const char *format, ...)
{
	va_list		ap;
	t_output	*output;
	char		*temp;
	int			print_count;

	va_start(ap, format);
	output = parse_string(format, ap);
	if (!output || !output->buffer || !buf
		|| !(temp = ft_strsub(output->buffer, 0, --size)))
	{
		va_end(ap);
		return (0);
	}
	free(output->buffer);
	ft_strncpy(buf, temp, size);
	free(temp);
	print_count = output->print_count;
	free(output);
	va_end(ap);
	return (print_count);
}
