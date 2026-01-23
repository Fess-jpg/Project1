#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

int main() {
  int secret_number;
  int user_guess;
  int attempts = 0;

  int best_score = 0;
  int games_played = 0;
  int total_attempts = 0;
  char play_again = 'y';

  while (play_again == 'y' || play_again == 'Y') {

    secret_number = rand() % 100 + 1;
    attempts = 0;

    printf("\n=== Игра #%d ===\n", games_played + 1);
    printf("Я загадал число от 1 до 100. Попробуй угадать!\n");
    printf("У тебя есть %d попыток.\n", MAX_ATTEMPTS);

    while (1) {

      printf("Твой вариант: ");
      int result = scanf("%d", &user_guess);
      clear_input_buffer();
      if (result != 1) {
        printf("Ошибка. Введи целое число: ");
        continue;
      }
      if (user_guess < 1 || user_guess > 100) {
        printf("Число должно быть от 1 до 100! Попробуй ещё.\n");
        continue;
      }

      attempts++;

      if (attempts >= MAX_ATTEMPTS) {
        printf("\nУвы, ты исчерпал все %d попыток.\n", MAX_ATTEMPTS);
        printf("Загаданное число было: %d\n", secret_number);
        break;
      }

      if (user_guess < secret_number) {
        printf("Слишком маленькое! Попробуй еще.\n");
      } else if (user_guess > secret_number) {
        printf("Слишком большое! Попробуй еще.\n");
      } else {
        printf("Поздравляю! Ты угадал число %d за %d попыток!\n", secret_number,
               attempts);

        games_played++;
        total_attempts += attempts;

        if (best_score == 0 || attempts < best_score) {
          best_score = attempts;
        }
        break;
      }
    }

    printf("\n--- Статистика ---\n");
    printf("Сыграно игр: %d\n", games_played);

    if (games_played > 0) {
      if (best_score > 0) {
        printf("Лучший результат: %d попыток\n", best_score);
      }
      printf("Среднее число попыток: %.1f\n",
             (float)total_attempts / games_played);
    } else {
      printf("Пока не сыгранно ни одной игры.\n");
    }
    printf("------------------\n");
    printf("Сыграем еще раз? (y/n): ");
    scanf(" %c", &play_again);
  }
  printf("\nСпасибо за игру! До встречи!\n");
  return 0;
}