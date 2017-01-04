/*
 *  fagelmatare-serializer
 *    Library used for binary translation for communication between master and
 *    slave via serialization
 *  serializer.c
 *    Routines for serializing/deserializing events
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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#include "events.h"
#include "serializer.h"

unsigned char *
serialize_int32_t (unsigned char *buffer, int32_t value)
{
	buffer[0] = value >> 24;
	buffer[1] = value >> 16;
	buffer[2] = value >> 8;
	buffer[3] = value;
	return buffer + 4;
}

unsigned char *
serialize_int8_t (unsigned char *buffer, int8_t value)
{
	buffer[0] = value;
	return buffer + 1;
}

unsigned char *
serialize_fgevent (unsigned char *buffer, struct fgevent *value)
{
	buffer = serialize_int32_t (buffer, value->id);
	buffer = serialize_int8_t (buffer, value->writeback);
	buffer = serialize_int32_t (buffer, value->length);
	for (int i = 0; i < value->length; i++) {
		buffer = serialize_int32_t (buffer, value->payload[i]);
	}
	return buffer;
}