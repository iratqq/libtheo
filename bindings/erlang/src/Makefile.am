erldir = $(libdir)/erlang/theo/src
erl_DATA = theo.erl
beamdir = $(libdir)/erlang/theo/ebin
beam_DATA = theo.beam

EXTRA_DIST = $(erl_DATA) $(beam_DATA)

.erl.beam:
	@ERLC@ -W $(ERLC_FLAGS) $<

CLEANFILES= $(beam_DATA)

