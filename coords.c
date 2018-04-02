/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:05:47 by tadey             #+#    #+#             */
/*   Updated: 2018/04/01 07:37:02 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_coords(char **temp)
{
	int i;
	int j;

	j = 1;
	if ((temp[1] == NULL) || (temp[2] == NULL))
		error("Room coordinates can't be empty.");
	while (j <= 2)
	{
		i = -1;
		while (temp[j][++i])
		{
			if ((ft_isdigit(temp[j][i]) == 0) || (ft_atoi(&temp[j][i]) < 0)
					|| (ft_atoi(&temp[j][i]) > 30))
				error("Coords has to be between 0 and 30.");
		}
		j++;
	}
}

void	check_duplicate_coords(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->counter)
	{
		j = 0;
		while (j < game->counter)
		{
			if ((i != j) && ((game->room_data[i]->coord_x ==
							game->room_data[j]->coord_x) && (game->room_data[i]
								->coord_y == game->room_data[j]->coord_y)))
				error("Coordinates can't be duplicate");
			j++;
		}
		i++;
	}
}

void	check_start_end(t_game *game, int i, int j)
{
	if (game->is_start == 1)
	{
		if (game->start_i + 1 != i)
			error("Bad start coordinates.");
		game->start = game->room_data[j];
		game->is_start = 0;
	}
	if (game->is_end == 1)
	{
		if (game->end_i + 1 != i)
			error("Bad end coordinates.");
		game->end = game->room_data[j];
		game->is_end = 0;
	}
}
