/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:26:24 by wescande          #+#    #+#             */
/*   Updated: 2016/12/01 15:49:57 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static int		fill(int fd, t_buf *buf, char **line)
{
	void	*v_pos;
	char	*pos;
	char	*ans;

	if (buf->pos >= buf->read_ret)
	{
		buf->pos = 0;
		if ((buf->read_ret = read(fd, buf->txt, BUFF_SIZE)) <= 0)
			return (buf->read_ret);
	}
	buf->txt[buf->read_ret + 1] = '\0';
	v_pos = ft_strchr(buf->txt + buf->pos, '\n');
	pos = (v_pos ? (char*)v_pos : buf->txt + buf->read_ret);
	if (!(ans = ft_strnew(pos - buf->txt - buf->pos)))
		return (-1);
	if (!(ans = ft_memcpy(ans, buf->txt + buf->pos, pos - buf->txt - buf->pos)))
		return (-1);
	if (!(*line = ft_strjoinf(*line, ans, 3)))
		return (-1);
	buf->pos = pos - buf->txt + 1;
	buf->newline = 1;
	return (v_pos ? 0 : 1);
}

static void		ft_lstdelif(t_list **s_buf, int fd)
{
	t_list	*l_cur;
	t_list	*l_prev;
	t_list	*l_next;

	l_cur = *s_buf;
	l_prev = NULL;
	l_next = NULL;
	while (l_cur && l_cur->next && ((t_buf *)l_cur->content)->fd != fd)
	{
		l_prev = l_cur;
		l_cur = l_cur->next;
		l_next = l_cur->next;
	}
	if (!l_cur)
		return ;
	ft_memdel((void **)&l_cur);
	if (l_prev)
		l_prev->next = l_next;
	else
		*s_buf = NULL;
}

static t_list	*init(t_list **buf, int fd)
{
	t_list		*link;
	t_list		*l_prev;
	t_buf		*my_buf;

	link = *buf;
	l_prev = NULL;
	while (link)
	{
		l_prev = link;
		if (((t_buf *)link->content)->fd == fd)
			return (link);
		link = link->next;
	}
	if (!(my_buf = (t_buf *)malloc(sizeof(t_buf))))
		return (NULL);
	ft_bzero(my_buf->txt, BUFF_SIZE + 1);
	my_buf->pos = BUFF_SIZE;
	my_buf->read_ret = 0;
	link = ft_lstnew(my_buf, sizeof(t_buf));
	if (l_prev)
		l_prev->next = link;
	else
		*buf = link;
	ft_memdel((void **)&my_buf);
	return (link);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*s_buf = NULL;
	int				val_ret;
	t_list			*c_buf;

	if (fd < 0 || !line || !(c_buf = init(&s_buf, fd)))
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	((t_buf *)c_buf->content)->newline = 0;
	((t_buf *)c_buf->content)->fd = fd;
	val_ret = 1;
	while (val_ret > 0)
		val_ret = fill(fd, c_buf->content, line);
	if (val_ret == -1)
		return (-1);
	if (((t_buf *)c_buf->content)->newline)
		return (1);
	val_ret = ((t_buf *)c_buf->content)->read_ret;
	ft_lstdelif(&s_buf, fd);
	return (val_ret);
}
