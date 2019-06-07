/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:39:44 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 15:39:45 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t size)
{
	unsigned int	i;
	size_t			j;
	size_t			match;

	i = 0;
	match = 0;
	if (ft_strlen(needle) == 0 || ft_strcmp(needle, str) == 0)
		return ((char *)str);
	while (str[i] && i <= size)
	{
		j = 0;
		if (str[i] == needle[j])
		{
			match = i;
			while (str[match] && str[match] == needle[j] && match < size)
			{
				if (needle[j + 1] == '\0')
					return ((char *)&(str[i]));
				match++;
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
