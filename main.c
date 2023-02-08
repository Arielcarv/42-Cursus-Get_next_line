/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:39:49 by arcarval          #+#    #+#             */
/*   Updated: 2023/02/08 00:32:22 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./6_no_nl", O_RDONLY);
	while (fd > 0)
	{
		line = get_next_line(fd);
		printf("LINE: %s\n", line);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	return (0);
}
