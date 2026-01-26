/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keezgi <keezgi@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:52:55 by keezgi            #+#    #+#             */
/*   Updated: 2026/01/26 06:19:42 by keezgi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_map_line(t_game *game, char *line)
{
	if (!game->parse.north_set || !game->parse.south_set ||
		!game->parse.west_set || !game->parse.east_set ||
		!game->parse.floor_set || !game->parse.ceiling_set)
	{
		print_err_exit("Missing textures before map!");
	}
	game->parse.is_map_started = true;
    list_add_back(&game->map, ft_strdup(line) , ft_strlen(line)); 
}

static void	process_line(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
	{
		if (game->parse.is_map_started)
			print_err_exit("Map can't be seperated with newline!");
		return ;
	}
	if (!ft_strncmp(&line[i], "NO ", 3))
		set_texture(&game->parse.north_file, &game->parse.north_set, line, i);
	else if (!ft_strncmp(&line[i], "SO ", 3))
		set_texture(&game->parse.south_file, &game->parse.south_set, line, i);
	else if (!ft_strncmp(&line[i], "WE ", 3))
		set_texture(&game->parse.west_file, &game->parse.west_set, line, i);
	else if (!ft_strncmp(&line[i], "EA ", 3))
		set_texture(&game->parse.east_file, &game->parse.east_set, line, i);
	else if (!ft_strncmp(&line[i], "F ", 2))
		set_rgb(game, line, i + 1, 'F');
	else if (!ft_strncmp(&line[i], "C ", 2))
		set_rgb(game, line, i + 1, 'C');
	else
		handle_map_line(game, line);
}


static void    init_parse_variables(t_game *game)
{
    game->map = NULL;
    game->parse.north_set = false;
    game->parse.south_set = false;
    game->parse.west_set = false;
    game->parse.east_set = false;
    game->parse.floor_set = false;
    game->parse.ceiling_set = false;
    game->parse.is_map_started = false;
}

void	read_file(t_game *game, char *file)
{
	int		fd;
	char	*line;

	init_parse_variables(game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_err_exit("File doesn't have read permission!");
	while ((line = get_next_line(fd)))
	{
		process_line(game, line);
		free(line);
	}
	close(fd);
	if (!game->map)
		print_err_exit("Map not found!");
}