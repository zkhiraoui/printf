#include "main.h"
#include <stdio.h>

int main(void)
{
    _printf("Let's try to printf a simple sentence.\n");
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");

    /* Comparison with real printf */
    printf("Let's try to printf a simple sentence.\n");
    printf("Character:[%c]\n", 'H');
    printf("String:[%s]\n", "I am a string !");
    printf("Percent:[%%]\n");
    return (0);
}
