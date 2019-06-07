/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:32:06 by lduqueno          #+#    #+#             */
/*   Updated: 2019/01/07 17:00:57 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_u_base_fd(unsigned int nbr, char *base, int fd)
{
	return (ft_putnbr_base_fd((int)nbr, base, fd));
}
