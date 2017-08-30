/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 13:45:04 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 00:37:39 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** list_merge - join two lists
** @add: the new list to add.
** @head: the place to add it in the first list.
*/
inline void		list_merge(t_lx *add, t_lx *head)
{
	if (!list_empty(add))
		list_merge_only(add, head);
}