/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:12:25 by tadey             #+#    #+#             */
/*   Updated: 2018/03/15 21:12:35 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*create_room(char *name, int x, int y, int size)
{
	t_room *tmp;

	tmp = (t_room *)malloc(sizeof(t_room));
	tmp->room_name = ft_strdup(name);
	tmp->coord_x = x;
	tmp->coord_y = y;
	tmp->parent_counter = 0;
	tmp->parents = (int *)malloc(sizeof(int) * size);
	return (tmp);
}

t_link	*create_link(char *room_one, char *room_two)
{
	t_link *tmp;

	tmp = (t_link *)malloc(sizeof(t_link));
	tmp->room_one = ft_strdup(room_one);
	tmp->room_two = ft_strdup(room_two);
	tmp->has_been_visited = 0;
	return (tmp);
}

t_ant	*create_ant(t_game *game, int name)
{
	t_ant *tmp;

	tmp = (t_ant *)malloc(sizeof(t_ant));
	tmp->current_pos = find_room(game, game->start->room_name);
	tmp->status = 0;
	tmp->previous_pos = tmp->current_pos;
	tmp->name = name + 1;
	return (tmp);
}
