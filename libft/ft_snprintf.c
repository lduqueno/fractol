/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:39:29 by rlegan            #+#    #+#             */
/*   Updated: 2019/01/29 15:39:30 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_initialize_printf(t_arg *p)
{
	int i;

	i = -1;
	if ((*p).start == 0)
	{
		ft_bzero((*p).buff, PF_BF_SZ);
		(*p).buff_index = 0;
		p->printed = 0;
	}
	while (++i < 12)
		(*p).flag[i] = 0;
	(*p).f_idx = 0;
	(*p).len = 0;
	(*p).pcs = -1;
	(*p).width = -1;
	(*p).stop = 0;
	(*p).maj = 0;
	(*p).start = 1;
	p->skip = 0;
}

static int		ptf_end(t_arg *p, char **str, size_t size)
{
	if (p->buff_index > 0 || PF_BF_SZ == 1)
		ft_strncpy(*(str), p->buff, size);
	va_end(p->ap);
	return (p->printed);
}

int				ft_snprintf(char *str, size_t size, const char *format, ...)
{
	t_arg	p;
	int		i;

	p.start = 0;
	ptf_initialize_printf(&p);
	va_start(p.ap, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			p.format = ft_strsub(format, i, ft_strlen(format));
			if (ptf_parser(&p))
				break ;
			free((void *)p.format);
			i += p.stop;
			ptf_initialize_printf(&p);
		}
		else if (format[i] != '\0')
			ptf_putchar(format[i], &p);
	}
	return (ptf_end(&p, &str, size));
}
