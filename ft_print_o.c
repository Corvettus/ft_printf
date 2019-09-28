/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:39:28 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/28 19:11:13 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_o(var *tmp)
{

	if (tmp->width < tmp->precision)
		tmp->width = tmp->precision;
	if (tmp->flag == '?' || tmp->flag == '0' || tmp->flag == '-')
		while ((int)ft_strlen(tmp->data) < tmp->precision)
			tmp->data = ft_strjoin_left("0", tmp->data);
//	if (tmp->flag == '0')
//		while ((int)ft_strlen(tmp->data) < tmp->width)
//			tmp->data = ft_strjoin_left("0", tmp->data);
	if (tmp->flag2 == '#' && tmp->flag != '0')
		tmp->data = ft_strjoin_left("0", tmp->data);
	
	if (tmp->width > (int)ft_strlen(tmp->data))
	{
		if (tmp->flag != '-')
			tmp->data = ft_fil_whitespaces(tmp, tmp->width, (int)ft_strlen(tmp->data));
		else if (tmp->flag == '-')
			tmp->data = ft_end_whitespaces(tmp, tmp->width, (int)ft_strlen(tmp->data));
	}

	//tmp->data = ft_print_d(tmp);		
	return (tmp->data);
}
//if (tmp->precision)
		//tmp->data = ft_crop_str(tmp->data, (int)ft_strlen(tmp->data), tmp->precision);
/*
if (tmp->width && tmp->width > (int)ft_strlen(tmp->data))
	{
		if (tmp->flag != '-')
			tmp->data = ft_fil_whitespaces(tmp, wdth, len);
		else if (tmp->flag == '-')
			tmp->data = ft_end_whitespaces(tmp, wdth, len);
	}
*/