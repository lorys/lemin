#include "lem_in.h"
#include "parser.h"

static t_paths	*create_link(t_tube *room)
{
	t_paths		*new;

	if (!(new = (t_paths *)ft_memalloc(sizeof(*new))) || !room)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->room = room;
	return (new);
}

static void	append_links(t_paths **links, t_paths *to_add)
{
	t_paths	*tmp;

	if (!links || !to_add)
		return ;
	if (!(*links))
	{
		*links = to_add;
		return ;
	}
	tmp = *links;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = to_add;
	to_add->prev = tmp;
}

void		make_tube(char *line, t_tube *room_list)
{
	char	**split_tmp;
	t_tube	*room_first;
	t_tube	*room_second;

	split_tmp = ft_strsplit(line, '-');
	room_first = find_room(split_tmp[0], room_list);
	room_second = find_room(split_tmp[1], room_list);
	if (room_first && room_second)
	{
		append_links(&room_first->links, create_link(room_second));
		append_links(&room_second->links, create_link(room_first));
	}
	free_char_tab(split_tmp);
}
