/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:55:09 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/07 11:55:10 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;
	int	save;

	i = -1;
	if (*str == '\0' && *to_find == '\0')
		return ((char *)str);
	if (*str == '\0' || *to_find == '\0')
		return ((*to_find == '\0') ? (char *)str : NULL);
	while (str[++i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			save = i;
			while (str[save] != '\0' && to_find[j] == str[save])
			{
				if (to_find[j + 1] == '\0')
					return ((char *)&str[i]);
				j++;
				save++;
			}
		}
	}
	return (0);
}
