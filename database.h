//
//  database.h
//  Üb4
//
//  Created by Andry Valderrama on 12.12.16.
//  Copyright © 2016 Andry Valderrama. All rights reserved.
//

#ifndef database_h
#define database_h

void saveCalendar();
void loadCalendar();
void loadAppointment(TAppointment **appointment, char *line);

#endif /* database_h */
