/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:36:01 by seongjki          #+#    #+#             */
/*   Updated: 2021/10/14 15:02:03 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_collect	*so_lstnew(int x, int y)
{
	t_collect	*lst;

	lst = (t_collect *)malloc(sizeof(t_collect));
	if (!lst)
		return (0);
	lst->x = x;
	lst->y = y;
	lst->next = 0;
	return (lst);
}

t_collect	*so_lstfind(t_collect **lst, int x, int y)
{
	t_collect	*tmp;
	t_collect	*new;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (tmp);
		tmp = tmp->next;
	}
	new = so_lstnew(x, y);
	new->next = *lst;
	*lst = new;
	return (new);
}

void	so_clear(t_collect **lst, t_collect *target)
{
	t_collect	*current;

	current = *lst;
	if (current->x == target->x && current->y == target->y)
	{
		*lst = current->next;
		free(target);
		return ;
	}
	while (current->next->x != target->x || current->next->y != target->y)
		current = current->next;
	current->next = target->next;
	free(target);
	return ;
}

int	so_lstsize(t_collect *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
