/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:14:09 by arcarval          #+#    #+#             */
/*   Updated: 2023/01/27 00:40:03 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/* Return if specified character was found */
int	ft_strchr(char const *str, int caracter)
{
	char	temp_caracter;
	int		index;

	temp_caracter = caracter;
	index = 0;
	while (*(str + index) && (*(str + index) != temp_caracter))
		index++;
	if (*(str + index) == temp_caracter)
		return (1);
	return (0);
}

/* Returns a pointer to the last node in our stash */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current_node;

	if (!lst)
		return (lst);
	current_node = lst;
	while (current_node->next)
		current_node = current_node->next;
	return (current_node);
}

/* Looks for a newline character in the given linked list. */
int	newline(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (0);
	current = ft_lstlast(lst);
	printf("\nSTRING%s\n", current->str);
	return (ft_strchr(current->str, '\n'));
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->str = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (*lst)
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new;
		return ;
	}
	*lst = new;
}

void	read_and_store(int fd, t_list **str_list)
{
	char	*buffer;
	int		bytes_read;

	printf("\nAQUI=1\n");
	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return ;
	while (!newline(*str_list) && bytes_read != 0)
	{
		// printf("\nAQUI=3\n");
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		printf("\nBYTES READ=%d\n", bytes_read);
		printf("BUFFER:%s", buffer);
		buffer[bytes_read] = '\0';
	}
}

char	*get_next_line(int fd)
{
	static t_list	*str_list = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	// 1 - Read the file and store it in a linked list
	read_and_store(fd, &str_list);
	// 2 - Take the first line of the linked list and return it
	// 3 - Clean up linked list
	return (line);
}


int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file2.txt", O_RDONLY);
	while (fd > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("LINE:%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
