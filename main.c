#include "main.h"

int main(void)
{
    int chars_printed;

    chars_printed = _printf("Let's try to printf a simple sentence.\n");
    _printf("Plain text: This is a test.\n");
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percentage sign: %%\n");
    _printf("Mixed: %c %s %%%c\n", 'X', "Custom Print", 'Y');

    printf("\nTotal characters printed: %d\n", chars_printed);

    return (0);
}

