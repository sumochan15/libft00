/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorimot <ymorimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:04:18 by ymorimot          #+#    #+#             */
/*   Updated: 2022/04/27 20:55:44 by ymorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)

{
	size_t	len_d;
	size_t	len_s;
	size_t	n;

	len_s = ft_strlen (src);
	if (dstsize == 0)
		return (len_s);
	len_d = ft_strlen (dst);
	n = 0;
	if (dstsize <= len_d)
		return (len_s + dstsize);
	while (src[n] != '\0' && n < dstsize - 1 - len_d)
	{
		dst[len_d + n] = src[n];
		n++;
	}
	dst[len_d + n] = '\0';
	return (len_d + len_s);
}
//dstが'\0'の時、プロトタイプはsfになるのでこの関数にも条件入れていないが、今後使用時は条件に入れる必要がある