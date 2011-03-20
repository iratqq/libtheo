lua_libdir = $(LUA_CMOD)/theo

lua_lib_LTLIBRARIES = theo.la
theo_la_SOURCES = lua-theo.c
AM_CFLAGS = ${LUA_CFLAGS}
theo_la_LIBADD = ${LUA_LIBS} $(top_srcdir)/lib/libtheo.la
AM_LDFLAGS = -rpath $(lua_libdir) -avoid-version -module
AM_CPPFLAGS = -I$(top_srcdir)/include
