/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:50:48 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 19:50:51 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int		get_spaces_count_start(char const *s)
{
	int		i;
	int		spaces_count;
	int		default_len;

	i = 0;
	spaces_count = 0;
	default_len = ft_strlen(s);
	while (i < default_len)
		if (!is_space(s[i]))
		{
			spaces_count = i;
			break ;
		}
		else if (++i == default_len)
			return (-1);
	return (spaces_count);
}

static int		get_spaces_count_end(char const *s)
{
	int		spaces_count;
	int		default_len;
	int		i;

	spaces_count = 0;
	default_len = ft_strlen(s);
	i = default_len - 1;
	while (i > 0)
		if (!is_space(s[i]))
		{
			spaces_count = default_len - i - 1;
			break ;
		}
		else
			i--;
	return (spaces_count);
}

char			*ft_strtrim(char const *s)
{
	int	start_spaces;
	int end_spaces;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
		return ((char *)s);
	start_spaces = get_spaces_count_start(s);
	end_spaces = get_spaces_count_end(s);
	if (start_spaces == -1)
		return ((char *)ft_strnew(0));
	return (ft_strsub(s, start_spaces, ft_strlen(s)
		- start_spaces - end_spaces));
}
