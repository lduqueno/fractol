/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:14:09 by rlegan            #+#    #+#             */
/*   Updated: 2019/01/27 14:34:31 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_negative_ltoa(long long int *n, int *neg, int *i)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
		*i += 1;
	}
}

static int		ft_count_ltoa(int *i, long long int n)
{
	long long int n2;

	n2 = n;
	while (n2 >= 10)
	{
		n2 = n2 / 10;
		*i += 1;
	}
	return (*i + 1);
}

char			*ft_ltoa(long long int n)
{
	int				i;
	long long		n2;
	int				neg;
	char			*s;

	i = 1;
	neg = 0;
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	ft_negative_ltoa(&n, &neg, &i);
	n2 = n;
	i = ft_count_ltoa(&i, n);
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
