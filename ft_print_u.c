/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:39:07 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/29 17:25:24 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_u(var *tmp)
{
	while ((tmp->flag == '?' || (tmp->precision > 0)) && tmp->precision > (int)ft_strlen(tmp->data))
	{
		tmp->flag = '0';
		tmp->data = ft_strjoin_left("0", tmp->data);
	}
	tmp->data = ft_print_s(tmp);
	return (tmp->data);
}
