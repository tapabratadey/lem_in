/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_parents.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:45:45 by tadey             #+#    #+#             */
/*   Updated: 2018/04/01 17:49:19 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_new_parents(t_game *game, int **new_parents)
{
	int i;
	int j;

	j = 0;
	game->parent_i = 0;
	game->new_children = (int *)malloc(sizeof(int) * game->counter);
	ft_memset((void **)&game->new_children, -1, game->counter);
	while ((*new_parents)[game->parent_i] != -1)
	{
		i = 0;
		while (i < game->link_counter)
		{
			check_if_visited(i, &j, game, new_parents);
			i++;
		}
		game->parent_i++;
	}
	check_for_dup(game);
	free(*new_parents);
	*new_parents = game->new_children;
}

void	check_if_visited(int i, int *j, t_game *game, int **new_parents)
{
	if (game->link_data[i]->has_been_visited == 0)
	{
		check_for_children_room_one(i, j, game, new_parents);
		check_for_children_room_two(i, j, game, new_parents);
	}
}

void	check_for_dup(t_game *game)
{
	int k;
	int m;
	int add_it;

	k = 0;
	while (game->new_children[k] != -1)
	{
		m = 0;
		add_it = 1;
		while (game->duplicate[m] != -1)
		{
			if (game->new_children[k] == game->duplicate[m])
				add_it = 0;
			m++;
		}
		if (add_it == 1)
			game->duplicate[index_of_push(game->duplicate)] =
				game->new_children[k];
		k++;
	}
}

void	check_for_children_room_one(int i, int *j, t_game *game,
		int **new_parents)
{
	if (ft_strcmp(game->link_data[i]->room_one, game->room_data[(*new_parents)
				[game->parent_i]]->room_name) == 0)
	{
		if (check_then_add(find_room(game, game->link_data[i]->room_two),
					game) == 1)
		{
			parents_for_room_one(game, i, *j, new_parents);
			(*j)++;
		}
	}
}

void	check_for_children_room_two(int i, int *j, t_game *game,
		int **new_parents)
{
	if (ft_strcmp(game->link_data[i]->room_two, game->room_data[(*new_parents)
				[game->parent_i]]->room_name) == 0)
	{
		if (check_then_add(find_room(game, game->link_data[i]->room_one),
					game) == 1)
		{
			parents_for_room_two(game, i, *j, new_parents);
			(*j)++;
		}
	}
}
