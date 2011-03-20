exampledir = $(datadir)/examples/theo/chicken

example_DATA = theo.egg

theo.egg: theo.scm theo.setup
	$(TAR) cvf $@ theo.scm theo.setup

CLEANFILES= theo.egg

