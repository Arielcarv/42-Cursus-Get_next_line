/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:39:49 by arcarval          #+#    #+#             */
/*   Updated: 2023/02/12 23:35:33 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("./tests/file.txt", O_RDONLY);
	fd2 = open("./tests/file2.txt", O_RDONLY);
	fd3 = open("./tests/file3.txt", O_RDONLY);
	while (fd1 > 0 || fd2 > 0 || fd3 > 0)
	{
		line = get_next_line(fd1);
		printf("LINE: %s\n", line);
		line = get_next_line(fd2);
		printf("LINE: %s\n", line);
		line = get_next_line(fd3);
		printf("LINE: %s\n", line);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
