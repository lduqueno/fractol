/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:51:04 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/16 14:10:20 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_start_arg(char *result, char *arg)
{
	char	*temp_free;

	if (!arg || ft_strncmp(result, arg, ft_strlen(arg)) == 0)
		return (result);
	temp_free = ft_strjoin(arg, result);
	free(result);
	return (temp_free);
}

static int	get_digits_count(unsigned long int n, int base_len, int prec)
{
	int		digits_count;

	digits_count = 1;
	prec--;
	while (n / base_len >= 1)
	{
		n /= base_len;
		digits_count++;
		prec--;
	}
	return (prec <= 0 ? digits_count : (digits_count + prec));
}

char		*ft_ltoa_base(unsigned long int n, char *base, int prec, char *arg)
{
	int		base_len;
	int		digits_count;
	char	*result;
	int		print_count;

	if (!ft_is_base_valid(base))
		return (0);
	base_len = ft_strlen(base);
	digits_count = get_digits_count(n, base_len, prec);
	print_count = 0;
	if (!(result = ft_strnew(digits_count)))
		return (ft_strdup("(null)"));
	digits_count--;
	while (n / base_len >= 1)
	{
		result[digits_count--] = base[n % base_len];
		n /= base_len;
	}
	result[digits_count--] = base[n];
	while (print_count < prec && digits_count >= 0)
	{
		result[digits_count--] = '0';
		print_count++;
	}
	return (handle_start_arg(result, arg));
}
