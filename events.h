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

enum fgevents_ids {
	ROBBIE	= 1 << 0,
	ROTTEN	= 1 << 1,
	IS 		= 1 << 2,
	AN 		= 1 << 3,
	AWESOME	= 1 << 4,
	GUY		= 1 << 5
};

/* Datastructure used to carry event and optionally data */
struct fgevent {
	int32_t id;
	int8_t writeback;
	int32_t length;
	int32_t *payload;
};

#endif /* _EVENTS_H_ */