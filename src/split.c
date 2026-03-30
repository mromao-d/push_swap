/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:00:41 by mromao-s          #+#    #+#             */
/*   Updated: 2026/03/16 20:32:16 by mromao-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cntwords(char *wrd, char sep)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (wrd[i])
	{
		if (wrd[i] != sep)
		{
			nb++;
			while (wrd[i] && wrd[i] != sep)
				i++;
		}
		else
			i++;
	}
	return (nb);
}

int	ft_len_arg(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

char	*ft_populate(char *from, char *to, char sep)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (from[++i] == sep)
		;
	while (from[i] && from[i] != sep)
		to[j++] = from[i++];
	to[j] = 0;
	return (to);
}

void	*ft_free(char **splited)
{
	size_t	i;

	i = 0;
	if (*splited == NULL)
		return (NULL);
	while (splited[i] != NULL)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	return (NULL);
}

char	**ft_split(char *argv)
{
	char	**out;
	int		wrds;
	int		i;

	if (!argv || !argv[0])
		return (0);
	wrds = ft_cntwords(argv, ' ');
	if (!wrds)
		return (NULL);
	out = malloc(sizeof(char *) * (wrds + 1));
	if (!out)
		return (0);
	i = -1;
	while (++i < wrds)
	{
		while (*argv == ' ')
			argv++;
		out[i] = malloc(sizeof(char) * (ft_len_arg(argv, ' ') + 1));
		if (!out[i])
			return (ft_free(out));
		out[i] = ft_populate(argv, out[i], ' ');
		argv += ft_len_arg(argv, ' ');
	}
	out[i] = NULL;
	return (out);
}
