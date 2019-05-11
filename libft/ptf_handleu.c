/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_handleu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:46:29 by rlegan            #+#    #+#             */
/*   Updated: 2019/01/21 14:46:30 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_putnbr_unsigned(unsigned long long int nb, t_arg *p)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_ltoa_base(nb, 10, p->maj);
	if (p->flag[F_LESS] == 0)
		ptf_flagspacezero(p, ft_strlen(tmp));
	if (p->flag[F_PCS])
		ptf_putchar_repeat('0', p, p->pcs - ft_strlen(tmp));
	while (tmp[++i] && p->pcs != -2)
		ptf_putchar(tmp[i], p);
	if (p->flag[F_LESS] == 1)
		ptf_flagspacezero(p, ft_strlen(tmp));
	free(tmp);
}

void			ptf_handle_u(t_arg *p)
{
	unsigned long long int	nb;
	unsigned short int		nb2;
	unsigned long int		nb3;
	unsigned int			nb4;

	if (p->flag[F_LL])
	{
		nb = (unsigned long long int)va_arg(p->ap, unsigned long long int);
		ptf_putnbr_unsigned(nb, p);
	}
	else if (p->flag[F_H])
	{
		nb2 = (unsigned short)va_arg(p->ap, int);
		ptf_putnbr_unsigned(nb2, p);
	}
	else if (p->flag[F_L])
	{
		nb3 = (unsigned long)va_arg(p->ap, unsigned long);
		ptf_putnbr_unsigned(nb3, p);
	}
	else
	{
		nb4 = (unsigned int)va_arg(p->ap, unsigned int);
		ptf_putnbr_unsigned(nb4, p);
	}
}
