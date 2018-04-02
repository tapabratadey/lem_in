/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:49:51 by tadey             #+#    #+#             */
/*   Updated: 2018/04/01 17:50:45 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	game->result = 0;
	game->num = 0;
	game->link_counter = 0;
	game->counter = 0;
	game->map = NULL;
	game->result = read_map(game);
	ft_putstr(game->map);
	ft_putchar('\n');
	init_graph(game);
	return (0);
}

int	error(char *str)
{
	ft_putstr(str);
	exit(0);
}
