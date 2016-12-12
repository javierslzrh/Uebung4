//
//  menu.c
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
#include "menu.h"
#include "tools.h"



int getMenu(char * MenuT, char * MenuP[], int Anz)
{
    int i;
    
    
    do{
        clearScreen();
        printLine('\0',*MenuT);
        printf("%s\n",MenuT);
        printLine('=', sizeof("Terminverwaltung V0.2"));
        for (i = 0; i < Anz; i++)
        {
            //printLine('\0',strlen(*MenuP));
            printf("\n%s ",MenuP[i]);
            
        }
        
        do
        {
            printf("\n\nBitte wählen Sie eine Option aus: ");
            scanf("%d",&Anz);
            clearBuffer();
        } while (i < NUMPOINTS);
        if (Anz == 7) {
            exitProg();
        }
        if (Anz < 1 || Anz > 7) {
            printf("\nDas ist keine Option");
            printf("\nBitte Geben Sie eine Zahl zwischen 1 und 7 ein!!!");
            continue;
            
        }
        
    } while (Anz == NUMPOINTS);
    
    
    /*    printf("\nBitte Eingabetaste druecken ...\n");
     waitForEnter();
     if (askYesOrNo("\nMoechten Sie noch einmal (j/n)? ")) {
     clearScreen();
     return 0;
     }
     */
    
    return Anz;
}

