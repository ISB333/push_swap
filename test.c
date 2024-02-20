#include "push_swap.h"

// int main (int argc, char *argv[])
// {
//     // char *str;
//     // int i = 0;
//     // int array[4] = {1, 2, 3, 4};
//     int *yo;
//     // int krkrkr;
    
//     argc = 1;
//     // str = ft_itoa(1258); | OK
//     // str = ft_split("salut ca va", ' '); | OK
//     // str = argv_join("Salut ", "Ca Va"); | OK
//     // while(str[i])
//     //     free(str[i++]);
//     // yo = int_array_init("515 666 333"); | OK
//     yo = initializer(argv);
//     // krkrkr = overflow_protector(array, argv, 4);
//     // printf("%d\n", krkrkr);
//     // while(yo[i])
//     //     printf("yo = %d\n", yo[i++]);

//     free(yo);
//     // free(str);
// }

#include <stdlib.h>
#include <stdio.h>

int ft_count_words(char *str, char c) {
    int rows = 0;
    int i = 0;
    while (str[i]) {
        while (str[i] == c)
            i++;
        if (str[i])
            rows++;
        while (str[i] && str[i] != c)
            i++;
    }
    return rows;
}

int *ft_atoi_n_split(int *array, char *str) {
    int rows = -1;
    int i = 0;
    while (str[i]) {
        int sign = 1;
        int n = 0;
        while (((str[i] >= '0' && str[i] <= '9') || str[i] == '-') && str[i] != ' ') {
            if (str[i] == '-' && i++ > 0)
                sign = -1;
            while (str[i] >= '0' && str[i] <= '9')
                n = (n * 10) + (str[i++] - '0');
            array[++rows] = n * sign;
        }
        i++;
    }
    array[++rows] = 0;
    return array;
}

int *int_array_init(char *str) {
    int rows = ft_count_words(str, ' ');
    int *array = (int *)malloc((rows + 1) * sizeof(int));
    if (!array)
        return NULL;
    return ft_atoi_n_split(array, str);
}

char *argv_join(char *str1, char *str2) {
    int i = 0;
    int k = 0;
    char *str = malloc(ft_strlen(str1) + ft_strlen(str2) + 2);
    if (!str)
        return NULL;
    if (str1 != NULL) {
        while (str1[i])
        {
            str[i] = str1[i];
            i++;
        }
    }
    while (str2[k])
        str[i++] = str2[k++];
    str[i] = ' ';
    str[++i] = '\0';
    return str;
}

int *initializer(char *argv[]) {
    char *str = NULL;
    int i = 1;
    while (argv[i])
        str = argv_join(str, argv[i++]);
    int *array = int_array_init(str);
    free(str);
    return array;
}

int main(int argc, char *argv[]) {
    if(argc == 1)
        return 0;
    int *array = initializer(argv);
    if (array) {
        int i = 0;
        while (array[i]) {
            printf("int_array = %d\n", array[i++]);
        }
        free(array);
    } else {
        printf("Initialization failed.\n");
    }
    return 0;
}
