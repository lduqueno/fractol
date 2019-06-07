/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:08:50 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/18 15:28:49 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		write_to_buf(char **buffer, const char *to_write)
{
	char	*temp;

	if (!buffer || !to_write)
		return ;
	if (!(temp = ft_strjoin(*buffer, to_write)))
		return ;
	free(*buffer);
	*buffer = temp;
}

void		write_to_buf_len(int a_len, int b_len, char **buf, const char *arg)
{
	char	*temp;

	if (!buf || !arg || !*buf)
		return ;
	if (!(temp = ft_strnew(b_len + a_len)))
		return ;
	ft_strncpy_c(temp, *buf, b_len);
	ft_strncpy_c(temp + b_len, arg, a_len);
	free(*buf);
	*buf = temp;
}

char		*pad_with_zeros(char *str, t_context *context, int str_len)
{
	int		print_count;
	int		zeros;
	char	*result;

	if (!str)
		return (NULL);
	if (!has_flag(context, "0") || context->pad_count == 0)
		return (str);
	print_count = 0;
	zeros = context->pad_count - str_len;
	if (zeros < 0)
		return (str);
	result = ft_strnew(zeros);
	while (print_count < zeros)
		result[print_count++] = '0';
	write_to_buf_len(str_len, zeros, &result, str);
	free(str);
	return (result);
}

char		*append_flags_double(char *r, long double i, t_context *c, int neg)
{
	char	*flag;
	char	*temp_free;

	flag = NULL;
	if (has_flag(c, "+") && i >= 0.0 && !neg)
		flag = ft_strdup("+");
	else if (has_flag(c, " ") && i >= 0.0 && !neg)
		flag = ft_strdup(" ");
	else if (neg)
		flag = ft_strdup("-");
	if (flag)
	{
		temp_free = ft_strdup(r);
		free(r);
		r = ft_strjoin(flag, temp_free);
		free(temp_free);
		free(flag);
	}
	return (r);
}

char		*append_flags_int(long long int i, t_context *context)
{
	char	*result;
	char	*flag;
	char	*temp_free;

	flag = NULL;
	if (has_flag(context, "+") && i >= 0)
		flag = ft_strdup("+");
	else if (has_flag(context, " ") && i >= 0)
		flag = ft_strdup(" ");
	if (has_flag(context, ".") && context->precision == 0 && i == 0)
		result = ft_strdup("");
	else
		result = ft_ltoa(i, context, flag ? ft_strlen(flag) : 0);
	if (flag)
	{
		temp_free = ft_strdup(result);
		free(result);
		result = ft_strjoin(flag, temp_free);
		free(temp_free);
		free(flag);
	}
	return (result);
}
