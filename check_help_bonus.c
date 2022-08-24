/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_help_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:14:07 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/14 13:14:10 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_sjoin_help(char *ret, char n)
{
	ret = (char *)malloc(2);
	ret[0] = n;
	ret[1] = 0;
	return (ret);
}

char	*ft_sjoin(char *line, char n)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = NULL;
	if (!line)
		ret = ft_sjoin_help(ret, n);
	else
	{
		while (line[i])
			i++;
		ret = (char *)malloc(i + 2);
		while (j < i)
		{
			ret[j] = line[j];
			j++;
		}
		ret[j] = n;
		ret[j + 1] = 0;
	}
	free(line);
	return (ret);
}

int	get_next_line_ex(char **line)
{
	char	*str;
	char	n;

	str = NULL;
	n = 0;
	if (str == NULL)
		str = ft_sjoin(str, '\0');
	while (read(0, &n, 1) && n != '\n')
		str = ft_sjoin(str, n);
	*line = str;
	return (n == '\n');
}
