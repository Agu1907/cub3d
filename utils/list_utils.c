/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:31:00 by keezgi            #+#    #+#             */
/*   Updated: 2026/01/26 06:34:19 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    list_add_back(t_list **list, char *content , int length)
{
    t_list *new_node;
    t_list *tmp;

    new_node = malloc(sizeof(t_list));
    new_node->content = content;
    new_node->width = ft_strlen(content);
    if (new_node->width > 0 && content[new_node->width - 1] == '\n')
        new_node->width -= 1;
    new_node->length = length;
    new_node->next = NULL;
    if (!(*list))
    {
        *list = new_node;
        return ;
    }
    tmp = *list; 
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
}

size_t get_list_size(t_list *list)
{
    size_t size;
    t_list *tmp;

    size = 0;
    tmp = list;
    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }
    return (size);
}