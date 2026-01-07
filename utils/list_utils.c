/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:31:00 by keezgi            #+#    #+#             */
/*   Updated: 2025/12/22 15:50:57 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    list_add_back(t_list **list, char *content)
{
    t_list *new_node;
    t_list *tmp;

    new_node = malloc(sizeof(t_list));
    new_node->content = content;
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