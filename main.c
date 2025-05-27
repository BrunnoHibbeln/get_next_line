/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:33:24 by bhibbeln          #+#    #+#             */
/*   Updated: 2025/05/23 12:33:24 by bhibbeln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line = NULL;  // Initialize to NULL
    int lines;

    lines = 1;
    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%d->%s\n", lines++, line);
        free(line);  // Don't forget to free the line when done
    }
    close(fd);
    return 0;
}