/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:13:43 by lgervet           #+#    #+#             */
/*   Updated: 2025/12/04 16:46:23 by lgervet          ###   ########.fr       */
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

void    debug_print(const char *s)
{
    int i = 0;

    while (s && s[i])
    {
        if (s[i] == '\n')
            printf("\\n");   // affiche "\n"
        else
            printf("%c", s[i]);
        i++;
    }
    printf("\n");
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

/*
** extract_line:
**     - return tous les caracteres jusqu'a \n (inclu) dans une str.
**	   - retire l'ensemble de la str returned de la chaine d'origine.
**
**     @param	s	str (ici stash[fd])
**     @return		la ligne trouvee / l'ensemble de la chaine
*/
char	*extract_line(char *s)
{
	size_t	i;
	size_t	j;
	size_t	line_len;
	char	*ret;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		line_len = i + 1;
	else
		line_len = i;
	ret = (char *)malloc((line_len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s, line_len + 1);
	j = 0;
	while (s[line_len + j])
		s[j++] = s[line_len + j];
	s[j] = '\0';
	return (ret);
}

/*
** add_to_stash:
**     ajoute str source a str destination (via pointeurs).
**
**     @param	dst	*str destination
**     @param	src	*str source
*/
void	add_to_stash(char **dst, char **src)
{
	if (!dst || !src)
		return ;
	while (*dst && *src)
		*dst++ = *src++;
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	char		*buffer;
	char		*line;
	int			i;
	int			n;

	if (!stash[fd])
	{
		stash[fd] = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); // TODO
		if (!stash[fd])
			return (NULL);
	}
	// printf("New iter; stash[fd] content: \"%s\"\n", stash[fd]);
	/* Si la stash dispose deja d'un \n */
	if (ft_strchr(stash[fd], '\n'))
		return (extract_line(stash[fd]));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	/* Tant qu'on a pas \n dans buffer */
	while (!ft_strchr(buffer, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			return (free(stash[fd]), free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
		{
			i = 0;
			while (stash[fd] && stash[fd][i++])
				buffer[i] = stash[fd][i];
			while (buffer[i] != '\n')
				i++;
			// printf("buffer = \"%s\"\n", buffer);
			line = malloc((i + 2) * sizeof(char));
			if (!line)
				return (NULL);
			ft_strlcpy(line, buffer, i + 2);
			// printf("line = \"%s\"\n", line);
			add_to_stash(&stash[fd], &buffer);
			extract_line(stash[fd]);
			// printf("new stash[fd] = \"%s\"\n", stash[fd]);
			return (line);
		}
	}
	return (NULL);
}

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*str;
	char	*str2;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("tst.txt", O_RDONLY);

	printf("[FD1]\n");
	str = get_next_line(fd1);
	printf("RETURNED: ");
	debug_print(str);
	str = get_next_line(fd1);
	printf("RETURNED: ");
	debug_print(str);
	str = get_next_line(fd1);
	printf("RETURNED: ");
	debug_print(str);

	printf("\n");

	printf("[FD2]\n");
	str2 = get_next_line(fd2);
	printf("RETURNED: ");
	debug_print(str2);
	str2 = get_next_line(fd2);
	printf("RETURNED: ");
	debug_print(str2);
	str2 = get_next_line(fd2);
	printf("RETURNED: ");
	debug_print(str2);

	return (1);
}
