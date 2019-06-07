/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:10:42 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/07 10:10:43 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_digits_count(int n)
{
	unsigned int	digits_count;

	digits_count = 0;
	while (n / 10 >= 1)
	{
		n /= 10;
		digits_count++;
	}
	return (digits_count);
}

static char		*ft_itoa_min_int(void)
{
	return (ft_strjoin(ft_itoa(MIN_INT / 10), ft_itoa(8)));
}

char			*ft_itoa(int n)
{
	int		signe;
	int		digits_count;
	char	*result;

	signe = 1;
	digits_count = 1;
	if (n == MIN_INT)
		return (ft_itoa_min_int());
	if (n < 0)
	{
		n = -n;
		signe = -1;
	}
	digits_count += get_digits_count(n) + (signe == -1 ? 1 : 0);
	if (!(result = (char *)malloc(sizeof(char) * (digits_count + 1))))
		return (NULL);
	result[digits_count--] = '\0';
	while (n / 10 >= 1)
	{
		result[digits_count--] = ((n % 10) + '0');
		n /= 10;
	}
	result[digits_count--] = (n + '0');
	result[0] = signe == -1 ? '-' : result[0];
	return (result);
}
