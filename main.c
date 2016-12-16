//
//  main.c
//  Üb4
//
//  Created by Andry Valderrama on 12.12.16.
//  Copyright © 2016 Andry Valderrama. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//#include "escapesequenzen.h"
#include "datastructure.h"
#include "menu.h"
#include "calendar.h"
#include "datetime.h"
#include "database.h"
#include "tools.h"



int main()
{
    loadCalendar();
    //Deklaration der Variablen für das Menü
    int wahl_m;
    char *Menu = "Terminverwaltung V 0.2";
    char *punkte[] = {"1. Neuen Termin anlegen",
        "2. Termin bearbeiten",
        "3. Termin loeschen",
        "4. Termin suchen",
        "5. Termine sortieren",
        "6. Termine auflisten",
        "7. Programm beenden"};



    do
    {
        clearScreen();
        wahl_m = getMenu(Menu, punkte, NUMPOINTS);


        switch (wahl_m) {
            case 1: createAppointment();
                break;
            case 2: editAppointment();
                break;
            case 3: deleteAppointment();
                break;
            case 4: searchAppointment();
                break;
            case 5: sortCalendar();
                break;
            case 6: listCalendar();
                break;
            case 7: exitProg();
                break;
            default: printf("\nDas ist keine Option");
                break;

        }


        //waitForEnter();
        //if (askYesOrNo("\nMoechten Sie noch einmal (j/n)? ") == 1) {
        //clearScreen();
        //return 0;
        //}

    } while(wahl_m != 7); //(wahl_m == 0)


    return 0;
}
