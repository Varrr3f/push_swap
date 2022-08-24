/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:32:29 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 18:32:32 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	operations_else(char *line, t_stacks *s)
{
	if (ft_strncmp(line, "rb", 3) == 0)
		ft_rb(0, &s->b);
	else if (ft_strncmp(line, "rr", 3) == 0)
		ft_rr(0, s);
	else if (ft_strncmp(line, "rra", 3) == 0)
		ft_rra(0, &s->a);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		ft_rrb(0, &s->b);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		ft_rrr(0, s);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	operations(char *line, t_stacks *s)
{
	if (ft_strncmp(line, "sa", 3) == 0)
		ft_sa(0, s->a);
	else if (ft_strncmp(line, "sb", 3) == 0)
		ft_sb(0, s->b);
	else if (ft_strncmp(line, "ss", 3) == 0)
		ft_ss(0, s);
	else if (ft_strncmp(line, "pa", 3) == 0)
		ft_pa(0, s);
	else if (ft_strncmp(line, "pb", 3) == 0)
		ft_pb(0, s);
	else if (ft_strncmp(line, "ra", 3) == 0)
		ft_ra(0, &s->a);
	else
		operations_else(line, s);
}

void	ft_read_action(t_stacks *s)
{
	char	*line;

	line = NULL;
	while (get_next_line_ex(&line))
	{
		operations(line, s);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	ft_stack_sorted(t_stacks *s)
{
	int		i;
	int		buff;
	t_listt	*save;

	i = 0;
	save = s->a;
	while (i < (s->len_a - 1))
	{
		buff = s->a->value;
		s->a = s->a->next;
		if (buff > s->a->value)
		{
			s->a = save;
			return (0);
		}
		i++;
	}
	s->a = save;
	return (1);
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
		parcer_then(argc, argv, arr, stacks);
	ft_free_stack(stacks);
	free(arr);
	free(stacks);
	return (0);
}
