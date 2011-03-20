#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.61])
AC_INIT([libtheo], [0.0.0], [iratqq@gmail.com])
AC_CONFIG_SRCDIR([lib/theo.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([1.9.6])
AM_MAINTAINER_MODE

# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_PATH_PROG(TAR, tar)

# Checks for libraries.
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UINT32_T

# Checks for library functions.
AC_CHECK_FUNCS([arc4random_uniform])

AC_ARG_ENABLE(lua,
  AC_HELP_STRING([--enable-lua],
                 [enable lua binding @<:@default=no@:>@]),
  [
    PKG_CHECK_MODULES(LUA, lua >= 5.0.0, use_lua="yes", use_lua="no")
    if test x$use_lua = xyes; then
      # XXX
      LUA_CMOD=`pkg-config --define-variable=prefix=${prefix} --variable INSTALL_CMOD lua`
    else
       use_lua="no"
    fi
  ],
  [
    use_lua="no"
  ])

AM_CONDITIONAL(BUILDABLE_LUA, test x$use_lua = xyes)
AC_SUBST(LUA_CMOD)

AC_ARG_ENABLE(erlang,
  AC_HELP_STRING([--enable-erlang],
                 [with erlang binding @<:@default=no@:>@]),
  [
    AM_WITH_ERLANG
    use_erlang="yes"
  ],
  [
    use_erlang="no"
  ])

AM_CONDITIONAL(BUILDABLE_ERLANG, test x$use_erlang = xyes)

AC_MSG_RESULT([
Configure Result :
  erlang      : ${use_erlang}
  lua         : ${use_lua}
])

AC_CONFIG_FILES([theo.pc
		 Makefile
		 include/Makefile
		 lib/Makefile
		 bindings/Makefile
		 bindings/chicken/Makefile
		 bindings/common-lisp/Makefile
		 bindings/erlang/Makefile
		 bindings/erlang/c_src/Makefile
		 bindings/erlang/src/Makefile
		 bindings/lua/Makefile
		 bindings/python/Makefile
		 bindings/ruby/Makefile])

AC_OUTPUT
