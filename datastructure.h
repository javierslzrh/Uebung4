//
//  datastructure.h
//  Üb4
//
//  Created by Andry Valderrama on 12.12.16.
//  Copyright © 2016 Andry Valderrama. All rights reserved.
//

#ifndef datastructure_h
#define datastructure_h

#define MAX 100
#define NUMPOINTS 7
#define TEXT 255
//#define TIME 9
//#define DATE 11

typedef enum
{
    NotADay = 0,
    Mo,
    Tu,
    We,
    Th,
    Fr,
    Sa,
    Su
}TDayOfTheWeek;

typedef struct
{
    int Day;
    int Month;
    int Year;
    TDayOfTheWeek Wochentag;
} TDate;

typedef struct
{
    int Second;
    int Minute;
    int Hour;
} TTime;

typedef struct {
    
    TDate datum;
    TTime zeit;
    char *Description;
    char *Place;
    TTime *Duration;
}TAppointment;

extern int countAppointment;
extern TAppointment Calendar[];

#endif /* datastructure_h */
