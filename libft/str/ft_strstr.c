/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:32:08 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 15:32:09 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *needle)
{
	int i;
	int j;
	int match;

	i = 0;
	match = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		if (str[i] == needle[j])
		{
			match = i;
			while (str[match] && str[match] == needle[j])
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
