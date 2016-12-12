//
//  calendar.h
//  Üb4
//
//  Created by Andry Valderrama on 12.12.16.
//  Copyright © 2016 Andry Valderrama. All rights reserved.
//

#ifndef calendar_h
#define calendar_h
#include "datastructure.h"

void createAppointment();
void editAppointment();
void deleteAppointment();
void searchAppointment();
void sortCalendar();
void listCalendar();
void exitProg();
void listAppointment(TAppointment *, int);
int compareDate(TAppointment *, TAppointment*);

#endif /* calendar_h */
