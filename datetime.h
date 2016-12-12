//
//  datetime.h
//  Üb4
//
//  Created by Andry Valderrama on 12.12.16.
//  Copyright © 2016 Andry Valderrama. All rights reserved.
//

#ifndef datetime_h
#define datetime_h

void printDate(TAppointment * date);
void printTime(TAppointment *time);
int  getDate(char * Eingabe, TDate * Datenstruktur);
int  getTime(char * Eingabe, TTime *timeStruktur);
int  isLeapYear(int j);
int  isDateValid(TDate date);
int  getDateFromString(char input[], TDate *date);
int  isTimeValid();
int  getTimeFromString(char input[], TTime *time);

#endif /* datetime_h */
