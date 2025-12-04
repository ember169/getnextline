/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:13:35 by lgervet           #+#    #+#             */
/*   Updated: 2025/12/04 17:42:45 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	l;
// 	char	*s3;
// 	size_t	i;
// 	size_t	j;

// 	l = ft_strlen(s1) + ft_strlen(s2);
// 	s3 = (char *)malloc((l + 1) * sizeof(char));
// 	if (!s3)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		s3[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		s3[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	s3[i] = '\0';
// 	return (s3);
// }

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	unsigned char	*new;
	unsigned char	*old;
	size_t			copy_size;
	size_t			i;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
		return (free(ptr), NULL);
	new = malloc(new_size);
	if (!new)
		return (NULL);
	old = (unsigned char *)ptr;
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	i = 0;
	while (i < copy_size)
		new[i] = old[i++];
	free(ptr);
	return (new);
}
