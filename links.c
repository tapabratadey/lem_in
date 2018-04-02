/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:05:59 by tadey             #+#    #+#             */
/*   Updated: 2018/04/01 18:09:54 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_links(t_game *game)
{
	int		i;
	char	**temp;

	temp = NULL;
	i = 0;
	store_links(i, game, temp);
	check_link_valid(game);
}

void	store_links(int i, t_game *game, char **temp)
{
	int j;

	game->ugh = 0;
	j = 0;
	while (game->lines[i])
	{
		if (ft_strchr(game->lines[i], '-') != NULL)
			game->ugh = 1;
		if (ft_strchr(game->lines[i], '-') != NULL)
		{
			temp = ft_strsplit(game->lines[i], '-');
			if (ft_strcmp(temp[0], temp[1]) == 0)
				error("Rooms can't link to each other.");
			game->link_data[j] = create_link(temp[0], temp[1]);
			j++;
			if (temp)
				free_array((void **)temp);
		}
		i++;
	}
	if (game->ugh != 1)
		error("No links available");
}

void	check_link_valid(t_game *game)
{
	int i;
	int j;

	i = 0;
	game->match_room_one = 0;
	game->match_room_two = 0;
	while (i < game->link_counter)
	{
		j = 0;
		game->match = 0;
		game->match_second = 0;
		check_for_no_solution(game, i);
		while (j < game->counter)
		{
			check_for_dup_link(game, i, j);
			j++;
		}
		if (game->match != 1 || game->match_second != 1)
			error("Room names doesn't match.");
		i++;
	}
	if (game->match_room_one != 1 || game->match_room_two != 1)
		error("No solution");
}

void	check_for_no_solution(t_game *game, int i)
{
	if ((ft_strcmp(game->link_data[i]->room_one, game->end->room_name) == 0) ||
		(ft_strcmp(game->link_data[i]->room_one, game->start->room_name) == 0))
		game->match_room_one = 1;
	if ((ft_strcmp(game->link_data[i]->room_two, game->end->room_name) == 0) ||
		(ft_strcmp(game->link_data[i]->room_two, game->start->room_name) == 0))
		game->match_room_two = 1;
}

void	check_for_dup_link(t_game *game, int i, int j)
{
	if ((ft_strcmp(game->link_data[i]->room_one,
	game->room_data[j]->room_name) == 0))
		game->match = 1;
	if ((ft_strcmp(game->link_data[i]->room_two,
	game->room_data[j]->room_name) == 0))
		game->match_second = 1;
}
