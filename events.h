/*
 *  events.h
 *    Defines structure for events that will be sent between master and slave
 *****************************************************************************
 *  This file is part of Fågelmataren, an embedded project created to learn
 *  Linux and C. See <https://github.com/Linkaan/Fagelmatare>
 *  Copyright (C) 2015-2017 Linus Styrén
 *
 *  Fågelmataren is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the Licence, or
 *  (at your option) any later version.
 *
 *  Fågelmataren is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public Licence for more details.
 *
 *  You should have received a copy of the GNU General Public Licence
 *  along with Fågelmataren.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************
 */

#ifndef _EVENTS_H_
#define _EVENTS_H_

#ifdef __AVR__
#include <inttypes.h>
#endif

#define APPLICATION_BASE_ID (1 << 10)
#define ABI APPLICATION_BASE_ID

/* 4 bytes long id
 * 1 byte long sender id
 * 1 byte long receiver id
 * 1 byte long writeback boolean
 * 4 bytes long length
 */
#define FGEVENT_HEADER_SIZE 11

enum user_ids {
	FG_AVR = 1 << 0,
	FG_MASTER = 1 << 1,
	FG_SLAVE = 1 << 2,
	FG_DATALOGGER = 1 << 3
};

enum sensor_data_types {
	CPUTEMP = 1,
	OUTTEMP = 2,
	INTEMP = 3,
	PRESSURE = 4,
	HUMIDITY = 5
};

enum fgevents_ids {
	FG_CONFIRMED = 1 << 0,
	FG_CONNECTED = 1 << 1,
	FG_DISCONNECTED = 1 << 2,
	FG_ALIVE = 1 << 3,
	FG_ALIVE_CONFRIM = 1 << 4,
	FG_USER_OFFLINE = 1 << 5,
	FG_SENSOR_DATA	= ABI + 1,
	FG_RETRIEVE_TEMP = ABI + 2,
	FG_TEMP_RESULT = ABI + 3,
};

/* Datastructure used to carry event and optionally data */
struct fgevent {
	int32_t id;

	int8_t sender;
	int8_t receiver;

	int8_t writeback;

	int32_t length;
	int32_t *payload;
};

#endif /* _EVENTS_H_ */