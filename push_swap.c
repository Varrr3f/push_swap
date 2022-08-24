/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:51:38 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:51:44 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stacks *stacks)
{
	if (stacks->len_a > 3)
	{
		while (stacks->len_a != 3)
		{
			if ((stacks->a->value == stacks->min)
				|| (stacks->a->value == stacks->max)
				|| (stacks->a->value == stacks->mid))
			{
				ft_ra(1, &stacks->a);
			}
			else
				ft_pb(1, stacks);
		}
		sort_3(stacks);
		ft_sort_b(stacks);
	}
	else
		sort_3(stacks);
}

void	final_sort(t_stacks *stacks)
{
	if (stacks->a->value > stacks->mid)
	{
		while (stacks->a->value > stacks->min)
			ft_ra(1, &stacks->a);
	}
	else
		while (stacks->a->value > stacks->min)
			ft_rra(1, &stacks->a);
}

void	sort_5(t_stacks *stacks)
{
	while (stacks->len_b < 2)
	{
		if (stacks->a->value == stacks->min || stacks->a->value == stacks->max)
			ft_pb(1, stacks);
		else
			ft_ra(1, &stacks->a);
	}
	sort_3(stacks);
	ft_pa(1, stacks);
	ft_pa(1, stacks);
	if (stacks->a->value == stacks->max)
		ft_ra(1, &stacks->a);
	else
	{
		ft_sa(1, stacks->a);
		ft_ra(1, &stacks->a);
	}
}

void	sort(t_mass	*arr, t_stacks *stacks)
{
	ft_duplicate_check(arr, stacks);
	if (!(mass_is_sorted(arr)))
	{
		init_stack(arr, stacks);
		if (!(mass_sirc_sorted(arr)))
		{
			if (stacks->len_a == 5)
				sort_5(stacks);
			else
			{
				sort_stack(stacks);
				final_sort(stacks);
			}
		}
		else
			final_sort(stacks);
		ft_free_stack(stacks);
	}
}

int	main(int argc, char **argv)
{
	t_mass		*arr;
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	arr = (t_mass *)malloc(sizeof(t_mass));
	if (!arr)
		exit(1);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		exit(1);
	ft_null(stacks, arr);
	if (parcer(argc, argv))
	{
		str_to_mass(argc, argv, arr);
		sort(arr, stacks);
	}
	free(arr);
	free(stacks);
	return (0);
}
