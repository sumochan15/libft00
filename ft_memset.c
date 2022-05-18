/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorimot <ymorimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:35:45 by ymorimot          #+#    #+#             */
/*   Updated: 2022/04/27 19:55:05 by ymorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*uc_b;
	unsigned char	uc_c;
	size_t			i;

	uc_b = (unsigned char *)b;
	uc_c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		uc_b[i] = uc_c;
		i++;
	}
	return (b);
	//return (uc_b); の方が変数指定した意味がある
}
