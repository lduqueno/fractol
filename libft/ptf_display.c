/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 13:48:01 by rlegan            #+#    #+#             */
/*   Updated: 2019/04/01 16:05:56 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ptf_putchar_repeat(char c, t_arg *p, int repeat)
{
	int i;

	i = -1;
	while (++i < repeat)
		ptf_putchar(c, p);
	return (repeat);
}

void	ptf_putchar(char c, t_arg *p)
{
	p->buff[p->buff_index] = c;
	p->buff_index++;
	p->printed++;
	if (p->buff_index == PF_BF_SZ)
		ptf_buffdisplay(p);
}

int		ptf_putstr(char *str, t_arg *p, size_t len)
{
	size_t	i;

	i = -1;
	if (p->pcs == -2)
		return (i);
	if (p->flag[F_LESS] == 0)
		if (p->width > 0 && p->width > (int)len)
		{
			if (ft_strlen(str) == 0)
				ptf_putchar_repeat((p->flag[F_ZERO] ? '0' : ' '), p,
					p->width - (ft_strlen(str) == 0 ? 0 : len));
			else
				ptf_putchar_repeat((p->flag[F_ZERO] ? '0' : ' '), p,
					p->width - (p->width - ft_strlen(str)
						> len ? ft_strlen(str) : len));
		}
	while (str[++i] && i < len)
		ptf_putchar(str[i], p);
	if (p->flag[F_LESS] == 1)
		if (p->width > 0 && p->width > (int)len)
			ptf_putchar_repeat((p->flag[F_ZERO] ? '0' : ' '), p,
				p->width - (ft_strlen(str) == 0 ? 0 : len));
	return (i);
}

int		ptf_putstr_wf(char *str, t_arg *p)
{
	int i;

	i = -1;
	while (str[++i])
		ptf_putchar(str[i], p);
	return (i);
}

int		ptf_putnbr_base(unsigned long long int nb, int base, t_arg *p)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_ltoa_base(nb, base, p->maj);
	while (tmp[++i])
		ptf_putchar(tmp[i], p);
	free(tmp);
	return (i);
}
