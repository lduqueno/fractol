/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:01:44 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 19:01:47 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	str_len;
	char			*result;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!s)
		return (NULL);
	if (!len)
		return (ft_strnew(0));
	str_len = ft_strlen(s);
	if (str_len < start || !(result = (char *)ft_strnew(len)))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
		if (i++ == start)
		{
			j = i - 1;
			while (s[j] && k < len)
				result[k++] = s[j++];
			break ;
		}
	result[k] = '\0';
	return (result);
}
