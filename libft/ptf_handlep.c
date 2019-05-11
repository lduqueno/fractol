/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_handlep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:09:50 by rlegan            #+#    #+#             */
/*   Updated: 2019/04/01 16:04:05 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ptf_flag_p(t_arg *p, int b, char *s, unsigned long long int nb)
{
	size_t	len;
	int		zeroxo;

	len = ft_strlen(s);
	zeroxo = (nb == 0 && p->pcs == -2 ? -1 : 0);
	if (b == 16)
	{
		if (p->flag[F_ZERO] == 0 && p->flag[F_LESS] == 0)
			ptf_flagspacezero(p, len + 2);
		if (p->width > 0 && p->flag[F_ZERO] == 0 && p->flag[F_LESS] == 0)
			p->width = 0;
	}
	if (p->flag[F_LESS] == 0 && b == 16)
		ptf_flagspacezero(p, len + (p->flag[F_HASH] ? 2 : zeroxo));
	if (p->flag[F_PCS] && (int)len < p->pcs)
		ptf_putchar_repeat('0', p, (p->pcs - len));
}

static void	ptf_putnbr_base_p(unsigned long long int nb, int base, t_arg *p)
{
	char	*tmp;
	int		i;

	i = -1;
	ptf_putstr_wf("0x", p);
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

void		ptf_handle_p(t_arg *p)
{
	unsigned long int		nb;
	size_t					len;

	len = (p->pcs == -1 ? PF_BF_SZ * 100 : p->pcs);
	nb = (unsigned long int)va_arg(p->ap, void *);
	ptf_putnbr_base_p(nb, 16, p);
}
