///-> Program that take as arguments an integer list -> 1st argument at the top of the stack
///-> Launch ./push_swap 
///-> Once every instructions read, execute them (gnl->ft_split)
///-> If stack_a sorted and stack_b empty == print "OK\n"
//////-> Else == print "KO\n"

#include "../push_swap.h"

int	checker(char *argv[])
{
	int	*array;
	int argc = 2;

	if (argc <= 1)
		return (0);
	else
	{
		array = initializer(argv);
		if (array == 0)
			return (printf("Error\n"), 0);
		int i = 0;
		while (array[i])
			printf("%d\n", array[i++]);
	}
	return (0);
}
int main()
{
	char *argv[] = {"1", "2", "3", "55", "1", "4"};
	checker(argv);
}