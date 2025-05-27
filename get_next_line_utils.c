/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:29:21 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/05/23 12:29:21 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	str_cpy(t_list *lst, char *str)
{
	int	i;
	int	k;

	if (NULL == lst)
		return ;
	k = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = lst->content[i++];
		}
		lst = lst->next;
	}
	str[k] = '\0';
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	newline_len(t_list *lst)
{
	int	i;
	int	len;

	if (lst == NULL)
		return (0);
	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				++len;
				return (len);
			}
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

void	clear_lines(t_list **lst, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (*lst == NULL || clean_node == NULL || buf == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	if (clean_node->content[0])
		*lst = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

int	found_newline(t_list *lst)
{
	int	i;

	if (NULL == lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i] && i < BUFFER_SIZE)
		{
			if (lst->content[i] == '\n')
				return (1);
			++i;
		}
		lst = lst->next;
	}
	return (0);
}
