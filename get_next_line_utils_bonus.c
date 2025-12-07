/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:52:55 by lgervet           #+#    #+#             */
/*   Updated: 2025/12/06 16:53:14 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
	{
		new[i] = old[i];
		i++;
	}
	free(ptr);
	return (new);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!src && !dst)
		return (NULL);
	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	if (s > d)
	{
		while (len--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}
