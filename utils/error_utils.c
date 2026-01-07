/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:35:15 by keezgi            #+#    #+#             */
/*   Updated: 2025/12/19 17:19:05 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    print_err(char *str)
{
    putstr_err("Error");
    putstr_err(str);
}

void    putstr_err(char *str)
{
    int i;
    i = 0;

    while (str[i])
    {
        write(2 , &str[i] , 1);
        i++;
    }
    write(2 , "\n" , 1);
}