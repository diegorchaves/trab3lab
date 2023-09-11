/*Codigo gerado pelo ChatGPT
Este programa permite ao usuário inserir duas datas no formato DD MM AAAA (dia, mês e ano) e, em seguida, calcula a diferença em dias
 entre essas duas datas. Certifique-se de inserir as datas no formato correto e observe que este programa não trata todos os casos
  possíveis (por exemplo, datas inválidas), mas deve funcionar bem para datas válidas.*/
  
#include <stdio.h>

// Estrutura para representar uma data
struct Date {
    int day;
    int month;
    int year;
};

// Função para calcular a diferença em dias entre duas datas
int daysBetweenDates(struct Date date1, struct Date date2) {
    int days1 = date1.year * 365 + date1.day;
    int days2 = date2.year * 365 + date2.day;

    // Adicionar dias extras para os anos bissextos
    days1 += date1.year / 4 - date1.year / 100 + date1.year / 400;
    days2 += date2.year / 4 - date2.year / 100 + date2.year / 400;

    // Adicionar dias para os meses
    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < date1.month; i++) {
        days1 += monthDays[i];
    }
    for (int i = 1; i < date2.month; i++) {
        days2 += monthDays[i];
    }

    // Considerar anos bissextos
    if (date1.month <= 2 && (date1.year % 4 == 0 && (date1.year % 100 != 0 || date1.year % 400 == 0))) {
        days1--;
    }
    if (date2.month <= 2 && (date2.year % 4 == 0 && (date2.year % 100 != 0 || date2.year % 400 == 0))) {
        days2--;
    }

    // Calcular a diferença em dias
    int difference = days2 - days1;
    return difference;
}

int main() {
    struct Date date1, date2;

    printf("Digite a primeira data (DD MM AAAA): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    printf("Digite a segunda data (DD MM AAAA): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    int difference = daysBetweenDates(date1, date2);

    printf("A diferença em dias entre as duas datas é: %d\n", difference);

    return 0;
}