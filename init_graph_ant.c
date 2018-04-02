/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph_ant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:53:18 by tadey             #+#    #+#             */
/*   Updated: 2018/04/01 17:54:14 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_graph(t_game *game)
{
	int	*new_parents;
	int	m;
	int	name;

	name = 0;
	m = 0;
	game->duplicate = (int *)malloc(sizeof(int) * game->counter);
	ft_memset((void **)&game->duplicate, -1, game->counter);
	new_parents = (int *)malloc(sizeof(int) * game->counter);
	ft_memset((void **)&new_parents, -1, game->counter);
	new_parents[0] = find_room(game, game->start->room_name);
	while (check_for_end(game, new_parents) == 0)
		get_new_parents(game, &new_parents);
	back_tracking(game, name);
}

void	init_ant(t_game *game, int name)
{
	int i;

	name = 0;
	i = 0;
	game->ant_data = (t_ant **)malloc(sizeof(t_ant *) * game->ant_number);
	while (i < game->ant_number)
	{
		game->ant_data[i] = create_ant(game, i);
		i++;
	}
}
