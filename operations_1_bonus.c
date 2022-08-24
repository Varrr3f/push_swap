/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:54:41 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:54:43 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_pa(int n, t_stacks *s)
{
	t_listt	*stack;

	if (s->b == NULL)
		return ;
	s->len_a += 1;
	s->len_b -= 1;
	stack = s->b;
	s->b = s->b->next;
	stack->next = s->a;
	s->a = stack;
	if (n == 1)
		write(1, "pa\n", 3);
}

void	ft_pb(int n, t_stacks *s)
{
	t_listt	*stack;

	if (s->a == NULL)
		return ;
	s->len_a -= 1;
	s->len_b += 1;
	stack = s->a;
	s->a = s->a->next;
	stack->next = s->b;
	s->b = stack;
	if (n == 1)
		write(1, "pb\n", 3);
}

void	ft_rrr(int n, t_stacks *s)
{
	ft_rra(0, &s->a);
	ft_rrb(0, &s->b);
	if (n == 1)
		write(1, "rrr\n", 4);
}

void	parcer_then(int argc, char **argv, t_mass *arr, t_stacks *stacks)
{
	str_to_mass(argc, argv, arr);
	ft_duplicate_check(arr, stacks);
	init_stack(arr, stacks);
	ft_read_action(stacks);
	if ((ft_stack_sorted(stacks)) && stacks->len_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
