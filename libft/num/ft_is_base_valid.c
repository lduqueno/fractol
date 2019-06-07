/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_base_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:34:16 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/15 17:34:17 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_base_valid(char *base)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = ft_strlen(base);
	if (size <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < size)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
