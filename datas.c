#include <stdio.h>
#include <stdlib.h>
#include "datas.h"

int daysBetweenDates (Date date1, Date date2) 
{
    int days1 = date1.year * 365 + date1.day;
    int days2 = date2.year * 365 + date2.day;

    days1 += date1.year / 4 - date1.year / 100 + date1.year / 400;
    days2 += date2.year / 4 - date2.year / 100 + date2.year / 400;

    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < date1.month; i++) {
        days1 += monthDays[i];
    }
    for (int i = 1; i < date2.month; i++) {
        days2 += monthDays[i];
    }

    if (date1.month <= 2 && (date1.year % 4 == 0 && (date1.year % 100 != 0 || date1.year % 400 == 0))) 
    {
        days1--;
    }
    if (date2.month <= 2 && (date2.year % 4 == 0 && (date2.year % 100 != 0 || date2.year % 400 == 0))) 
    {
        days2--;
    }

    int difference = days2 - days1;
    return difference;
}

Date *pedeData(struct data *dataAtual)
{
    Date *dataLocal = (Date*)malloc(sizeof(Date));
    printf ("Digite a data atual (DD MM AAAA): ");
    scanf ("%d %d %d", &dataLocal->day, &dataLocal->month, &dataLocal->year);

    return dataLocal;
}
