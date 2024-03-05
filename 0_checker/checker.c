///-> Program that take as arguments an integer list -> 1st argument at the top of the stack
///-> Launch ./push_swap 
///-> Once every instructions read, execute them (gnl->ft_split)
///-> If stack_a sorted and stack_b empty == print "OK\n"
//////-> Else == print "KO\n"

#include "../push_swap.h"

int	checker(char *argv[])
{
	t_stack *stack_a;
	t_stack	*stack_b;
	int	*array;
	int argc = 2;

	if (argc <= 1)
		return (0);
	else
	{
		array = initializer(argv);
		if (array == 0)
			return (printf("Error\n"), 0);
		stack_a = NULL;
		stack_b = NULL;
		initialize_stacks(array, &stack_a);
		// int i = -1;
		// while (array[++i])
		// 	printf("%d\n", array[i]);
		push_swap(&stack_a, &stack_b);
		lst_freememory(stack_a, stack_b);
	}
	return (0);
}
int main()
{
	char	*argv[] = {"a.out", "1", "2", "3", NULL};
	checker(argv);
}