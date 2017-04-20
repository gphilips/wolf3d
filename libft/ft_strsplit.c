/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:00:39 by gphilips          #+#    #+#             */
/*   Updated: 2016/11/19 15:25:45 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count_w(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[0] != '\0')
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static	char	*ft_get_word(const char *s, char c, int *i)
{
	char	*tab;
	int		j;

	tab = (char *)malloc(sizeof(tab) * (ft_strlen(s)));
	if (!tab)
		return (NULL);
	j = 0;
	while (s[*i] != c && s[*i])
	{
		tab[j] = s[*i];
		j++;
		*i += 1;
	}
	tab[j] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (tab);
}

char			**ft_strsplit(const char *s, char c)
{
	int		nb_word;
	char	**tab;
	int		i;
	int		j;

	if (!s || !c)
		return (NULL);
	nb_word = ft_count_w(s, c);
	tab = (char**)malloc(sizeof(tab) * (nb_word + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (j < nb_word && s[i])
	{
		tab[j] = ft_get_word(s, c, &i);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
