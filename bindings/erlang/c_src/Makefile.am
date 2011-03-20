ERLANG_CFLAGS= @ERLANG_CFLAGS@

AM_CFLAGS= $(ERLANG_CFLAGS)
AM_CPPFLAGS = -I$(top_srcdir)/include

erl_libdir = $(prefix)/lib/erlang/theo/priv/lib
erl_lib_LTLIBRARIES= theo_drv.la

theo_drv_la_SOURCES= theo_drv.c
theo_drv_la_LDFLAGS= -module -avoid-version
theo_drv_la_LIBADD = ${LUA_LIBS} $(top_srcdir)/lib/libtheo.la
