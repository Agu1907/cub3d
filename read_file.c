/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:52:55 by keezgi            #+#    #+#             */
/*   Updated: 2025/12/26 13:48:44 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    read_file(t_parse *parse, char *file)
{
    int     fd;
    char    *line;
    int     i;
    unsigned int    start;
    int counter; // ceiling ve floor icin gerekli

    fd = open(file , O_RDONLY);
    if (fd < 0)
    {
        print_err("File doesn't have read permission!");
        exit(1);
    }
    while ((line = get_next_line(fd)))
    {
        i = 0;
        start = 0;
        while (line[i] == ' ' || line[i] == '\t')
            i++;
        if (line[i] == 'N' && line[i + 1] == 'O' && parse->is_map_started == false && parse->north_set == false)
        {
            i += 2;
            while (line[i] == ' ' || line[i] == '\t')
                i++;
            start = i; // burada bir newline ve null kontrolu aklinda bulunsun
            while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
                i++;
            parse->north_file = ft_substr(line , start , i - start);
            while (line[i] && line[i] != '\n')
            {
                if (line[i] != ' ' && line[i] != '\t')
                {
                    print_err("Unexpected data after texture path!");
                    exit(1);
                }
                i++;
            }
            parse->north_set = true;
            continue;
        }
        else if (line[i] == 'S' && line[i + 1] == 'O' && parse->is_map_started == false && parse->south_set == false)
        {
            i += 2;
            while (line[i] == ' ' || line[i] == '\t')
                i++;
            start = i; // burada bir newline ve null kontrolu aklinda bulunsun
            while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
                i++;
            parse->south_file = ft_substr(line , start , i - start);
            while (line[i] && line[i] != '\n')
            {
                if (line[i] != ' ' && line[i] != '\t')
                {
                    print_err("Unexpected data after texture path!");
                    exit(1);
                }
                i++;
            }
            parse->south_set = true;
            continue;
        }
        else if (line[i] == 'E' && line[i + 1] == 'A' && parse->is_map_started == false && parse->east_set == false)
        {
            i += 2;
            while (line[i] == ' ' || line[i] == '\t')
                i++;
            start = i; // burada bir newline ve null kontrolu aklinda bulunsun
            while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
                i++;
            parse->east_file = ft_substr(line , start , i - start);
            while (line[i] && line[i] != '\n')
            {
                if (line[i] != ' ' && line[i] != '\t')
                {
                    print_err("Unexpected data after texture path!");
                    exit(1);
                }
                i++;
            }
            parse->east_set = true;
            continue;
        }
        else if (line[i] == 'W' && line[i + 1] == 'E' && parse->is_map_started == false && parse->west_set == false)
        {
            i += 2;
            while (line[i] == ' ' || line[i] == '\t')
                i++;
            start = i; // burada bir newline ve null kontrolu aklinda bulunsun
            while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
                i++;
            parse->west_file = ft_substr(line , start , i - start);
            while (line[i] && line[i] != '\n')
            {
                if (line[i] != ' ' && line[i] != '\t')
                {
                    print_err("Unexpected data after texture path!");
                    exit(1);
                }
                i++;
            }
            parse->west_set = true;
            continue;
        }
        else if (line[i] == 'F' && parse->is_map_started == false && parse->floor_set == false)
        {
            i++;
            while (line[i] == ' ' || line[i] == '\t')
                i++;
            start = i;
            while (line[i] != '\n')
                i++;
            parse->floor_line = ft_substr(line , start , i - start);
            i = 0;
            counter = 0;
            while (line[start + i])
            {
                if (line[start + i] == ',')
                {
                    if (line[start + i + 1] && line[start + i + 1] == ',')
                    {
                        print_err("There is a consecutive comma in the color range!");
                        exit (1);
                    }
                    counter++;
                }
                i++;
            }
            if (counter != 2)
            {
                print_err("There are not enough arguments for RGB!");
                exit (1);
            }
            char **floor_data = ft_split(parse->floor_line , ',');
            if (!floor_data[0] || !floor_data[1] || !floor_data[2])
            {
                print_err("Missing RGB value!");
                exit(1);
            }
            parse->floor_r = ft_atoi(floor_data[0]);
            parse->floor_g = ft_atoi(floor_data[1]);
            parse->floor_b = ft_atoi(floor_data[2]);

            if (parse->floor_r == -1 || parse->floor_g == -1 || parse->floor_b == -1)
            {
                print_err("Invalid color value, (must be between 0-255)!");
                exit (1);
            }
            parse->floor_set = true;
            counter = 0;
            continue;
        }
        else if (line[i] == 'C' && parse->is_map_started == false && parse->ceiling_set == false)
        {
            i++;
            while (line[i] == ' ' || line[i] == '\t')
                i++;
            start = i;
            while (line[i] != '\n')
                i++;
            parse->ceiling_line = ft_substr(line , start , i - start);
            i = 0;
            counter = 0;
            while (line[start + i])
            {
                if (line[start + i] == ',')
                {
                    if (line[start + i + 1] && line[start + i + 1] == ',')
                    {
                        print_err("There is a consecutive comma in the color range!");
                        exit (1);
                    }
                    counter++;
                }
                i++;
            }
            if (counter != 2)
            {
                print_err("There are not enough arguments for RGB!");
                exit (1);
            }
            char **ceiling_data = ft_split(parse->ceiling_line , ',');
            if (!ceiling_data[0] || !ceiling_data[1] || !ceiling_data[2])
            {
                print_err("Missing RGB value!");
                exit(1);
            }
            parse->ceiling_r = ft_atoi(ceiling_data[0]);
            parse->ceiling_g = ft_atoi(ceiling_data[1]);
            parse->ceiling_b = ft_atoi(ceiling_data[2]);

            if (parse->ceiling_r == -1 || parse->ceiling_g == -1 || parse->ceiling_b == -1)
            {
                print_err("Invalid color value, (must be between 0-255)!");
                exit (1);
            }
            parse->ceiling_set = true;
            counter = 0;
            continue; 
        }
    }
}