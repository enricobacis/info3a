MY_CFLAGS = 
MY_LIBS   = 
CPPFLAGS  = -Wall
LDFLAGS   = 
SRCDIR    = src
OUTDIR    = bin
PROGRAM   = cpp
SRCEXTS   = .cpp
HDREXTS   = .h

CXXFLAGS  = -g -O2

SHELL     = /bin/sh
EMPTY     =
SPACE     = $(EMPTY) $(EMPTY)

ifeq ($(PROGRAM),)
  CUR_PATH_NAMES = $(subst /,$(SPACE),$(subst $(SPACE),_,$(CURDIR)))
  PROGRAM = $(word $(words $(CUR_PATH_NAMES)),$(CUR_PATH_NAMES))
  ifeq ($(PROGRAM),)
    PROGRAM = a.out
  endif
endif

ifeq ($(SRCDIR),)
  SRCDIR = .
endif

ifeq ($(OUTDIR),)
  OUTDIR = $(SRCDIR)
endif

SOURCES = $(wildcard $(addprefix $(SRCDIR)/*, $(SRCEXTS)))
SRC     = $(subst $(SRCDIR)/, , $(SOURCES))
OBJS    = $(addsuffix .o, $(basename $(SRC)))

COMPILE.cxx = $(CXX) $(MY_CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c
LINK.cxx    = $(CXX) $(MY_CFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)

.PHONY: all objs tags ctags clean distclean help show

all: $(PROGRAM)

objs: $(OBJS)

%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OUTDIR)
	$(COMPILE.cxx) $< -o $(OUTDIR)/$@

$(PROGRAM): $(OBJS)
	$(LINK.cxx) $(addprefix $(OUTDIR)/, $(OBJS)) -o $(OUTDIR)/$@

clean:
	$(RM) $(OBJS) $(PROGRAM) $(PROGRAM).exe
	rm -rf $(OUTDIR)

help:
	@echo 'Usage: make [TARGET]'
	@echo 'TARGETS:'
	@echo '  all       (=make) compile and link.'
	@echo '  objs      compile only (no linking).'
	@echo '  clean     clean objects and the executable file.'
	@echo '  distclean clean objects, the executable and dependencies.'
	@echo '  show      show variables (for debug use only).'
	@echo '  help      print this message.'

show:
	@echo 'PROGRAM     :' $(PROGRAM)
	@echo 'SRCDIR      :' $(SRCDIR)
	@echo 'OUTDIR      :' $(OUTDIR)
	@echo 'SOURCES     :' $(SOURCES)
	@echo 'SRC         :' $(SRC)
	@echo 'OBJS        :' $(OBJS)
	@echo 'COMPILE.c   :' $(COMPILE.c)
	@echo 'COMPILE.cxx :' $(COMPILE.cxx)
	@echo 'link.c      :' $(LINK.c)
	@echo 'link.cxx    :' $(LINK.cxx)
