/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:51:54 by lgervet           #+#    #+#             */
/*   Updated: 2025/11/28 12:51:55 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*str;
	char	*str2;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("tst.txt", O_RDONLY);

	str = get_next_line(fd1);
	str2 = get_next_line(fd1);

	printf("%s\n", str);
	printf("%s", str2);

	return (1);
}
