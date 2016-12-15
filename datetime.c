//
//  datetime.c
//  Üb4
//
//  Created by Andry Valderrama on 12.12.16.
//  Copyright © 2016 Andry Valderrama. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "escapesequenzen.h"
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "calendar.h"


/**************************************************************
 //Druckt das von Benutzer eingegebene Datum aus
 **************************************************************/
void printDate(TAppointment * Date)
{
    switch( Date->datum.Wochentag)
    {
        case 0:
        case 1: printf("\nMo, "); break;
        case 2: printf("\nDi, "); break;
        case 3: printf("\nMi, "); break;
        case 4: printf("\nDo, "); break;
        case 5: printf("\nFr, "); break;
        case 6: printf("\nSa, "); break;
        case 7: printf("\nSo, "); break;
    }


    printf("%02d.%02d.%04i\n", Date->datum.Day, Date->datum.Month, Date->datum.Year); // resolver digitos de Anio %i || %04i
}


/**************************************************************
 //Druckt die von Benutzer eingegebene zeit aus
 **************************************************************/
void printTime(TAppointment * time)
{
    if(time->zeit.Second > 0){
        printf("\n\t%02i:%02i:%02i ->", time->zeit.Second, time->zeit.Minute, time->zeit.Second);
    }else {
        printf("\n\t%02i:%02i ->", time->zeit.Hour, time->zeit.Minute);
    }
}



/**************************************************************
 //bekommt das Datum vom Bernutzer
 **************************************************************/
int getDate(char *Eingabeaufvorderung, TDate *Datenstruktur)
{
    char Date[20];
    int scann = 0;
    do
    {
        printf("%s",Eingabeaufvorderung);
        scann = scanf("%20[^\n]", Date);
        clearBuffer();
        if(scann > 0)
        {
            if (getDateFromString(Date, Datenstruktur))
            {
                return 1;
            }
            else
            {
                printf("Ungueltiges Datum! Versuchen Sie es bitte erneut, indem sie Enter druecken \n");
                waitForEnter();
                clearScreen();
                scann = 0;
            }
        }
        else
        {
            printf("Es wurde kein Datum eingegeben! Versuchen Sie es bitte erneut, indem sie Enter druecken \n");
            waitForEnter();
            clearScreen();
        }
    }while(scann == 0);
    return 0;
}


/***************************************************************************************************************
 //bekommt Uhrzeit vom Bernutzer
 **************************************************************/

int getTime(char * Eingabe, TTime *timeStruktur)
{
    char time[9];
    int scann = 0;
    do
    {
        printf("%s",Eingabe);
        scann = scanf("%[^\n]", time);
        clearBuffer();
        if(scann > 0)
        {
            if (getTimeFromString(time, timeStruktur))
            {
                return 1;
            }
            else
            {
                printf("Ungueltige Uhrzeit! Versuchen Sie es bitte erneut, indem sie Enter druecken \n");
                waitForEnter();
                clearScreen();
                scann = 0;
            }
        }
        else
        {
            printf("Es wurde keine Uhrzeit eingegeben! Versuchen Sie es bitte erneut, indem sie Enter druecken \n");
            waitForEnter();
            clearScreen();
        }
    }while(scann == 0);
    return 0;
}

/**************************************************************
 //Prüft ob das eingegebene Jahr, ein Schaltjahr ist
 **************************************************************/
int isLeapYear(int j)
{
    if ((j % 4 == 0 && j % 100 != 0) || (j % 400 == 0))
        return 1;
    else
        return 0;
}

/**************************************************************
 // Prüft ob das eingegebene Datum gültig ist
 **************************************************************/
int isDateValid(TDate date)
{
    if (date.Month >= 1 && date.Month <=12)
    {
        switch (date.Month)
        {   // guckt die Monate, die 31 Tage haben
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: if (date.Day >= 1 && date.Day <=31)
            {
                return 1;
            }
            else
            {
                return 0;
            }
                break;
                // Guckt die Monate, die nur 30 Tage haben
            case 4:
            case 6:
            case 9:
            case 11: if (date.Day >=1 && date.Day <= 30)
            {
                return 1;
            }else{
                return 0;
            }
                break;
                // Februar
            case 2: if (isLeapYear(date.Year)){
                if (date.Day >= 1 && date.Day <= 29)
                    return 1;
                else
                    return 0;

            }else
            {
                if (date.Day >= 1 && date.Day <= 28)
                {
                    return 1;
                }
                else
                    return 0;
            }
            default:
                break;
        }
    }
    return 0;
}
/**************************************************************
 //Bekommt das Deingegebene Datum und gibt eine ganze Zahl zurück
 **************************************************************/

int getDateFromString(char input[], TDate *date)
{
    char *p;
    int i;


    p = strtok(input, ".");

    for(i = 0; (p != NULL); i++)
    {
        if(i == 0)
        {
            date->Day = atoi(p);
        }
        else if(i == 1)
        {
            date->Month = atoi(p);
        }
        else if(i == 2)
        {
            date->Year = atoi(p);
        }
        p = strtok(NULL, ".");
    }

    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int year = (*date).Year;
    if (date->Month < 3)
    {
        year = (*date).Year - 1;
    }

    date->Wochentag = (year + year/4 - year/100 + year/400 + t[date->Month-1] + date->Day ) % 7;

    return isDateValid(*date);
}
/**************************************************************
 // Die Fuktion prüft ob die Zeit gültig ist und gibt eine ganze Zahl zurück
 **************************************************************/
int isTimeValid(TTime Time)
{
    if (Time.Hour >= 0 && Time.Hour <= 23)
        if (Time.Minute >= 0 && Time.Minute <= 59)
            if (Time.Second >= 0 && Time.Second <= 59)
                return 1;

    return 0;
}
/**************************************************************
 //Bekommt das Deingegebene Zeit und gibt eine ganze Zahl zurück
 **************************************************************/
int getTimeFromString(char input[], TTime *Time)
{
    char *p;
    int i;

    p = strtok(input, ":");

    Time->Second = 0;

    for(i = 0; (p != NULL); i++){
        if(i == 0){
            Time->Hour = atoi(p);
        }else if(i == 1){
            Time->Minute = atoi(p);
        }else if(i == 2){
            Time->Second = atoi(p);
        }
        p = strtok(NULL, ":");
    }

    return isTimeValid((*Time));
}

