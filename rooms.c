/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:06:21 by tadey             #+#    #+#             */
/*   Updated: 2018/04/01 18:19:03 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_rooms(t_game *game)
{
	int		i;
	int		j;
	char	**temp;

	temp = NULL;
	i = 0;
	j = 0;
	split_rooms(game, temp, i, j);
	if (!game->end || !game->start)
		error("There has to be atleast a start or end room.");
}

void	split_rooms(t_game *game, char **temp, int i, int j)
{
	while (game->lines[i])
	{
		start_end(game, i);
		if (i != 0 && (ft_strchr(game->lines[i], ' ') != NULL) &&
			(ft_strchr(game->lines[i], '#') == NULL))
		{
			temp = ft_strsplit(game->lines[i], ' ');
			if (temp[3])
				error("There can only be two coordinates.");
			if (ft_strchr(temp[0], 'L') != NULL)
				error("Rooms can't be name L.");
			check_coords(temp);
			game->room_data[j] = create_room(temp[0], ft_atoi(temp[1]),
			ft_atoi(temp[2]), game->counter);
			check_start_end(game, i, j);
			j++;
			if (temp)
				free_array((void **)temp);
		}
		if ((i != 0) && (ft_strchr(game->lines[i], '-') == NULL) &&
			(ft_strchr(game->lines[i], '#') == NULL) &&
			(ft_strchr(game->lines[i], ' ') == NULL))
			error("stop fucking around");
		i++;
	}
}

void	start_end(t_game *game, int i)
{
	if (ft_strcmp(game->lines[i], "##start") == 0)
	{
		game->is_start = 1;
		game->start_i = i;
	}
	if (ft_strcmp(game->lines[i], "##end") == 0)
	{
		game->is_end = 1;
		game->end_i = i;
	}
}

void	check_duplicate_rooms(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->counter)
	{
		j = 0;
		while (j < game->counter)
		{
			if ((i != j) && (ft_strcmp(game->room_data[i]->room_name,
			game->room_data[j]->room_name) == 0))
				error("Rooms can't have duplicate names.");
			j++;
		}
		i++;
	}
}
