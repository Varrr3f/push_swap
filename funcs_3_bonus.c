/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:58:09 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:58:11 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_listt	*greate_stack(int *mass, int size)
{
	int		i;
	t_listt	*first;
	t_listt	*new_list;

	i = 0;
	new_list = (t_listt *)malloc(sizeof(t_listt));
	if (!new_list)
		exit(1);
	first = new_list;
	while (i < size)
	{
		if (i < size - 1)
		{
			new_list->next = (t_listt *)malloc(sizeof(t_listt));
			if (!new_list->next)
				exit(1);
		}
		new_list->value = mass[i];
		if (i == size - 1)
			new_list->next = NULL;
		else
			new_list = new_list->next;
		i++;
	}
	return (first);
}

int	number_is_valid_help(char *str, int sign, int size, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			size++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && size == 0)
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			size = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-')
				&& (sign == 0 && size == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (size);
}

void	number_is_valid(char *str)
{
	int	i;
	int	size;
	int	sign;
	int	n;

	i = 0;
	size = 0;
	sign = 0;
	n = ft_atoi(str);
	size = number_is_valid_help(str, sign, size, i);
	if (((n == 0) || (n == -1)) && (size != 1))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	number_or_not(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	separators_before(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}
