/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 05:03:23 by keezgi            #+#    #+#             */
/*   Updated: 2026/01/25 03:18:04 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    fill_map_with_two(t_list *map, size_t max_width)
{
    t_list  *tmp;
    char    *new_row;
    size_t     i;
    size_t     j;

    tmp = map;
    while (tmp)
    {
        if (tmp->width < max_width || (tmp->width > 0))
        {
            new_row = malloc(sizeof(char) * (max_width + 1));
            i = 0;
            j = 0;
            while (tmp->content[i] && tmp->content[i] != '\n')
            {
                new_row[i] = tmp->content[i];
                i++;
            }
            while (i < max_width)
            {
                new_row[i] = '2';
                i++;
            }
            new_row[i] = '\0';
            free(tmp->content);
            tmp->content = new_row;
            tmp->width = max_width;
        }
        tmp = tmp->next;
    }
}
size_t find_max_width(t_list *map)
{
    size_t len;
    t_list *tmp;
    tmp = map;
    len = 0;
    while (tmp)
    {
        if (len < tmp->width)
            len = tmp->width;
        tmp = tmp->next;
    }
    return (len);
}

int    check_rows(t_list *map , int *is_player_set)
{
    t_list *tmp;
    int i;
    tmp = map;
    while (tmp)
    {
        i = 0;
        while (tmp->content[i] && tmp->content[i] != '\n')
        {
            if (tmp->content[i] == '\t' || tmp->content[i] == ' ')
                i++;
            else if (tmp->content[i] == '1' || tmp->content[i] == '0')
                i++;
            else if ((tmp->content[i] == 'N' || tmp->content[i] == 'S' || tmp->content[i] == 'E' || tmp->content[i] == 'W') && *is_player_set == false)
            {
                *is_player_set = true;
                i++;
            }
            else if ((tmp->content[i] == 'N' || tmp->content[i] == 'S' || tmp->content[i] == 'E' || tmp->content[i] == 'W') && *is_player_set == true)
            {
                print_err("Multiple character definition on map!");
                return (0);
            }
            else
            {
                print_err("Undefined character on map!");
                return (0);
            }
        }
        tmp = tmp->next;
    }
    if (*is_player_set == false)
    {
        print_err("No character on map!");
        return (0);
    }
    return (1);
}

char **list_to_matrix(t_list *map)
{
    char **matrix;
    t_list *temp;
    size_t i;
    
    matrix = malloc(sizeof(char *) * get_list_size(map) + 1);
    temp = map;
    i = 0;
    while (temp)
    {
        matrix[i] = ft_strdup(temp->content);
        temp = temp->next;
        i++;
    }
    matrix[i] = NULL;
    return (matrix);
}

int handle_map(t_game *game)
{
    size_t max_width;
    int is_player_set;
    is_player_set = false;
    if (!check_rows(game->map , &is_player_set))
        return (0);
    max_width = find_max_width(game->map);
    fill_map_with_two(game->map , max_width);
    game->matrix_map = list_to_matrix(game->map);
    return (1);
}