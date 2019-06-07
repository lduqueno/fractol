/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:40:12 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/16 13:45:10 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define MAX_FILE_DESCRIPTORS 4864
# define BUFF_SIZE 1024

int		get_next_line(const int fd, char **line);

#endif
