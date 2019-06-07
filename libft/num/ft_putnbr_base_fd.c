/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:31:54 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/15 17:31:55 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int				base_size;
	unsigned int	new_nbr;
	int				print_count;

	new_nbr = nbr;
	print_count = 0;
	if (!ft_is_base_valid(base))
		return (0);
	base_size = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		print_count++;
		new_nbr = -nbr;
	}
	if (new_nbr / base_size >= 1)
		print_count += ft_putnbr_base_fd(new_nbr / base_size, base, fd);
	ft_putchar_fd(base[new_nbr % base_size], fd);
	print_count++;
	return (print_count);
}
