/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:33:15 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/05/23 12:33:15 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	polish_list(t_list **lst)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = ft_lstlast(*lst);
	if (!last_node)
		return ;
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[++i])
		buf[j++] = last_node->content[i];
	buf[j] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	clear_lines(lst, clean_node, buf);
}

char	*get_line(t_list *lst)
{
	int		str_len;
	char	*next_str;

	if (lst == NULL)
		return (NULL);
	// Count how many char are till '\n'
	str_len = newline_len(lst);
	next_str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (next_str == NULL)
		return (NULL);
	// Copy the string in the buffer and return it
	str_cpy(lst, next_str);
	return (next_str);
}

void	append(t_list **lst, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*lst);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

void	create_list(t_list **lst, int fd)
{
	// Necessary to place the \0 -> "string\0"
	int		char_read;
	char	*buf;

	//scan line if '\n' present
	while (!found_newline(*lst))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		// Append the node
		append(lst, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*next_line;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, &next_line, 0) < 0))
		return (NULL);
	// Create my list till i stumble into '\n'
	create_list(&lst, fd);
	if (lst == NULL)
		return (NULL);
	// Fetch the line from list
	next_line = get_line(lst);
	polish_list(&lst);
	return (next_line);
}
