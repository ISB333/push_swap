/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:28:12 by isb3              #+#    #+#             */
/*   Updated: 2024/02/09 13:35:22 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int				value;
	int				position;
	int				cost;
	struct s_data	*prev;
	struct s_data	*next;
}				t_data;

typedef struct s_stack_a
{
	t_data	*head;
	t_data	*tail;
}				t_stack_a;

typedef struct s_stack_b
{
	t_data	*head;
	t_data	*tail;
}				t_stack_b;

int		*initializer(char *argv[]);

/// initialization ///
int		ft_count_words(char	*str, char c);
int		*ft_atoi_n_split(int *array, char *str);
char	*argv_join(char *str1, char *str2);
int		*int_array_init(char *str);
int		*initializer(char *argv[]);

void	initialize_stacks(int *array, t_stack_a *stack_a, t_stack_b *stack_b);
void	add_node(t_stack_a *stack, int value);
void	stack_printer_a(t_stack_a *stack);
void	stack_printer_b(t_stack_b *stack);

int		security_check(char *argv[]);
int		ft_strlen(char *str);

/// protections ///
int		overflow_protector(int *int_array, char *argv[]);
char	**argv_init(char *argv[]);
void	ptr_check(t_stack_a *stack_a, t_stack_b *stack_b);
void    ope_check(t_stack_a *stack_a, t_stack_b *stack_b);

char	*ft_putnbr(int n, int digit_nbr);
int		digit_counter(int n);
char	*ft_itoa(int n);

char	*ft_substr(char *s, unsigned int start, size_t len);
void	freememory(char **array, size_t j);
char	*ft_strdup(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);

int		ft_strcmp(char *str1, char *str2);
char	**ft_cut(char **array, char *s, char c, size_t i);
char	**ft_split(char *s, char c);

////// algo //////
void	push_swap(t_stack_a *stack_a, t_stack_b *stack_b);
void    five_sorter_stack_a(t_stack_a *stack_a, t_stack_b *stack_b);
void    five_sorter_stack_b(t_stack_a *stack_a, t_stack_b *stack_b);

void    scen_minus1toptop(t_stack_a *stack_a, t_stack_b *stack_b);
void    scen_minus1toptopminus1(t_stack_a *stack_a, t_stack_b *stack_b);
void    scen_bottbott(t_stack_a *stack_a, t_stack_b *stack_b);
void    scen_bottplusbottplus(t_stack_a *stack_a, t_stack_b *stack_b);

void    inside_stacks_sorting(t_stack_a *stack_a, t_stack_b *stack_b, int a_pos, int b_pos);

// ////// algo_utils //////
int 	ruler(t_stack_a *stack_a, t_stack_b *stack_b, int stack);
int		abs_diff(int a, int b);
void	cost_initializer(t_stack_a *stack_a, t_stack_b *stack_b);
int		cheapest_pos_finder(t_stack_a *stack_a, t_stack_b *stack_b);
int		b_pos_finder(int stack_a_value, t_stack_b *stack_b);
void    printer(t_stack_a *stack_a, t_stack_b *stack_b);

void	three_sorter_stack_a(t_stack_a *stack_a);
void	three_sorter_stack_b(t_stack_b *stack_a);
void	thee_sorter_utils_stack_a(t_stack_a	*stack_a, int scenario);
int		scenario_finder(t_data *stack);


/// operations ///  
void	sa(t_stack_a *stack);
void	sb(t_stack_b *stack);
void	ss(t_stack_a *stack_a, t_stack_b *stack_b);
void	ra(t_stack_a *stack);
void	rb(t_stack_b *stack);
void	rr(t_stack_a *stack_a, t_stack_b *stack_b);
void	rra(t_stack_a *stack);
void	rrb(t_stack_b *stack);
void	rrr(t_stack_a *stack_a, t_stack_b *stack_b);
void	pa(t_stack_a *stack_a, t_stack_b *stack_b);
void	pb(t_stack_a *stack_a, t_stack_b *stack_b);

#endif