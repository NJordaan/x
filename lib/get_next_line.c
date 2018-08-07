/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njordaan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:13:28 by njordaan          #+#    #+#             */
/*   Updated: 2018/06/29 13:23:41 by njordaan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*get_content(t_list *l, int fd)
{
	char	*ret;

	while (l)
	{
		if (l->content_size == (size_t)fd)
		{
			ret = (char *)(l->content);
			l->content = ft_strnew(0);
			return (ret);
		}
		l = l->next;
	}
	return (ft_strnew(0));
}

static	void	add_content(t_list **l, char *content, int fd)
{
	t_list *temp;

	temp = *l;
	while (temp)
	{
		if (temp->content_size == (size_t)fd)
		{
			temp->content = ft_strdup(content);
			return ;
		}
		temp = temp->next;
	}
	temp = ft_lstnew(content, ft_strlen(content) + 1);
	temp->content_size = fd;
	ft_lstaddend(l, temp);
}

static	void	handle_overflow(t_list **l, char **overflow, int fd, int *r)
{
	**overflow = '\0';
	(*overflow)++;
	add_content(l, *overflow, fd);
	*r = 1;
}

static	char	*get_line(t_list **list, char *content, int fd, int *r)
{
	char	*store;
	char	*temp;
	char	*nl_pos;

	temp = ft_strnew(BUFF_SIZE);
	while ((*r = read(fd, temp, BUFF_SIZE)) > 0)
	{
		temp[*r] = '\0';
		store = content;
		content = ft_strjoin(store, temp);
		free(store);
		if ((nl_pos = ft_strchr(content, '\n')) != 0)
		{
			handle_overflow(list, &nl_pos, fd, r);
			break ;
		}
	}
	return (content);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	char			*nl_pos;
	char			*content;
	int				r;

	if (!line || fd < 0 || BUFF_SIZE < 1 || (r = read(fd, "", 0)) < 0)
		return (-1);
	if (list)
		content = get_content(list, fd);
	else
		content = ft_strnew(0);
	if ((nl_pos = ft_strchr(content, '\n')) != 0)
		handle_overflow(&list, &nl_pos, fd, &r);
	else
		content = get_line(&list, content, fd, &r);
	*line = content;
	if (ft_strlen(content) == 0)
		return (r > 0 ? 1 : 0);
	return (1);
}
