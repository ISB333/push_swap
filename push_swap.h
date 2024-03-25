/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:28:12 by isb3              #+#    #+#             */
/*   Updated: 2024/03/25 13:37:35 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	size_t			position;
	int				cost;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

void	printer(t_stack *stack_a, t_stack *stack_b, int c);
void	printer_a(t_stack *stack_a);
void	printer_b(t_stack *stack_b);
int		sorting_checker(t_stack *stack_a);

/// initialization ///
void	initialize_stacks(int *array, t_stack **stack_a, int len);
char	*argv_join(char *str1, char *str2);
int		*initializer(char *argv[]);
size_t	ft_strlcat(char *dst, char *src, size_t size);
char	*argv_join_all(char *argv[]);

int		ft_count_words(char	*str, char c);
int		*ft_atoi_n_split(int *array, char *str, int i, int rows, int n);
int		security_check(char *argv[]);
int		ft_strlen(char *str);

/// protections ///
void	freememory(char **array);
void	lst_freememory(t_stack *stack_a, t_stack *stack_b);
char	**argv_init(char *argv[]);
int		el_protector(int *int_array, char *argv[], int len);

char	*ft_strdup(char *s);
char	*ft_itoa(int n);
int		duplicate_sec(int *int_array, int len);

size_t	ft_strlcpy(char *dst, char *src, size_t size);
int		ft_strcmp(char *str1, char *str2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);

////// algo //////
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	three_sorter_stack_a(t_stack **stack_a);
void	five_sorter_stack_a(t_stack **stack_a, t_stack **stack_b);

////// algo_utils //////
size_t	ruler(t_stack *stack);
void	pos_update(t_stack *stack);
int		*ft_calloc(size_t size, int value);
void	ft_putstr(char *s);

size_t	n_selector(t_stack *stack_a);
t_stack	*return_tail(t_stack *stack);
void	free_int(int *int_arr1, int *int_arr2);

void	extractor(t_stack **stack_a, t_stack **stack_b, int n, int i);

int		not_in(int *lowest, int value, int n);
int		not_in_extract(int *lowest, int value, int n);
int		*largest_scrapper(t_stack *stack_a, int n, int i, int j);
int		*half_n_scrapper(int *lowest, int n);
int		*n_smallest_scrapper(t_stack *stack_a, int n);

char	side_chooser(t_stack *stack_b, int value);
void	pre_sorting_a(t_stack **stack_a, t_stack **stack_b);
void	up_sorter(t_stack **stack_a, t_stack **stack_b, int *largest);
void	low_sorter(t_stack **stack_a, t_stack **stack_b, int *largest);

////// operations ////// 
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

#endif