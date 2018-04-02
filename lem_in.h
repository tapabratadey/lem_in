/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:02:11 by tadey             #+#    #+#             */
/*   Updated: 2018/04/01 18:04:20 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# define BUFF_SIZE 32
# define SIZE 50

typedef	struct	s_room
{
	char	*room_name;
	int		coord_x;
	int		coord_y;
	int		*parents;
	int		parent_counter;
}				t_room;

typedef	struct	s_ant
{
	int	name;
	int	current_pos;
	int	previous_pos;
	int	status;
}				t_ant;

typedef	struct	s_link
{
	char	*room_one;
	char	*room_two;
	int		has_been_visited;
}				t_link;

typedef	struct	s_game
{
	int		result;
	int		num;
	char	*map;
	char	*store;
	char	*tmp;
	int		ant_number;
	int		counter;
	t_room	**room_data;
	t_room	*start;
	t_room	*end;
	t_link	**link_data;
	t_ant	**ant_data;
	int		check;
	char	*file;
	int		bytes_read;
	int		is_end;
	int		is_start;
	int		start_i;
	int		end_i;
	int		i;
	char	**lines;
	int		link_counter;
	int		*duplicate;
	int		store_counter;
	int		ant_name;
	int		*path;
	int		parent_i;
	int		match_room_one;
	int		match_room_two;
	int		match;
	int		match_second;
	int		ugh;
	int		*new_children;
}				t_game;

int				main(void);
int				error(char *str);
int				read_map(t_game *game);
int				get_next_line(int const fd, char **line);
void			check_map(t_game *game);
void			check_rooms(t_game *game);
void			check_ants(t_game *game);
t_room			*create_room(char *name, int x, int y, int size);
void			check_duplicate_rooms(t_game *game);
void			check_coords(char **temp);
void			check_strings(char **temp);
void			check_empty(t_game *game);
void			check_duplicate_coords(t_game *game);
void			loop_empty(t_game *game);
void			start_end(t_game *game, int i);
void			check_start_end(t_game *game, int i, int j);
void			help(t_game *game);
t_link			*create_link(char *room_one, char *room_two);
void			check_links(t_game *game);
void			check_duplicate_links(t_game *game);
void			check_link_valid(t_game *game);
void			init_graph(t_game *game);
int				find_room(t_game *game, char *room);
int				check_for_end(t_game *game, int *new_parents);
void			get_new_parents(t_game *game, int **new_parents);
void			check_for_dup(t_game *game);
int				check_then_add(int i, t_game *game);
void			back_tracking(t_game *game, int name);
int				check_for_start(t_game *game);
void			traverse_back(t_game *game);
t_ant			*create_ant(t_game *game, int name);
void			init_ant(t_game *game, int name);
void			moving_ants(t_game *game, int *store, int size_of_path);
void			increment_pos(int *store, int size_of_path, t_ant *ant,
				t_game *game);
int				check_status(t_game *game);
void			parents_for_room_two(t_game *game, int i, int j, int
				**new_parents);
void			parents_for_room_one(t_game *game, int i, int j, int
				**new_parents);
void			check_for_children_room_one(int i, int j, t_game *game,
				int **new_parents);
void			check_for_children_room_two(int i, int j, t_game *game,
				int **new_parents);
void			check_if_visited(int i, int j, t_game *game, int
				**new_parents);
void			printing(t_ant *ant);
void			store_links(int i, t_game *game, char **temp);
void			check_for_no_solution(t_game *game, int i);
void			check_for_dup_link(t_game *game, int i, int j);
void			init(t_game *game);
void			split_rooms(t_game *game, char **temp, int i, int j);
void			storing_map(char *line, t_game *game);
int				index_of_push(int *array);
#endif
