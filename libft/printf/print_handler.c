/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:57:09 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/16 15:47:56 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type			g_types[FORMAT_COUNT] =
{
	(t_type) { .format = "c", .execute = &from_char },
	(t_type) { .format = "s", .execute = &from_str },
	(t_type) { .format = "p", .execute = &from_ptr },
	(t_type) { .format = "d", .execute = &from_int },
	(t_type) { .format = "i", .execute = &from_int },
	(t_type) { .format = "o", .execute = &from_uint_to_octal },
	(t_type) { .format = "u", .execute = &from_uint_to_uint },
	(t_type) { .format = "x", .execute = &from_uint_to_uhex_low },
	(t_type) { .format = "X", .execute = &from_uint_to_uhex_upp },
	(t_type) { .format = "f", .execute = &from_double },
	(t_type) { .format = "b", .execute = &from_binary },
	(t_type) { .format = "bo", .execute = &from_boolean },
	(t_type) { .format = "%", .execute = &from_default }
};

static t_type	*type_from_str(const char *format, int start_index)
{
	int		i;
	int		j;
	t_type	*found;
	char	*sub;

	found = NULL;
	i = 0;
	while (i < FORMAT_COUNT)
	{
		if (!g_types[i].format)
			break ;
		j = 2;
		while (j > 0)
		{
			if (!(sub = ft_strsub(format, start_index, j--)))
				continue ;
			found = (ft_strequ(sub, g_types[i].format) ? &g_types[i] : found);
			free(sub);
			if (found)
				break ;
		}
		i++;
	}
	return (found);
}

static void		padding(t_context *context, const char *arg, t_output *o, int a)
{
	int			print_count;
	int			has_flag_minus;

	print_count = a;
	has_flag_minus = has_flag(context, "-");
	if (has_flag_minus)
	{
		write_to_buf_len(a, o->print_count, &o->buffer, arg);
		o->print_count += a;
	}
	if (!has_flag(context, "0"))
		while (print_count < context->pad_count)
		{
			write_to_buf_len(1, o->print_count, &o->buffer, " ");
			o->print_count += 1;
			print_count++;
		}
	if (!has_flag_minus)
	{
		write_to_buf_len(a, o->print_count, &o->buffer, arg);
		o->print_count += a;
	}
}

static void		handle_format(int *i, va_list ap, const char *form, t_output *o)
{
	char		*arg_result;
	t_context	*context;
	t_type		*type;
	int			arg_len;

	++*i;
	context = make_context((char *)form, i, ap);
	if (!(type = type_from_str(form, *i)))
	{
		free_context(context);
		*i -= 1;
		return ;
	}
	*i += ft_strlen(type->format) - 1;
	if (!(arg_result = (*(type->execute))(ap, context)))
	{
		free_context(context);
		return ;
	}
	arg_len = ft_strlen(arg_result);
	arg_len += (ft_strequ(type->format, "c") && arg_len == 0);
	padding(context, arg_result, o, arg_len);
	free(arg_result);
	free_context(context);
}

t_output		*parse_string(const char *format, va_list ap)
{
	t_output	*output;
	char		*temp;
	int			i;

	i = 0;
	if (!(output = (t_output *)malloc(sizeof(t_output))))
		return (NULL);
	output->buffer = ft_strnew(0);
	output->print_count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			handle_format(&i, ap, format, output);
		else
		{
			if (!(temp = ft_strsub(format, i, 1)))
				continue ;
			write_to_buf_len(1, output->print_count, &output->buffer, temp);
			output->print_count += 1;
			free(temp);
		}
		++i;
	}
	return (output);
}
