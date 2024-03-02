/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:28:12 by isb3              #+#    #+#             */
/*   Updated: 2024/03/02 12:12:05 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# define RA ft_nom_super_long(stack_a, param1, param2)
typedef struct s_stack
{
	int				value;
	int				position;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

int		*initializer(char *argv[]);
void	printer(t_stack *stack_a, t_stack *stack_b, int c);
void	printer_a(t_stack *stack_a);
void	printer_b(t_stack *stack_b);

/// initialization ///
int		ft_count_words(char	*str, char c);
int		*ft_atoi_n_split(int *array, char *str);
char	*argv_join(char *str1, char *str2);
int		*int_array_init(char *str);
int		*initializer(char *argv[]);

void	initialize_stacks(int *array, t_stack **stack_a);
void	add_node(t_stack **stack, int value);

int		security_check(char *argv[]);
int		ft_strlen(char *str);

/// protections ///
int		overflow_protector(int *int_array, char *argv[], int len);
char	**argv_init(char *argv[]);
// void	ptr_check(t_stack *stack_a, t_stack *stack_b);
// void    ope_check(t_stack *stack_a, t_stack *stack_b);

char	*ft_putnbr(int n, int digit_nbr);
int		digit_counter(int n);
char	*ft_itoa(int n);

char	*ft_substr(char *s, unsigned int start, size_t len);
void	freememory(char **array);
void    free_intmemory(int *array);
void    lst_freememory(t_stack *stack_a, t_stack *stack_b);
char	*ft_strdup(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);

int		ft_strcmp(char *str1, char *str2);
char	**ft_cut(char **array, char *s, char c, size_t i);
char	**ft_split(char *s, char c);

////// algo //////
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void    five_sorter_stack_a(t_stack **stack_a, t_stack **stack_b);
void    five_sorter_stack_b(t_stack **stack_a, t_stack **stack_b);
void    a_four_sorter(t_stack **stack_a, t_stack **stack_b);
int		*largest_finder(t_stack *stack_b);
void	two_swapper(t_stack **stack_a, t_stack **stack_b, int value);
void	three_swapper(t_stack **stack_a, t_stack **stack_b, int *lowest);
void	last_push(t_stack **stack_a, t_stack **stack_b);
void	sorting_checker(t_stack *stack_a);
void	checker(t_stack **stack_a);
void	sorting_correct(t_stack	**stack_a);

////// extractor //////
// void    n_smallest_extractor(t_stack **stack_a, t_stack **stack_b, int n);
void    extractor(t_stack **stack_a, t_stack **stack_b, int n);

////// scrapper //////
int     *n_smallest_scrapper(t_stack *stack_a, int n);
int		*n_2nd_scrapper(t_stack *stack_a, int *lowest, int n);
int     *largest_scrapper(t_stack *stack_a, int n);
int		*larg_scrapper_n2(t_stack *stack_a, int *largest, int n);


// ////// algo_utils //////
int 	ruler(t_stack *stack);
int		abs_diff(int a, int b);
void	cost_initializer(t_stack *stack_a, t_stack *stack_b);
int		b_pos_finder(int stack_a_value, t_stack *stack_b);
t_stack	*return_tail(t_stack *stack);
void	pos_update(t_stack *stack);

int	    *ft_calloc(size_t size, int value);
void	free_int(int *int_arr1, int *int_arr2);

int     n_selector(t_stack *stack_a);
char    side_chooser(t_stack *stack_b, int largest);

void	three_sorter_stack_a(t_stack **stack_a);
void	three_sorter_stack_b(t_stack **stack_a);
void	three_sorter_utils_stack_a(t_stack	**stack_a, int scenario);
int		scenario_finder(t_stack *stack);

/// operations ///  
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