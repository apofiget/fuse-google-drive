/*
	fuse-google-drive: a fuse filesystem wrapper for Google Drive
	Copyright (C) 2012  James Cline

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License version 2 as
 	published by the Free Software Foundation.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along
	with this program; if not, write to the Free Software Foundation, Inc.,
	51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef _CURL_INTERFACE_H
#define _CURL_INTERFACE_H

#include <curl/curl.h>
#include <curl/multi.h>

#include "str.h"

struct response_t {
	struct str_t message;
	struct str_t headers;

	int flags;
};

struct request_t {
	struct response_t response;
	CURL* handle;
	struct curl_slist* headers;
};

enum request_type_e {
	POST,
	GET,
};

int ci_init();
int ci_destroy();

#endif
