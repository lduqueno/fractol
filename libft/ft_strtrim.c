/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:06:39 by rlegan            #+#    #+#             */
/*   Updated: 2019/04/17 13:51:10 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (!(s))
		return (NULL);
	i = 0;
	if (s[i] == '\0')
		return (ft_strdup((char *)s));
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	if (s[i] == '\0')
	{
		if (!(str = (char *)malloc(sizeof(char) * (j + i - 1))))
			return (NULL);
		ft_bzero(str, j + i - 1);
		return (str);
	}
	str = ft_strsub(s, i, j - i + 1);
	return (str);
}
