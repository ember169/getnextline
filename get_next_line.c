/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:13:43 by lgervet           #+#    #+#             */
/*   Updated: 2025/11/28 12:58:13 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*  FUNCTION: get_next_line                                                   */
/*                                                                            */
/*  Returns a line read from given file descriptor                            */
/*                                                                            */
/*  @param fd  	  The file descriptor to read from                            */
/*  @return       Read line (str) / NULL if nothing to read or error occured  */
/*                                                                            */
/*  Example:                                                                  */
/*     int *arr = ft_calloc(10, sizeof(int));                                 */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_fd(int file, char *s, int buffersize)
{
	int	n;

	n = read(file, s, buffersize);
	if (n == -1 || n == 0)
		return (NULL);
	return (n);
}

char	*get_next_line(int fd)
{
	int			n;
	int			*ptr;
	char		*s[BUFFER_SIZE];

	n = read_fd(file, s, BUFFER_SIZE - 1);
	if (n <= 0)
		return (NULL);
	ptr = compose_str(s);
	free();
	return (s);
}

/* 
	1. find out if file descriptor aleady been seen
		yes:	is '\n' in stash
				yes: return stash before \n and stash after \n
				no:  

*/