exampledir = $(datadir)/examples/theo/chicken
example_DATA = theo.egg

EXTRA_DIST = theo.scm theo.setup

theo.egg: theo.scm theo.setup
	$(TAR) cvf $@ theo.scm theo.setup

CLEANFILES= theo.egg

