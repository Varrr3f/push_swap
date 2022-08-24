/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:56:46 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:56:48 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(int n, t_listt *a)
{
	int	buff;

	if (a == NULL || a->next == NULL)
		return ;
	buff = a->value;
	a->value = a->next->value;
	a->next->value = buff;
	if (n == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(int n, t_listt *b)
{
	int	buff;

	if (b == NULL || b->next == NULL)
		return ;
	buff = b->value;
	b->value = b->next->value;
	b->next->value = buff;
	if (n == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(int n, t_stacks *s)
{
	ft_sa(0, s->a);
	ft_sb(0, s->b);
	if (n == 1)
		write(1, "ss\n", 3);
}
