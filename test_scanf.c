#include <stdio.h>

int main() {
    int number;
    char symbol;

    printf("Введите число и нажмите Enter: ");
    scanf("%d", &number);

    printf("Введите символ: ");
    // Попробуй УБРАТЬ пробел перед %c в следующей строке и увидишь магию
    scanf("%c", &symbol);

    printf("Вы ввели: %d и символ '%c'\n", number, symbol);
    return 0;
}