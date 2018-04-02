/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:36:03 by tadey             #+#    #+#             */
/*   Updated: 2018/04/01 17:44:35 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	back_tracking(t_game *game, int name)
{
	int index;
	int size_of_path;
	int *store;

	size_of_path = 1;
	store = (int *)malloc(sizeof(int) * game->counter);
	ft_memset((void **)&store, -1, game->counter);
	index = find_room(game, game->end->room_name);
	store[0] = find_room(game, game->end->room_name);
	while (index != find_room(game, game->start->room_name))
	{
		index = game->room_data[index]->parents[0];
		store[size_of_path] = index;
		size_of_path++;
	}
	init_ant(game, name);
	while (check_status(game))
		moving_ants(game, store, size_of_path);
	free(store);
}

void	increment_pos(int *store, int size_of_path, t_ant *ant, t_game *game)
{
	int counter;

	counter = 0;
	size_of_path--;
	while (size_of_path >= 0)
	{
		if (store[size_of_path] == ant->current_pos)
		{
			ant->current_pos = store[size_of_path - 1];
			printing(ant);
			ft_putstr(game->room_data[ant->current_pos]->room_name);
			ft_putstr(" ");
			if (ant->current_pos == store[0])
				ant->status = 2;
			else
				ant->status = 1;
			return ;
		}
		size_of_path--;
	}
}

void	printing(t_ant *ant)
{
	ft_putstr("L");
	ft_putnbr(ant->name);
	ft_putchar('-');
}

void	moving_ants(t_game *game, int *store, int size_of_path)
{
	int i;
	int got_idle;

	i = 0;
	got_idle = 0;
	while (i < game->ant_number)
	{
		if (game->ant_data[i]->status == 0 && got_idle == 0)
		{
			increment_pos(store, size_of_path, game->ant_data[i], game);
			got_idle = 1;
		}
		else if (game->ant_data[i]->status == 1)
			increment_pos(store, size_of_path, game->ant_data[i], game);
		i++;
	}
	ft_putchar('\n');
}

int		check_status(t_game *game)
{
	int i;

	i = 0;
	while (i < game->ant_number)
	{
		if (game->ant_data[i]->status != 2)
			return (1);
		i++;
	}
	return (0);
}
