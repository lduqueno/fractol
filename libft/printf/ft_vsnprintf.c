/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:38:41 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/13 16:43:17 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_vsnprintf(char *buf, size_t size, const char *fm, va_list ap)
{
	t_output	*output;
	char		*temp;
	int			print_count;

	output = parse_string(fm, ap);
	if (!output || !output->buffer || !buf ||
		!(temp = ft_strsub(output->buffer, 0, --size)))
		return (0);
	free(output->buffer);
	ft_strncpy(buf, temp, output->print_count);
	free(temp);
	print_count = output->print_count;
	free(output);
	return (print_count);
}
