/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:54:00 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:54:02 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_duplicate_check(t_mass *arr, t_stacks *stacks)
{
	int			*dup;

	dup = (int *)malloc(sizeof(int) * (arr->size));
	if (!dup)
		exit(1);
	dup = ft_intcpy(dup, arr->a, arr->size);
	quick_sort(dup, 0, arr->size - 1);
	ft_search_duplicate(dup, arr->size - 1);
	stacks->len_a = arr->size;
	stacks->len_b = 0;
	stacks->min = dup[0];
	stacks->mid = dup[arr->size / 2];
	stacks->max = dup[arr->size - 1];
	free(dup);
}

void	ft_free_stack(t_stacks *stacks)
{
	int		i;
	t_listt	*buff;

	i = 0;
	while (i < stacks->len_a)
	{
		buff = stacks->a;
		stacks->a = stacks->a->next;
		free(buff);
		i++;
	}
	i = 0;
	while (i < stacks->len_b)
	{
		buff = stacks->b;
		stacks->b = stacks->b->next;
		free(buff);
		i++;
	}
}

void	ft_null(t_stacks *stacks, t_mass *arr)
{
	arr->size = 0;
	stacks->len_a = 0;
	stacks->len_b = 0;
	stacks->min = 0;
	stacks->max = 0;
	stacks->mid = 0;
	stacks->a = NULL;
	stacks->b = NULL;
}

void	init_stack(t_mass *arr, t_stacks *stacks)
{
	stacks->b = NULL;
	stacks->a = greate_stack(arr->a, arr->size);
}

int	parcer(int argc, char **argv)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	while (i < argc)
	{
		if (separators_before(argv[i]))
		{
			number_or_not(argv[i]);
			number_is_valid(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}
