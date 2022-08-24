/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:57:03 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:57:05 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b(t_stacks *stacks)
{
	t_steps	*step;

	step = (t_steps *)malloc(sizeof(t_steps));
	if (!step)
		exit(1);
	init_steps(stacks, step);
	if ((where_rot(stacks->a, stacks->min)) > stacks->len_a / 2)
	{
		while (stacks->a->value != stacks->min)
			ft_rra(1, &stacks->a);
	}
	else
		while (stacks->a->value != stacks->min)
			ft_ra(1, &stacks->a);
	free(step);
}

void	find_min_steps(t_stacks *stacks, t_steps *steps)
{
	int		min_action;
	t_listt	*first_a;
	t_listt	*first_b;

	min_action = -1;
	first_a = stacks->a;
	first_b = stacks->b;
	while (stacks->b)
	{
		min_action = find_place(stacks, stacks->b, steps, min_action);
		stacks->a = first_a;
		stacks->b = stacks->b->next;
	}
	stacks->b = first_b;
}

int	find_place(t_stacks *s, t_listt *b, t_steps *steps, int min)
{
	int	action;
	int	res;
	int	buff;

	action = 0;
	buff = 0;
	find_place_help(s, b, &action, &buff);
	if (s->a->low == -1)
		action = s->len_a - action;
	if (min == -1 || (action + b->step) < min)
	{
		steps->low_a = s->a->low;
		steps->low_b = b->low;
		steps->action_a = action;
		steps->action_b = b->step;
		res = action + b->step;
	}
	else
		res = min;
	return (res);
}

void	find_place_help(t_stacks *s, t_listt *b, int *action, int *buff)
{
	while (s->a)
	{
		*buff = s->a->value;
		if (b->value > s->a->value)
		{
			*action += 1;
			if (b->value < s->a->next->value)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (smaller_last(s->a, *buff, b->value) == 1)
	{
		while (s->a)
		{
			if (s->a->value < *buff && s->a->value > b->value)
				break ;
			*action += 1;
			s->a = s->a->next;
		}
	}
}

int	smaller_last(t_listt *a, int buff, int src)
{
	t_listt	*save;
	int		ret;

	save = a;
	ret = 0;
	while (save && ret == 0)
	{
		if (save->value < buff && save->value > src)
			ret = 1;
		save = save->next;
	}
	return (ret);
}
