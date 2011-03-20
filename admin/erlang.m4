dnl
dnl check erlang
dnl  from ejabberd (http://ejabberd.jabber.ru/)
dnl
AC_DEFUN([AM_WITH_ERLANG],
[ AC_ARG_WITH(erlang,
	      [  --with-erlang=PREFIX    path to erlc and erl ])


   AC_PATH_TOOL(ERLC, erlc, , $PATH:$with_erlang:$with_erlang/bin)
   AC_PATH_TOOL(ERL, erl, , $PATH:$with_erlang:$with_erlang/bin)
   
   if test "z$ERLC" == "z" || test "z$ERL" == "z"; then
   		AC_MSG_ERROR([erlang not found])
   fi
   
   
   cat >>conftest.erl <<_EOF
   
-module(conftest).
-author('alexey@sevcom.net').

-export([[start/0]]).

start() ->
    EIDirS = code:lib_dir("erl_interface") ++ "\n",
    EILibS =  libpath("erl_interface") ++ "\n",
    RootDirS = code:root_dir() ++ "\n",
    file:write_file("conftest.out", list_to_binary(EIDirS ++ EILibS ++ RootDirS)),
    halt().

%% return physical architecture based on OS/Processor
archname() ->
    ArchStr = erlang:system_info(system_architecture),
    case os:type() of
	{win32, _} -> "windows";
	{unix,UnixName} ->
	    Specs = string:tokens(ArchStr,"-"),
	    Cpu = case lists:nth(2,Specs) of
		      "pc" -> "x86";
		      _ -> hd(Specs)
		  end,
	    atom_to_list(UnixName) ++ "-" ++ Cpu;
	_ -> "generic"
    end.

%% Return arch-based library path or a default value if this directory
%% does not exist
libpath(App) ->
    PrivDir    = code:priv_dir(App),
    ArchDir    = archname(),
    LibArchDir = filename:join([[PrivDir,"lib",ArchDir]]),
    case file:list_dir(LibArchDir) of
	%% Arch lib dir exists: We use it
	{ok, _List}  -> LibArchDir;
	%% Arch lib dir does not exist: Return the default value
	%% ({error, enoent}):
	_Error -> code:lib_dir("erl_interface") ++ "/lib"
    end.
	   
_EOF
   
   if ! $ERLC conftest.erl; then
   	   AC_MSG_ERROR([could not compile sample program])
   fi
   
   if ! $ERL -s conftest -noshell; then
       AC_MSG_ERROR([could not run sample program])
   fi
   
   if ! test -f conftest.out; then
       AC_MSG_ERROR([erlang program was not properly executed, (conftest.out was not produced)])
   fi
   
   # First line
   ERLANG_EI_DIR=`cat conftest.out | head -n 1`
   # Second line
   ERLANG_EI_LIB=`cat conftest.out | head -n 2 | tail -n 1`
   # Third line
   ERLANG_DIR=`cat conftest.out | tail -n 1`
   
   ERLANG_CFLAGS="-I$ERLANG_EI_DIR/include -I$ERLANG_DIR/usr/include"
   ERLANG_LIBS="-L$ERLANG_EI_LIB -lerl_interface -lei"
   
   AC_SUBST(ERLANG_CFLAGS)
   AC_SUBST(ERLANG_LIBS)
   AC_SUBST(ERLC)
   AC_SUBST(ERL)
])

