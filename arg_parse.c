/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:31:46 by keezgi            #+#    #+#             */
/*   Updated: 2026/01/25 16:54:27 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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