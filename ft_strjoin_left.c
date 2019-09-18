/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 06:21:19 by tlynesse          #+#    #+#             */
/*   Updated: 2019/09/18 20:21:04 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_left(const char *s1, char *s2)
{
	size_t	buf;
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1)
		return (s2);
	else if (!s2)
		return ((char *)s1);
	buf = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = (char*)malloc(buf * sizeof(char))))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = 0;
	if (ft_strlen(s2))
		free((void *)s2);
	return (res);
}
