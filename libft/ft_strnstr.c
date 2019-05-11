/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:46:38 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/07 12:46:39 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	save;

	i = -1;
	if (*str == '\0' && *to_find == '\0')
		return ((char *)str);
	if (*str == '\0' || *to_find == '\0')
		return ((*to_find == '\0') ? (char *)str : NULL);
	while (str[++i] != '\0' && i < len)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			save = i;
			while (str[save] != '\0' && to_find[j] == str[save] && save <= len)
			{
				if (to_find[j + 1] == '\0')
					return ((char *)&str[i]);
				j++;
				save++;
			}
		}
	}
	return (NULL);
}
