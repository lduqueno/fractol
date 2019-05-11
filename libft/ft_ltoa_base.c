/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 13:55:52 by rlegan            #+#    #+#             */
/*   Updated: 2018/12/25 13:55:52 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ltoa_base(unsigned long long int n, int base, int maj)
{
	int							i;
	unsigned long long int		n2;
	char						*s;

	i = 2;
	n2 = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (maj)
		maj = 'A' - 10;
	else
		maj = 'a' - 10;
	while (n2 >= (unsigned long long int)base)
	{
		n2 = n2 / base;
		i += 1;
	}
	s = ft_strnew(sizeof(char) * i);
	s[--i] = '\0';
	while (--i >= 0)
	{
		s[i] = (n % base) + (n % base > 9 ? maj : '0');
		n = n / base;
	}
	return (s);
}
