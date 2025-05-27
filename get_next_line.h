/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:29:47 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/05/23 12:29:47 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;
// get_next_line.c
char	*get_next_line(int fd);
void	create_list(t_list **lst, int fd);
void	append(t_list **lst, char *buf);
char	*get_line(t_list *lst);
void	polish_list(t_list **lst);
// get_next_line_utils.c
void	str_cpy(t_list *lst, char *str);
t_list	*ft_lstlast(t_list *lst);
int		newline_len(t_list *lst);
void	clear_lines(t_list **lst, t_list *clean_node, char *buf);
int		found_newline(t_list *lst);

#endif