/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:34:10 by lduqueno          #+#    #+#             */
/*   Updated: 2019/06/18 14:05:38 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_next_number(char *format, int *i, t_context *context)
{
	int		result;
	int		digits_count;
	int		next_pad_count;
	char	*temp_free;

	result = 0;
	digits_count = 0;
	while ((format[*i - 1] == '.' || format[*i] != '0')
		&& ft_isdigit(format[*i + digits_count]))
		digits_count++;
	if (digits_count > 0)
	{
		temp_free = ft_strsub(format, *i, digits_count);
		result = ft_atoi(temp_free);
		*i += digits_count;
		free(temp_free);
	}
	if (format[*i] == '*')
	{
		*i += 1;
		result = va_arg(*(context->arg), int);
		if ((next_pad_count = get_next_number(format, i, context)) > 0)
			result = next_pad_count;
	}
	return (result);
}

void		handle_flag(char *format, char *flag, t_context *context, int *i)
{
	int		next_pad_count;

	*i += ft_strlen(flag);
	context->flags[get_flag_index(context, flag)] = 1;
	if (ft_strequ(flag, "."))
		context->precision = get_next_number(format, i, context);
	else if (ft_strequ(flag, "0") || ft_strequ(flag, "+")
		|| ft_strequ(flag, "-") || ft_strequ(flag, " ") || ft_strequ(flag, "#"))
		if ((next_pad_count = get_next_number(format, i, context)) > 0)
			context->pad_count = next_pad_count;
}

t_context	*make_context(char *format, int *start_index, va_list ap)
{
	int			i;
	char		*flag;
	t_context	*context;

	i = 0;
	if (!(context = (t_context *)malloc(sizeof(t_context))))
		return (NULL);
	if (!(context->flags = (int *)malloc(sizeof(int) * (FLAG_COUNT))))
		return (NULL);
	if (!(context->def_flags = ft_strsplit(FLAGS, '_')))
		return (NULL);
	context->arg = (va_list *)ap;
	while (i < FLAG_COUNT)
		context->flags[i++] = 0;
	context->pad_count = get_next_number(format, start_index, context);
	context->precision = 0;
	while ((flag = search_next_flag(context->def_flags, format, start_index)))
		handle_flag(format, flag, context, start_index);
	if (has_flag(context, "-"))
		context->flags[get_flag_index(context, "0")] = 0;
	else if (has_flag(context, "+"))
		context->flags[get_flag_index(context, " ")] = 0;
	return (context);
}
