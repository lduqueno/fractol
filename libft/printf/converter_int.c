/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:20:58 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/14 14:50:18 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*from_int(va_list ap, t_context *context)
{
	long long int	i;

	if (has_flag(context, "l"))
		i = va_arg(ap, long int);
	else if (has_flag(context, "ll"))
		i = va_arg(ap, long long int);
	else if (has_flag(context, "hh"))
		i = (signed char)va_arg(ap, int);
	else if (has_flag(context, "h"))
		i = (short)va_arg(ap, int);
	else
		i = va_arg(ap, int);
	return (append_flags_int(i, context));
}
