/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:57:40 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:57:43 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mass_is_sorted(t_mass *arr)
{
	int	i;

	i = 0;
	while (i < (arr->size - 1))
	{
		if (arr->a[i] > arr->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	mass_sirc_sorted(t_mass *arr)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < arr->size)
	{
		if (arr->a[i] > arr->a[(i + 1) % arr->size])
			ret++;
		i++;
	}
	if (ret <= 1)
		return (1);
	else
		return (0);
}

int	find_max(t_listt *s)
{
	int	max;

	max = s->value;
	while (s)
	{
		if (s->value > max)
			max = s->value;
		s = s->next;
	}
	return (max);
}

void	sort_3(t_stacks *stacks)
{
	int	max;

	max = find_max(stacks->a);
	if (stacks->len_a == 1)
		return ;
	else if (stacks->len_a == 2)
	{
		if (stacks->a->value > stacks->a->next->value)
			ft_sa(1, stacks->a);
		return ;
	}
	else if (stacks->len_a == 3)
	{
		if (stacks->a->value == max)
			ft_ra(1, &stacks->a);
		if (stacks->a->next->value == max)
			ft_rra(1, &stacks->a);
		if (stacks->a->value > stacks->a->next->value)
			ft_sa(1, stacks->a);
	}
}
