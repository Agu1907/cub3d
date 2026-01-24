/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:30:52 by keezgi            #+#    #+#             */
/*   Updated: 2026/01/25 01:31:30 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_map_list(t_list *map)
{
    t_list  *tmp;
    int     i;

    tmp = map;
    i = 0;
    printf("\n------- MAP LIST CONTENT -------\n");
    while (tmp)
    {
        printf("Node [%d] | Width: %zu | Length: %zu | Content: %s", 
               i, tmp->width, tmp->length, tmp->content);
        if (tmp->content && tmp->content[ft_strlen(tmp->content) - 1] != '\n')
            printf("\n");

        tmp = tmp->next;
        i++;
    }
    printf("--------------------------------\n");
}


int main (int ac, char **av)
{
    t_game game;
    if (ac == 2)
    {
        arg_parse(av[1]);
        read_file(&game ,av[1]);
        if(!handle_map(&game))
        {
            // free hata kontrolu eklenecek (garbage collector freesi)
            return (1);
        }
        print_map_list(game.map);
    }
    else
    {
        print_err("Program must take 2 argument!");
        return (1);
    }
}
