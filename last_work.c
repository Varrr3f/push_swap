/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:51:02 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:51:15 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_work(t_stacks *stacks, t_steps *steps)
{
	while (steps->action_a > 0)
	{
		if (steps->low_a == 1)
			ft_ra(1, &stacks->a);
		else
			ft_rra(1, &stacks->a);
		steps->action_a--;
	}
	while (steps->action_b > 0)
	{
		if (steps->low_b == 1)
			ft_rb(1, &stacks->b);
		else
			ft_rrb(1, &stacks->b);
		steps->action_b--;
	}
	ft_pa(1, stacks);
}

int	where_rot(t_listt *a, int min)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

void	steps(t_listt *b, int len)
{
	int		i;
	int		iter;
	t_listt	*buff;

	i = -1;
	iter = len / 2;
	buff = b;
	while (++i <= iter)
	{
		buff->step = i;
		buff->low = 1;
		buff = buff->next;
	}
	if (len % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->low = -1;
		buff = buff->next;
	}
}

void	init_steps(t_stacks *stacks, t_steps *step)
{
	while (stacks->len_b != 0)
	{
		step->action_a = -1;
		step->action_b = -1;
		step->low_a = 0;
		step->low_b = 0;
		steps(stacks->a, stacks->len_a);
		steps(stacks->b, stacks->len_b);
		find_min_steps(stacks, step);
		last_work(stacks, step);
	}
}
