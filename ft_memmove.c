/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorimot <ymorimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:32:17 by ymorimot          #+#    #+#             */
/*   Updated: 2022/04/23 02:41:26 by ymorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;

	if (!dst && !src)
		return (NULL);
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	if (uc_src < uc_dst)
	{
		while (len > 0)
		{
			uc_dst[len - 1] = uc_src[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(uc_dst, uc_src, len);
	return (uc_dst);
}
