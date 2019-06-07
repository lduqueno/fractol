/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:40:07 by lduqueno          #+#    #+#             */
/*   Updated: 2019/01/05 18:29:37 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		readline(int fd, char **str)
{
	int		error;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	ft_bzero(buff, BUFF_SIZE + 1);
	while ((error = read(fd, buff, BUFF_SIZE)) > 0)
	{
		tmp = *str;
		*str = ft_strjoin(*str, buff);
		free(tmp);
		ft_bzero(buff, BUFF_SIZE + 1);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	return (error);
}

char	*gnl_to_line(char **str)
{
	int				i;
	char			*ret;
	char			*tmp;

	i = 0;
	while (*(*str + i) != '\n' && *(*str + i) != '\0')
		i++;
	ret = ft_strsub(*str, 0, i);
	tmp = *str;
	*str = ft_strsub(*str, i + 1, ft_strlen(*str) - i);
	free(tmp);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str;
	int				error;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!str)
		str = ft_strnew(0);
	if (ft_strchr(str, '\n') != NULL)
		*line = gnl_to_line(&str);
	else
	{
		if ((error = readline(fd, &str)) == 0 && !*str)
			return (0);
		if (error == -1)
			return (-1);
		*line = gnl_to_line(&str);
	}
	return (1);
}
