/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:29:58 by keezgi            #+#    #+#             */
/*   Updated: 2025/12/26 13:40:46 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#include "get_next_line/get_next_line.h"


// structs

typedef struct s_parse
{
    bool west_set;
    bool east_set;
    bool north_set;
    bool south_set;
    bool floor_set;
    bool ceiling_set;
    bool is_map_started;
    bool is_player_set;
    char *west_file;
    char *east_file;
    char *north_file;
    char *south_file;
    char *floor_line;
    char *ceiling_line;
    int floor_r;
    int floor_g;
    int floor_b;
    int ceiling_r;
    int ceiling_g;
    int ceiling_b;
} t_parse;

typedef struct s_game
{
    t_parse parse;
} t_game;

typedef struct s_list
{
    char *content;
    struct s_list *next;
} t_list;

// utils
void    print_err(char *str);
void    putstr_err(char *str);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
int	ft_atoi(char *str);
size_t ft_strlen(char *str);

// list utils
void    list_add_back(t_list **list , char *content);

// arg parse
int    arg_parse(char *str);

void    read_file(t_parse *parse, char *file);
#endif