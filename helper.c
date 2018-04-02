/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:51:42 by tadey             #+#    #+#             */
/*   Updated: 2018/04/01 17:53:11 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_for_end(t_game *game, int *new_parents)
{
	int i;

	i = 0;
	while (new_parents[i] != -1)
	{
		if (ft_strcmp(game->room_data[new_parents[i]]->room_name,
		game->end->room_name) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_then_add(int i, t_game *game)
{
	int m;

	m = 0;
	while (game->duplicate[m] != -1)
	{
		if (game->duplicate[m] == i)
			return (0);
		m++;
	}
	return (1);
}

int	index_of_push(int *array)
{
	int i;

	i = 0;
	while (array[i] != -1)
		i++;
	return (i);
}

int	find_room(t_game *game, char *room)
{
	int i;

	i = 0;
	while (i < game->counter)
	{
		if ((ft_strcmp(game->room_data[i]->room_name, room) == 0))
			return (i);
		i++;
	}
	return (0);
}
