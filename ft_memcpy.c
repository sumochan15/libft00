/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorimot <ymorimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:50:48 by ymorimot          #+#    #+#             */
/*   Updated: 2022/05/07 00:03:50 by ymorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;
	size_t			len;

	if (!dst && !src)
		return (NULL);
	len = 0;
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	while (len < n)
	{
		uc_dst[len] = uc_src[len];
		len++;
	}
	return (uc_dst);
}
