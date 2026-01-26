/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*-                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:30:52 by keezgi            #+#    #+#             */
/*   Updated: 2026/01/25 17:40:37 by keezgi           ###   ########.fr       */
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

void print_map_debug(char **map)
{
    int i;

    i = 0;
    if (!map)
    {
        printf("Error: Map is NULL\n");
        return ;
    }
    printf("\n--- MAP DEBUG START ---\n");
    while (map[i])
    {
        // Eğer satır sonlarında hala \n varsa alt satıra kaymış gibi görünebilir.
        // Amaç satırın bittiği yeri görmektir.
        printf("[%d] |%s|\n", i, map[i]);
        i++;
    }
    printf("--- MAP DEBUG END ---\n\n");
}


int    arg_parse(char *str)
{
    size_t pos;

    pos = ft_strlen(str);
    if (pos < 5 || ft_strcmp(&str[pos - 4] , ".cub"))
    {
        print_err("File extension doesn't end with .cub");
        exit(1);
    }
    return (0);
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
        print_map_debug(game.matrix_map);
    }
    else
    {
        print_err("Program must take 2 argument!");
        return (1);
    }
}