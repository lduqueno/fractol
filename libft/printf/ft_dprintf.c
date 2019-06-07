/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:06:41 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/10 18:18:45 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list ap;
	int		result;

	va_start(ap, format);
	result = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (result);
}
