#include "push_swap.h"

int main (int argc, char *argv[])
{
    // char *str;
    // int i = 0;
    // int array[4] = {1, 2, 3, 4};
    int *yo;
    // int krkrkr;
    
    argc = 1;
    // str = ft_itoa(1258); | OK
    // str = ft_split("salut ca va", ' '); | OK
    // str = argv_join("Salut ", "Ca Va"); | OK
    // while(str[i])
    //     free(str[i++]);
    // yo = int_array_init("515 666 333"); | OK
    yo = initializer(argv);
    // krkrkr = overflow_protector(array, argv, 4);
    // printf("%d\n", krkrkr);
    // while(yo[i])
    //     printf("yo = %d\n", yo[i++]);

    free(yo);
    // free(str);
}