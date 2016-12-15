//
//  tools.h
//  Üb4
//
//  Created by Andry Valderrama on 12.12.16.
//  Copyright © 2016 Andry Valderrama. All rights reserved.
//

#ifndef tools_h
#define tools_h

void clearBuffer();
void clearScreen();
void waitForEnter();
int askYesOrNo(char *);
void printLine(char, int);
void getText(char *textEingabe, int Maxlen, char **text, int requiered);
void lTrim(char *);

#endif /* tools_h */
