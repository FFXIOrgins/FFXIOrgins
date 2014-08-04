/*
===========================================================================

Copyright (c) 2010-2014 Darkstar Dev Teams

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see http://www.gnu.org/licenses/

This file is part of DarkStar-server source code.

===========================================================================
*/
#include "../common/sql.h"
#include "../common/socket.h"

#include <zmq.hpp>

enum CHATTYPE
{
	CHAT_TELL		= 1,
	CHAT_PARTY		= 2,
	CHAT_LINKSHELL	= 3,
	CHAT_YELL		= 4,
	CHAT_SERVMES	= 5,
	CHAT_PT_INVITE	= 6,
	CHAT_PT_INV_RES = 7,
	CHAT_PT_RELOAD  = 8,
    CHAT_PT_DISBAND = 9,
	CHAT_MSG_DIRECT = 10
};

extern zmq::context_t zContext;
extern zmq::socket_t* zSocket;
extern Sql_t* ChatSqlHandle;

void chat_init();

void chat_listen();
void chat_parse(CHATTYPE type, zmq::message_t* extra, zmq::message_t* packet);
void chat_send(uint64 ipp, CHATTYPE type, zmq::message_t* extra, zmq::message_t* packet);