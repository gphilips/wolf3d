/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:00:21 by gphilips          #+#    #+#             */
/*   Updated: 2016/11/19 15:25:35 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_fullblank(char const *s)
{
	size_t	len;
	int		i;

	len = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
		len--;
	}
	if (len == 0 || i + 1 == '\0')
		return (1);
	else
		return (0);
}

unsigned int		ft_start_word(char const *s)
{
	unsigned int	i;
	unsigned int	start;

	i = 0;
	start = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		start++;
		i++;
	}
	return (start);
}

unsigned int		ft_end_word(char const *s)
{
	unsigned int	end;
	unsigned int	i;

	end = 0;
	i = 0;
	while (s[i])
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		end++;
		i--;
	}
	return (end);
}

char				*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	char			*tab;
	size_t			wordlen;

	if (!s)
		return (NULL);
	if (ft_fullblank(s) == 1)
		return (ft_strdup(""));
	i = 0;
	start = ft_start_word(s);
	end = ft_end_word(s);
	wordlen = ft_strlen(s) - start - end;
	tab = ft_strsub(s, start, wordlen);
	return (tab);
}
