/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:24:16 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 15:24:17 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				last;
	unsigned int	i;
	unsigned int	length;

	last = -1;
	i = 0;
	length = ft_strlen(str);
	while (i < length + 1)
	{
		if (str[i] == (unsigned char)c)
			last = i;
		i++;
	}
	return (last == -1 ? NULL : ((char *)&str[last]));
}
