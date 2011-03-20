beamdir = $(libdir)/erlang/theo/ebin
beam_DATA = theo.beam
erldir = $(libdir)/erlang/theo/src
erl_DATA = theo.erl

.erl.beam:
	@ERLC@ -W $(ERLC_FLAGS) $<

CLEANFILES= $(beam_DATA)

