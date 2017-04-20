/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:03:07 by gphilips          #+#    #+#             */
/*   Updated: 2016/11/19 15:26:54 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(elem->content = (void*)malloc(sizeof(content) * content_size)))
	{
		ft_memdel((void**)&elem);
		return (NULL);
	}
	if (content)
	{
		elem->content = ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
		elem->next = NULL;
	}
	else
	{
		elem->content_size = 0;
		elem->content = NULL;
		elem->next = NULL;
	}
	return (elem);
}
