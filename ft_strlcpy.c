/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymorimot <ymorimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:36:03 by ymorimot          #+#    #+#             */
/*   Updated: 2022/05/07 00:17:15 by ymorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(src);
	i = 0;
	if (src != NULL && dstsize != 0)
	//書き方として以下の方法もある
	//if (src == NULL || dstsize == 0)
	//		return (str_len)
	//以下whileに続く
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (str_len);
}

// static size_t    ft_strnlen(const char *s, size_t n);
static size_t   ft_strnlen(const char *s, size_t n)
{
    size_t  len;

    len = 0;
    while (s[len] != '\0' && len < n)
        len += 1;
    return (len);
}
*/
/*
#include <string.h>
#include <stdio.h>

void    output_dest(char *dst, char *dst_ft, int size)
{
    int i = 0;

    printf("     dest         = [");
    while (i < size)
    {
        if (dst[i] == '\0')
            printf("\\0");
        else
            printf("%c", dst[i]);
        i += 1;
    }
    printf("]\n");

    i = 0;
    printf("     dest_ft      = [");
    while (i < size)
    {
        if (dst_ft[i] == '\0')
            printf("\\0");
        else
            printf("%c", dst_ft[i]);
        i += 1;
    }
    printf("]\n");
    printf("-----------------------------------------\n");

}

void    output_result(char *dst, char *dst_ft, int size, size_t res, size_t res_ft)
{
    int i = 0;

    printf("        strlcpy() = [");
    while (i < size && dst[i] != '\0')
    {
        printf("%c", dst[i]);
        i += 1;
    }
    if (dst[i] == '\0')
        printf("\\0");
    printf("] (%zu)\n", res);

    i = 0;
    printf("     ft_strlcpy() = [");
    while (i < size && dst_ft[i] != '\0')
    {
        printf("%c", dst_ft[i]);
        i += 1;
    }
    if (dst_ft[i] == '\0')
        printf("\\0");
    printf("] (%zu)\n", res_ft);
    printf("-----------------------------------------\n\n\n");

}

int main(void)
{
    int     i;
    size_t  res;
    size_t  res_ft;
    char    dest[10];
    char    dest_ft[10];
    char    src[9] = "coucou";
    char    src_ft[9] = "coucou";
    char    *null_p = NULL;
    size_t  sizes[9] = {0, 1, 2, -1, 6, 7, 8, 42, 0};

    i = 0;
    while (i < 9)
    {
        res = 0;
        res_ft = 0;

        if (i == 3)
            i += 1;
        if (i == 7)
            i += 1;
        memset(dest, 'A', 10);
        memset(dest_ft, 'A', 10);
        printf("------[%d] : args (dest, \"%s\", %zu);-----\n", i, src, sizes[i]);
        output_dest(dest, dest_ft, 10);
        res = strlcpy(dest, src, sizes[i]);
        res_ft = ft_strlcpy(dest_ft, src_ft, sizes[i]);
        output_result(dest, dest_ft, 10, res, res_ft);
        i += 1;
    }

    res = 0;
    res_ft = 0;
    memset(dest, '\0', 10);
    memset(dest_ft, '\0', 10);
    printf("------[%d] : args (dest, \"\\0\", 3);-----\n", i++);
    output_dest(dest, dest_ft, 10);
    res = strlcpy(dest, "\0", 3);
    res_ft = ft_strlcpy(dest_ft, "\0", 3);
    output_result(dest, dest_ft, 10, res, res_ft);

    res = 0;
    res_ft = 0;
    memset(dest, '\0', 10);
    memset(dest_ft, '\0', 10);
    printf("------[%d] : args (dest, \"\\0\", 0);-----\n", i++);
    output_dest(dest, dest_ft, 10);
    res = strlcpy(dest, "\0", 0);
    res = ft_strlcpy(dest_ft, "\0", 0);
    output_result(dest, dest_ft, 10, res, res_ft);

    res = 0;
    res_ft = 0;
    memset(dest, 'A', 10);
    memset(dest_ft, 'A', 10);
    printf("------[%d] : args (%s, %s, 0);-----\n", i++, dest, null_p);
    output_dest(dest, dest_ft, 10);
    res = strlcpy(dest, null_p, 4);
    res_ft = ft_strlcpy(dest_ft, null_p, 4);
    output_result(dest, dest_ft, 10, res, res_ft);

    return (0);
}
