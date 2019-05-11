/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:17:19 by lduqueno          #+#    #+#             */
/*   Updated: 2019/04/16 13:40:04 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_endswith(char *src, char *search)
{
	int	src_len;
	int	search_len;
	int	i;
	int	j;

	src_len = ft_strlen(src);
	search_len = ft_strlen(search);
	i = src_len - search_len;
	j = 0;
	if (i < 0)
		return (0);
	while (i < src_len)
		if (src[i++] != search[j++])
			return (0);
	return (1);
}
