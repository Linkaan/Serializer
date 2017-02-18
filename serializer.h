/*
 *  serializer.h
 *    The names of functions callable from within serializer
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

#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_

#include "events.h"

/* Routines to serialize the used data structures */
extern unsigned char *serialize_fgevent (unsigned char *,
                                         struct fgevent *);
/* These functions assumes value is big-endian and htons and htonl can be used
   to convert between host and network byte order to ensure the data is
   parsed correctly */
extern unsigned char *serialize_int32_t (unsigned char *, int32_t);
extern unsigned char *serialize_int8_t (unsigned char *, int8_t);

/* Routines to deserialize the used data structures */
extern unsigned char *deserialize_fgevent (unsigned char *,
                                           struct fgevent *);
extern unsigned char *deserialize_int32_t (unsigned char *, int32_t *);
extern unsigned char *deserialize_int8_t (unsigned char *, int8_t *);

#endif /* _SERIALIZER_H_ */
