/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:10:42 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/14 16:31:21 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_ltoa(long long int n, t_context *context, int pre_flag_len)
{
	int		max_zero_pad;
	int		signe;
	char	*result;
	char	*temp_free;

	if (has_flag(context, "0") && context->precision > 0)
		context->flags[get_flag_index(context, "0")] = 0;
	max_zero_pad = has_flag(context, "0") && context->pad_count >= context->
		precision ? context->pad_count - pre_flag_len : context->precision;
	signe = n >= 0;
	if (n < 0)
	{
		n = -n;
		if (has_flag(context, "0"))
			--max_zero_pad;
	}
	temp_free = ft_ltoa_base((unsigned long long int)n, "0123456789",
		max_zero_pad, NULL);
	if (signe == 0)
	{
		result = ft_strjoin("-", temp_free);
		free(temp_free);
		return (result);
	}
	return (temp_free);
}
