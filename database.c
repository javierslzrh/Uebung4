//
//  database.c
//  Üb4
//
//  Created by Andry Valderrama on 12.12.16.
//  Copyright © 2016 Andry Valderrama. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datastructure.h"
#include "database.h"
#include "datetime.h"
#include "tools.h"

void saveCalendar()
{

}

void saveAppointment()
{

}

void loadCalendar()
{
    FILE *file;
    char line[TEXT];

    file = fopen("calendar.xml", "r");
    int flag = -1;
    int linesCount = 0;
    TAppointment *appointment = NULL;
    while(1)
    {
        if (fgets(line, TEXT, file) == NULL)
        {
            break;
        }
        lTrim(line);

        linesCount++;

        if(linesCount == 1 && strncmp(line, "<Calendar>", 10) != 0)
        {
            //Rompe el ciclo porque el fichero tiene un formato incorrecto
            break;
        }

        if(strncmp(line, "<Appointment>", 13) == 0){
            flag = 1;
            continue;
        }

        if(strncmp(line, "</Appointment>", 14) == 0){
            flag = 0;
        }

        if(flag == 1){
            loadAppointment(&appointment, line);
        }else if(flag == 0) {
            if(appointment != NULL) {
                Calendar[countAppointment] = *appointment;
                countAppointment++;
                free(appointment);
            }
        }
    }
}

void loadAppointment(TAppointment **appointment, char *line){

    *appointment = malloc(sizeof(TAppointment));

    if(strncmp(line, "<Date>", 6) == 0){

        int len = strlen(line + 6) -8;
        if (strncmp(line + 6 + len, "</Date>", 7) == 0 )
        {
            getDateFromString(line + 6, &(**appointment).datum);
        }
    }

    if(strncmp(line, "<Time>", 6) == 0){
        int len = strlen(line + 6) -8;
        if (strncmp(line + 6 + len, "</Time>", 7) == 0 )
        {
            getTimeFromString(line + 6, &(**appointment).zeit);
        }
    }

    if(strncmp(line, "<Description>", 13) == 0){
        int len = strlen(line + 13) -15;

        if (strncmp(line + 13 + len, "</Description>", 14) == 0 )
        {
            (**appointment).Description = calloc( len + 1, sizeof( char ) );
            strncpy((**appointment).Description, line + 13, len);
        }
    }

    if(strncmp(line, "<Location>", 10) == 0){
        int len = strlen(line + 10) -12;

        if (strncmp(line + 10 + len, "</Location>", 11) == 0 )
        {
            (**appointment).Place = calloc( len + 1, sizeof( char ) );
            strncpy((**appointment).Place, line + 10, len);
        }
    }

    if(strncmp(line, "<Duration>", 10) == 0){
        int len = strlen(line + 10) -12;

        if (strncmp(line + 10 + len, "</Duration>", 11) == 0 )
        {
            (**appointment).Duration = calloc( len + 1, sizeof( TTime ) );
            getTimeFromString(line + 6, (**appointment).Duration);
        }
    }
}
