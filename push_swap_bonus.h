/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:53:43 by sdavos            #+#    #+#             */
/*   Updated: 2022/03/13 16:53:46 by sdavos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct s_steps
{
	int	len_a;
	int	len_b;
	int	low_a;
	int	low_b;
}	t_steps;

typedef struct s_mass
{
	int	a[100000];
	int	size;
}	t_mass;

typedef struct s_listt
{
	int				step;
	int				value;
	int				low;
	struct s_listt	*next;
}	t_listt;

typedef struct s_stacks
{
	t_listt	*a;
	t_listt	*b;
	int		min;
	int		max;
	int		mid;
	int		len_a;
	int		len_b;
}	t_stacks;

void	str_to_mass(int argc, char **argv, t_mass *arr);
void	ft_stacking(t_mass *arr, int *buff, int count);
void	ft_null(t_stacks *stacks, t_mass *arr);
int		ft_countword(char const *s);
int		parcer(int argc, char **argv);
void	number_is_valid(char *str);
void	number_or_not(char *str);
int		separators_before(char *str);
void	init_stack(t_mass *arr, t_stacks *stacks);
int		mass_is_sorted(t_mass *arr);
t_listt	*greate_stack(int *mass, int size);
int		mass_sirc_sorted(t_mass *arr);
void	ft_duplicate_check(t_mass *arr, t_stacks *stacks);
int		*ft_intcpy(int *dst, const int *src, int count);
void	quick_sort(int *array, int left, int right);
int		quick_sort_help(int *array, int left, int pivot);
int		ft_partition(int *array, int start, int end);
void	ft_search_duplicate(const int *dup, int count);
void	sort(t_mass	*arr, t_stacks *stacks);
void	ft_ra(int n, t_listt **a);
void	ft_rra(int n, t_listt **a);
void	ft_pb(int n, t_stacks *s);
void	ft_sa(int n, t_listt *a);
void	ft_pa(int n, t_stacks *s);
void	ft_rrb(int n, t_listt **b);
void	ft_rb(int n, t_listt **b);
void	ft_sb(int n, t_listt *b);
void	ft_ss(int n, t_stacks *s);
void	ft_rr(int n, t_stacks *s);
void	ft_rrr(int n, t_stacks *s);
void	sort_3(t_stacks *stacks);
int		find_max(t_listt *s);
void	ft_sort_b(t_stacks *stacks);
void	steps(t_listt *b, int len);
void	find_min_steps(t_stacks *stacks, t_steps *steps);
int		find_place(t_stacks *s, t_listt *b, t_steps *steps, int min);
void	find_place_help(t_stacks *s, t_listt *b, int *action, int *buff);
int		smaller_last(t_listt *a, int buff, int src);
void	last_work(t_stacks *stacks, t_steps *steps);
int		where_rot(t_listt *a, int min);
void	ft_free_stack(t_stacks *stacks);
void	sort_5(t_stacks *stacks);
void	operations(char *line, t_stacks *s);
void	ft_read_action(t_stacks *s);
int		ft_stack_sorted(t_stacks *s);
void	init_steps(t_stacks *stacks, t_steps *step);
int		number_is_valid_help(char *str, int sign, int size, int i);
void	operations_else(char *line, t_stacks *s);
void	parcer_then(int argc, char **argv, t_mass *arr, t_stacks *stacks);
int		get_next_line_ex(char **line);
char	*ft_sjoin(char *line, char n);
char	*ft_sjoin_help(char *ret, char n);

#endif
