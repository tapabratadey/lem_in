/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parents_for.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:10:37 by tadey             #+#    #+#             */
/*   Updated: 2018/04/01 18:11:55 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parents_for_room_one(t_game *game, int i, int j, int **new_parents)
{
	game->new_children[j] = find_room(game, game->link_data[i]->room_two);
	game->link_data[i]->has_been_visited = 1;
	game->room_data[game->new_children[j]]->parents[game->room_data[game->
		new_children[j]]->parent_counter] = (*new_parents)[game->parent_i];
	game->room_data[game->new_children[j]]->parent_counter++;
}

void	parents_for_room_two(t_game *game, int i, int j, int **new_parents)
{
	game->new_children[j] = find_room(game, game->link_data[i]->room_one);
	game->link_data[i]->has_been_visited = 1;
	game->room_data[game->new_children[j]]->parents[game->room_data[game->
		new_children[j]]->parent_counter] = (*new_parents)[game->parent_i];
	game->room_data[game->new_children[j]]->parent_counter++;
}
