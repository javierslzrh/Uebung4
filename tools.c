//
//  tools.c
//  Üb4
//
//  Created by Andry Valderrama on 12.12.16.
//  Copyright © 2016 Andry Valderrama. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
//#include "escapesequenzen.h"

void clearBuffer(void)
{   char dummy;
    do
        scanf("%c",&dummy);
    while (dummy != '\n');
}

void clearScreen()
{
    printf("\033");
}


void waitForEnter()
{
    printf("\nBitte Eingabetaste druecken ...\n");
    unsigned char c1;
    c1 = getchar();
}

int askYesOrNo(char T[])
{
    char Frage = 'j';
    int  W = 0;
    do
    {
        printf("\nMöchten Sie noch einmal (j/n)? ");
        scanf("%c", &Frage);
        
        if(Frage != '\n')
            clearBuffer();
        
        if( (Frage != 'j') && (Frage != 'J') && (Frage != 'N') && (Frage != 'n') )
            printf("\nFalsche Eingabe!");
        
        if((Frage == 'N') || (Frage == 'n'))
            W = 1;
        else if((Frage == 'J') || (Frage == 'j'))
            W = 1;
        else
            W = 0;
    } while ( W == 0);
    
    return ( (Frage == 'j') || (Frage == 'J') );
}

/***************************************************
 * printLine                                        *
 ****************************************************/
void printLine(char Zeichen, int Anz)
{
    do
    {
        printf("%c",Zeichen);
        Anz--;
    } while (Anz);
    
}



/**************************************************************
 //bekommt den Text vom Bernutzer
 **************************************************************/
void getText(char *textEingabe, int Maxlen, char **text, int required)
{
    char *input = calloc(Maxlen, sizeof(char));
    int isValid;
    char *pch;
    
    
    do
    {
        isValid = 1;
        printf("%s", textEingabe);
        fgets(input, Maxlen, stdin);
        pch = strchr(input, 10);
        if (pch != NULL)
        {
            *pch = '\0';
        }
        
        if (required && strlen(input) == 1) {
            printf("Der Text ist erforderlich!!!\n");
            isValid = 0;
        }
        
    } while (!isValid);
    
    *text = calloc(strlen(input), sizeof(char));
    strcpy(*text, input);
    free(input);
}

