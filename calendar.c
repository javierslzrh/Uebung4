//
//  calendar.c
//  Üb4
//
//  Created by Andry Valderrama on 12.12.16.
//  Copyright © 2016 Andry Valderrama. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calendar.h"
#include "datastructure.h"
#include "escapesequenzen.h"
#include "menu.h"
#include "tools.h"
#include "datetime.h"

int countAppointment = 0;
TAppointment Calendar[MAX];

void createAppointment()
{
    if (countAppointment < MAX)
    {
        TAppointment *appointment = Calendar + countAppointment;
        printf("\nErfassung eines neuen Termins\n");
        printLine('=', 29);
        
        getDate("\n\nDatum: ", &(appointment->datum));
        getTime("Uhrzeit: ", &appointment->zeit);
        getText("Beschreibung: ", 100, &appointment->Description, 1);
        getText("Ort: ", 15, &(appointment->Place), 0);
        
        appointment->Duration = (TTime *) malloc(sizeof(TTime));
        getTime("Dauer: ", appointment->Duration);
        
        countAppointment++;
    } else {
        printf("Speicher ist Voll");
    }
}

void editAppointment()
{
    printf("Termin bearbeiten");
}

void deleteAppointment()
{
    printf("Termin loeschen");
}

void searchAppointment()
{
    printf("Termin suchen");
}

void sortCalendar()
{
    
}

void listCalendar()
{
    int i;
    int WithDate = 1;
    
    printf("Liste der Termine\n");
    printLine('=', 17);
    printf("\n\n");
    
    for(i = 0; i < countAppointment; i++)
    {
        listAppointment(Calendar + i , WithDate);
        if(i < countAppointment - 1)
            WithDate = (compareDate(Calendar + i, Calendar + i + 1) != 0 );
        
    }
    
    /*TAppointment appointment = Calendar[i];
     
     if (appointment.Place != NULL)
     {
     printf(" %s ", appointment.Place);
     
     }else
     {
     printf("\t\t\t\t\t| %s\t", appointment.Description);
     }
     
     //printTime(*appointment.Duration);
     */
    
    if (i == 0 || i < countAppointment) {
        printf("Zurzeit gibt keine Termine zur Verfügung!!!\n");
    }
    
    waitForEnter();
}


int compareDate(TAppointment * data1, TAppointment * data2)
{
    int Erg = data1->datum.Year - data2->datum.Year;
    
    if (Erg == 0)
    {
        Erg = data1->datum.Month - data2->datum.Month;
        if (Erg == 0) {
            Erg = data1->datum.Day - data2->datum.Day;
        }
    }
    return Erg;
}

void listAppointment(TAppointment * App, int WithDate)
{
    int i;
    
    if(WithDate)
    {
        
        printLine('=', 82);
        printDate(App);
        printLine('_', sizeof(App->datum)); // Antes estaba escrito '15'
    }
    
    printTime(App);
    printf("%15s      |" ,App->Place);
    
    int len_beschreibung = (unsigned)strlen(App->Description);
    
    if(len_beschreibung <= 48)
        printf(" %s \n", App->Description);
    
    else if( len_beschreibung >48)
    {
        for(i = 0; i < 44; i++)
            printf(" %c", (App->Description[i])); // Zeichenweise ausgabe
        
        printf(" ...\n");
        
    }
    
}

void exitProg()
{
    printf("Programm beendet!\n");
    exit(0);
}

