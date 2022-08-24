/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:53:18 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:53:20 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
