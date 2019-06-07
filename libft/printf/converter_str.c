/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:56:30 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/16 15:46:27 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*from_char(va_list ap, t_context *context)
{
	char	*result;
	char	character;

	if (!(result = ft_strnew(1)))
		return (ft_strdup("(null)"));
	character = (char)va_arg(ap, int);
	*result = character;
	return (pad_with_zeros(result, context, 1));
}

char		*from_default(va_list ap, t_context *context)
{
	(void)ap;
	return (pad_with_zeros(ft_strdup("%"), context, 1));
}

char		*from_str(va_list ap, t_context *context)
{
	char	*arg;
	char	*result;
	char	*temp_free;

	if (!(arg = va_arg(ap, char *))
		|| !(result = ft_strdup(arg)))
		result = ft_strdup("(null)");
	if (has_flag(context, "."))
	{
		temp_free = ft_strsub(result, 0, context->precision);
		free(result);
		result = temp_free;
	}
	return (pad_with_zeros(result, context, ft_strlen(result)));
}
