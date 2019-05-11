/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_handlexo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:38:27 by rlegan            #+#    #+#             */
/*   Updated: 2019/04/01 16:04:20 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ptf_flagwbase(t_arg *p, int b, char *s, unsigned long long int nb)
{
	size_t	len;
	int		zeroxo;

	len = ft_strlen(s);
	zeroxo = (nb == 0 && p->pcs == -2 ? -1 : 0);
	if (b == 16 && p->flag[F_HASH] && nb != 0)
	{
		if (p->flag[F_ZERO] == 0 && p->flag[F_LESS] == 0)
			ptf_flagspacezero(p, len + 2);
		if (p->width > 0 && p->flag[F_ZERO] == 0 && p->flag[F_LESS] == 0)
			p->width = 0;
		ptf_putchar('0', p);
		ptf_putchar((p->maj == 1 ? 'X' : 'x'), p);
	}
	if (p->flag[F_LESS] == 0 && b == 8)
		ptf_flagspacezero(p, len + (p->flag[F_HASH] ? 1 : zeroxo));
	if (p->flag[F_LESS] == 0 && b == 16)
		ptf_flagspacezero(p, len + (p->flag[F_HASH] ? 2 : zeroxo));
	if (b == 8 && p->flag[F_HASH] && nb != 0)
		ptf_putchar('0', p);
	if (b == 8 && p->flag[F_HASH] && nb == 0 && p->pcs == -2)
		ptf_putchar('0', p);
	if (p->flag[F_PCS] && (int)len < p->pcs)
		ptf_putchar_repeat('0', p, (p->pcs - len));
}

static void	ptf_putnbr_base_xo(unsigned long long int nb, int base, t_arg *p)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_ltoa_base(nb, base, p->maj);
	ptf_flagwbase(p, base, tmp, nb);
	while (tmp[++i] && !(p->pcs == -2 && nb == 0))
		ptf_putchar(tmp[i], p);
	if (p->flag[F_LESS] == 1 && p->flag[F_HASH])
		ptf_flagspacezero(p, ft_strlen(tmp) + (base == 8 ? 1 : 2));
	else if (p->flag[F_LESS] == 1)
		ptf_flagspacezero(p, p->flag[F_PCS] && p->pcs > (int)ft_strlen(tmp)
			? p->pcs : ft_strlen(tmp));
	free(tmp);
}

void		ptf_handle_o(t_arg *p)
{
	unsigned long long int	nb;

	nb = (unsigned long long int)va_arg(p->ap, unsigned long long int);
	ptf_putnbr_base_xo(nb, 8, p);
}

void		ptf_handle_xx(t_arg *p)
{
	unsigned long long int	nb;

	if (p->flag[F_HH])
		nb = (unsigned char)va_arg(p->ap, int);
	else if (p->flag[F_H])
		nb = (unsigned short int)va_arg(p->ap, unsigned int);
	else if (p->flag[F_L])
		nb = (unsigned long)va_arg(p->ap, unsigned long int);
	else
		nb = (unsigned int)va_arg(p->ap, unsigned int);
	ptf_putnbr_base_xo(nb, 16, p);
}
