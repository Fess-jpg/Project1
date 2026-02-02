#include <stdio.h>

void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

void remove_newline(char str[]) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  if (i > 0 && str[i - 1] == '\n') {
    str[i - 1] = '\0';
  }
}

void caesar_encrypt(char text[], int shift) {
  int i = 0;

  while (text[i] != '\0') {
    char c = text[i];

    if (c >= 'A' && c <= 'Z') {
      text[i] = (c - 'A' + shift) % 26 + 'A';
    } else if (c >= 'a' && c <= 'z') {
      text[i] = (c - 'a' + shift) % 26 + 'a';
    }

    i++;
  }
}

void caesar_decrypt(char text[], int shift) {
  caesar_encrypt(text, 26 - (shift % 26));
}

int main(void) {
  printf("=== Текстовый шифратор ===\n");
  printf("Программа запущена!\n");

  int choice;
  do {
    printf("\nМеню:\n");
    printf("1. Зашифровать\n");
    printf("2. Расшифровать\n");
    printf("3. Выйти\n");
    printf("Введите номер: ");

    int result = scanf("%d", &choice);
    clear_input_buffer();
    if (result != 1) {
      printf("Ошибка ввода, нужно ввести число.\n");
      continue;
    }

    switch (choice) {
    case 1: {
      printf("\n--- Шифрование текста ---\n");

      char text[1000];
      int shift;

      printf("Введите текст для шифрования: ");
      fgets(text, sizeof(text), stdin);
      remove_newline(text);

      if (text[0] == '\0') {
        printf("Ошибка: текст не может быть пустым!\n");
        break;
      }

      printf("Введите сдвиг (1-25): ");
      int shift_result = scanf("%d", &shift);
      clear_input_buffer();

      if (shift_result != 1) {
        printf("Ошибка: нужно ввести число!\n");
        break;
      }

      if (shift < 1 || shift > 25) {
        printf("Ошибка: сдвиг должен быть от 1 до 25!\n");
        break;
      }

      printf("\nРезультат:\n");
      printf("Исходный текст:  %s\n", text);
      caesar_encrypt(text, shift);
      printf("Зашифрованный:   %s\n", text);

      break;
    }

    case 2: {
      printf("\n--- Дешифрование текста ---\n");

      char text[1000];
      int shift;

      printf("Введите текст для дешифрования: ");
      fgets(text, sizeof(text), stdin);
      remove_newline(text);

      if (text[0] == '\0') {
        printf("Ошибка: текст не может быть пустым!\n");
        break;
      }

      printf("Введите сдвиг (1-25): ");
      int shift_result = scanf("%d", &shift);
      clear_input_buffer();

      if (shift_result != 1) {
        printf("Ошибка: нужно ввести число!\n");
        break;
      }

      if (shift < 1 || shift > 25) {
        printf("Ошибка: сдвиг должен быть от 1 до 25!\n");
        break;
      }

      printf("\nРезультат:\n");
      printf("Зашифрованный текст: %s\n", text);
      caesar_decrypt(text, shift);
      printf("Дешифрованный текст: %s\n", text);

      break;
    }

    case 3:
      printf("\nВыход из программы.\n");
      break;

    default:
      printf("\nОшибка! Введите число от 1 до 3.\n");
      break;
    }

  } while (choice != 3);

  printf("До свидания!\n");
  return 0;
}