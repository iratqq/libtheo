/*
 * Copyright (c) 2010 Iwata <iwata@quasiquote.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <string.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include "config.h"
#include "theo.h"

#define LIBNAME    "theo"
#define LIBVERSION LIBNAME " library for " LUA_VERSION

static int
Ptheo(lua_State *L)
{
	char *str = strdup(theo());

	lua_pushstring(L, str);
	return 1;
}

static const luaL_reg R[] =
{
	{ "theo", Ptheo },
	{ NULL, NULL }
};

LUALIB_API int
luaopen_theo(lua_State *L)
{
	luaL_openlib(L, LIBNAME, R, 0);
	lua_pushliteral(L, "version");           /** version */
	lua_pushliteral(L, LIBVERSION);
	lua_settable(L, -3);
	return 1;
}
