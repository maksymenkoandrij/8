#include <stdio.h>
#include <string.h>

// Функція для обміну двох символів
void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Рекурсивна функція для генерації анаграм
void generateAnagrams(char *word, int start, int end, int *anagramCount) {
    int i;
    if (start == end) {
        // Захищений вивід, якщо знайдено нову анаграму
        (*anagramCount)++;
        return;
    } else {
        for (i = start; i <= end; i++) {
            // Обміняти символи word[start] та word[i]
            swap((word + start), (word + i));
            // Викликати рекурсивно для підслова після обміну символів
            generateAnagrams(word, start + 1, end, anagramCount);
            // Повернути початковий стан
            swap((word + start), (word + i));
        }
    }
}

int main() {
    char word[15];
    int len, anagramCount = 0;

    printf("Введіть слово (максимум 14 символів): ");
    scanf("%s", word);

    len = strlen(word);
    
    if (len > 14) {
        printf("Кількість букв у слові не повинно перевищувати 14.\n");
        return 1;
    }

    generateAnagrams(word, 0, len - 1, &anagramCount);
    printf("Кількість можливих анаграм: %d\n", anagramCount);

    return 0;
}
