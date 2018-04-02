/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:09:52 by tadey             #+#    #+#             */
/*   Updated: 2018/04/01 18:15:22 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_map(t_game *game)
{
	char *line;

	line = NULL;
	while ((game->result = get_next_line(0, &line)) > 0)
	{
		if (ft_strcmp(line, "") == 0)
			error("Map can't be empty.");
		game->bytes_read += game->result;
		if (game->map == NULL)
			game->map = ft_strjoin(line, "\n");
		if (game->num == 0)
			check_ants(game);
		else
			storing_map(line, game);
		game->num++;
		if (line)
			free(line);
	}
	if (game->num == 0)
		error("Nothing to read");
	help(game);
	return (0);
}

void	storing_map(char *line, t_game *game)
{
	if ((ft_strchr(line, ' ') != NULL) && (ft_strchr(line, '#') == NULL))
		game->counter++;
	if (ft_strchr(line, '-') != NULL)
		game->link_counter++;
	game->store = ft_strjoin(game->map, line);
	game->tmp = ft_strjoin(game->store, "\n");
	free(game->map);
	free(game->store);
	game->map = game->tmp;
}

void	init(t_game *game)
{
	game->is_end = 0;
	game->is_start = 0;
	game->start_i = 0;
	game->end_i = 0;
}

void	help(t_game *game)
{
	game->lines = NULL;
	game->room_data = (t_room **)malloc(sizeof(t_room *) * game->counter);
	game->link_data = (t_link **)malloc(sizeof(t_link *) * game->link_counter);
	if ((ft_strstr(game->map, "##start") == 0) || (ft_strstr(game->map,
					"##end") == 0))
		error("Map should have a ##start and ##end.");
	game->lines = ft_strsplit(game->map, '\n');
	init(game);
	check_rooms(game);
	check_links(game);
	check_duplicate_rooms(game);
	check_duplicate_coords(game);
}
