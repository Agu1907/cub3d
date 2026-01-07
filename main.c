/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:30:52 by keezgi            #+#    #+#             */
/*   Updated: 2025/12/23 14:16:52 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (int ac, char **av)
{
    t_game game;
    (void)ac;
    if (ac == 2)
    {
        arg_parse(av[1]);
        read_file(&game.parse, av[1]);
    }
    else
        print_err("Program must take 2 argument!");
}