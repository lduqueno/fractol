/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:14:09 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/09 15:14:10 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_negative_itoa(int *n, int *neg, int *i)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
		*i += 1;
	}
}

static int		ft_count_itoa(int *i, int n)
{
	int n2;

	n2 = n;
	while (n2 >= 10)
	{
		n2 = n2 / 10;
		*i += 1;
	}
	return (*i + 1);
}

char			*ft_itoa(int n)
{
	int		i;
	int		n2;
	int		neg;
	char	*s;

	i = 1;
	neg = 0;
	ft_negative_itoa(&n, &neg, &i);
	n2 = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_count_itoa(&i, n);
	if (!(s = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	s[--i] = '\0';
	while (--i >= 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
