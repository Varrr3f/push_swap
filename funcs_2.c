/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:55:43 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:55:45 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	str_to_mass(int argc, char **argv, t_mass *arr)
{
	int		a;
	int		i;
	int		size;
	int		*mass;
	char	**str;

	i = 1;
	while (i < argc)
	{
		a = -1;
		size = ft_countword(argv[i]);
		str = ft_split(argv[i], ' ');
		mass = (int *)malloc(sizeof(int) * (size));
		while (size > ++a)
		{
			mass[a] = ft_atoi(str[a]);
			free(str[a]);
		}
		free(str);
		ft_stacking(arr, mass, size);
		i++;
	}
}

int	*ft_intcpy(int *dst, const int *src, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	ft_countword(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			count++;
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

void	ft_search_duplicate(const int *dup, int count)
{
	int	i;

	i = 0;
	while (i != count)
	{
		if (dup[i] == dup[i + 1])
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
}

void	ft_stacking(t_mass *arr, int *buff, int count)
{
	int	i;

	i = -1;
	while (count > ++i)
		arr->a[arr->size + i] = buff[i];
	arr->size += count;
	free(buff);
}
