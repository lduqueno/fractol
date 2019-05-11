/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:09:42 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/06 19:09:42 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int count;
	int found;

	i = 0;
	count = 0;
	found = 0;
	if ((unsigned char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[count] != '\0')
	{
		if (s[count] == (unsigned char)c)
		{
			found = 1;
			i = count;
		}
		count++;
	}
	if (s[count] == '\0' && found == 0)
		return (NULL);
	return ((char *)&s[i]);
}
