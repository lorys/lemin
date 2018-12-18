#include "lem_in.h"

static int	find_path_recursive(t_tube *room, t_tube *from, t_infos *infos, int n)
{
	t_paths	*tmp;

	if (room == infos->start)
		return (1);
	tmp = room->links;
	while (tmp)
	{
		if (tmp->room == from)
		{
			tmp = tmp->next;
			continue ;
		}
		find_path_recursive(tmp->room, room, infos, n + 1);
		room->vu = n;
		tmp = tmp->next;
	}
	return (0);
}

int			find_paths(t_tube *room_list, t_infos *infos)
{
	(void)room_list;
	if (find_path_recursive(infos->end, infos->end, infos, 0))
		return (1);
	return (0);
}