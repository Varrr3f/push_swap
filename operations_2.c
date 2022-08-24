/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:55:12 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:55:14 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(int n, t_listt **a)
{
	t_listt	*first_list;
	t_listt	*rotate_list;
	t_listt	*last_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	rotate_list = *a;
	first_list = (*a)->next;
	last_list = *a;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*a = first_list;
	if (n == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(int n, t_listt **b)
{
	t_listt	*first_list;
	t_listt	*rotate_list;
	t_listt	*last_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	rotate_list = *b;
	first_list = (*b)->next;
	last_list = *b;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*b = first_list;
	if (n == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(int n, t_stacks *s)
{
	ft_ra(0, &s->a);
	ft_rb(0, &s->b);
	if (n == 1)
		write(1, "rr\n", 3);
}

void	ft_rra(int n, t_listt **a)
{
	t_listt		*first_list;
	t_listt		*rotate_list;
	t_listt		*penultimate_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	first_list = *a;
	penultimate_list = *a;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*a = rotate_list;
	if (n == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(int n, t_listt **b)
{
	t_listt		*first_list;
	t_listt		*rotate_list;
	t_listt		*penultimate_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	first_list = *b;
	penultimate_list = *b;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*b = rotate_list;
	if (n == 1)
		write(1, "rrb\n", 4);
}
