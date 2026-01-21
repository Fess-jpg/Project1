#include <stdio.h>
#include <string.h>

#define HISTORY_SIZE 5
#define MAX_EXPR_LEN 50

void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

int main() {
  double num1, num2;
  char operation;
  double result;
  char should_continue = 'y';
  char history[HISTORY_SIZE][MAX_EXPR_LEN] = {0};
  int history_count = 0;

  while (should_continue == 'y' || should_continue == 'Y') {

    printf("Введите первое число: ");
    while (scanf("%lf", &num1) != 1) {
      clear_input_buffer();
      printf("Ошибка: введите корректное число: ");
    }
    clear_input_buffer();

    printf("Введите операцию: ");
    scanf(" %c", &operation);

    printf("Введите второе число: ");
    while (scanf("%lf", &num2) != 1) {
      clear_input_buffer();
      printf("Ошибка: введите корректное число: ");
    }
    clear_input_buffer();

    switch (operation) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      if (num2 != 0) {
        result = num1 / num2;
      } else {
        printf("Ошибка: деление на ноль\n");
        continue;
      }
      break;
    default:
      printf("Ошибка, неизвестная оперция'%c'!", operation);
      continue;
    }

    printf("Результат: %.2lf\n", result);

    char buffer[MAX_EXPR_LEN];
    snprintf(buffer, MAX_EXPR_LEN, "%.2lf %c %.2lf = %.2lf", num1, operation,
             num2, result);

    if (history_count < HISTORY_SIZE) {
      strcpy(history[history_count], buffer);
      history_count++;
    } else {
      for (int i = 0; i < HISTORY_SIZE - 1; i++) {
        strcpy(history[i], history[i + 1]);
      }
      strcpy(history[HISTORY_SIZE - 1], buffer);
    }

    printf("Хотите сделать ее одно вычисление? (y/n):");
    scanf(" %c", &should_continue);
  }

  printf("\n===История последних %d операций===\n",
         (history_count < HISTORY_SIZE) ? history_count : HISTORY_SIZE);

  if (history_count == 0) {
    printf("История пуста.\n");
  } else {
    int start_index = 0;
    int total_to_show = history_count;

    if (history_count > HISTORY_SIZE) {
      start_index = history_count - HISTORY_SIZE;
      total_to_show = HISTORY_SIZE;
    }

    for (int i = 0; i < total_to_show; i++) {
      printf("%d. %s\n", i + 1, history[i]);
    }
  }
  printf("=================================\n");

  return 0;
}