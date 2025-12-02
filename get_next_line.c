/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:13:43 by lgervet           #+#    #+#             */
/*   Updated: 2025/12/01 15:43:09 by lgervet          ###   ########.fr       */
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

char	*construct_line_from_stash(char *stash, char *line)
{
	int	*ptr;

	ptr = ft_strchr(stash, '\n');
	while (*ptr)
		*line++ = *ptr++;
	return (line);
}

char	*stash_remainder(char *stash)
{

}

char	*stash_and_return(int fd, char *stash, char *line)
{
	line = construct_line_from_stash(stash[fd], line);
	stash[fd] = stash_remainder(stash[fd]);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*stash[FD_MAX];
	int				n;
	char			s[BUFFER_SIZE + 1];
	char			*line;

	while (!(ft_strchr(stash[fd], '\n')))
	{
		n = read(fd, s, BUFFER_SIZE);
		if (n < 0)
		{
			free(stash[fd]);
			stash[fd] = NULL;
			return (NULL);
		}
		if (n == 0)
		{
			if (stash[fd] == NULL)
				return (NULL);
			return (stash_and_return(fd, stash[fd], line));
		}
		s[n] = '\0';
		ft_strcat(stash[fd], s);
	}
	return (stash_and_return(fd, stash[fd], line));
}

/* 
	strchr(stash[fd], '\n') ?
		yes: 
			line  = stash[fd][0 -> '\n']
     	  	stash[fd] = stash[fd]['\n' -> end]
      	  	return line
			
		no:  
			loop
				n = read(fd, str, BUFFER_SIZE)
				if (n < 0):
					free stash[fd]
					stash[fd] = NULL
					return NULL
				if (n == 0):
					if (stash[fd] == NULL):
						return NULL
					line = stash[fd]
					stash[fd] = NULL
					return line

				cat(str, stash[fd])
				
				strchr(stash[fd], '\n')
					yes:
						line = stash[fd]
						stash[fd] = everything after \n
						return line
					no:
						continue
*/