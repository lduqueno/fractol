/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:21:47 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/10 18:19:07 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		result;

	va_start(ap, format);
	result = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (result);
}
