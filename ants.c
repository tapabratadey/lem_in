/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:05:34 by tadey             #+#    #+#             */
/*   Updated: 2018/04/01 07:30:07 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_ants(t_game *game)
{
	int i;

	i = 0;
	while (game->map && game->map[i])
	{
		if ((ft_isdigit(game->map[i]) == 0) && (game->map[i] != '\n'))
			error("Ant number has to be positive and a numeric number.");
		i++;
	}
	game->ant_number = ft_atoi(game->map);
	if ((ft_atoi(game->map) <= 0) || (ft_atoi(game->map) > 2147483647))
		error("The number of ants must be between 1 to 2147483647 ");
}
