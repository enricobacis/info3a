# Customize this part on your setting

SRCDIR      = src
OPENJMLLIB  = lib/openjml.jar
PACKAGE     = university
MAINCLASS   = Demo

# Customize this is you are not on Linux/Mac
# (a better way would be to switch to Linux/Mac)

SEP   = /
CPSEP = :

# Do not change after this point unless you know what you are doing

ifeq ($(SRCDIR),)
  SRCDIR = .
endif

ifeq ($(PACKAGE),)
  MAIN = $(MAINCLASS)
else
  MAIN = $(PACKAGE).$(MAINCLASS)
endif

SOURCES  = $(wildcard $(addprefix $(SRCDIR)$(SEP)$(PACKAGE)$(SEP)*, java))
CLASSES  = $(addsuffix .class, $(basename $(SOURCES)))
OPENJML  = $(CURDIR)$(SEP)$(OPENJMLLIB)

run: all

all: clean clearscr rac exec

rac: clearscr
	@echo 'Compiling with OpenJML (RAC)...'
	@echo ''
	@java -jar "$(OPENJML)" -rac -noPurityCheck $(SOURCES)

exec:
	@echo ''
	@echo 'Executing with OpenJML...'
	@echo ''
	@cd $(SRCDIR) && java -cp "$(OPENJML)$(CPSEP)." $(MAIN)

check: clearscr
	@echo 'Checking with OpenJML ...'
	@echo ''
	@java -jar "$(OPENJML)" -check -noPurityCheck $(SOURCES)

check-purity: clearscr
	@echo 'Checking with OpenJML (Purity enabled with hidden openjml.jar errors) ...'
	@echo ''
	@java -jar "$(OPENJML)" -check $(SOURCES) | awk "/^$(SRCDIR)/,/ +\^$$/"

check-purity-all: clearscr
	@echo 'Checking with OpenJML (Purity enabled) ...'
	@echo ''
	@java -jar "$(OPENJML)" -check $(SOURCES)

clean:
	@rm -rf $(CLASSES)
	@echo 'Done Cleaning'
	@echo ''

clearscr:
	@clear

help:
	@echo 'Usage: make [TARGET]'
	@echo 'TARGETS:'
	@echo '  all                (=make) compile and execute with OpenJML (RAC).'
	@echo '  rac                compile only with OpenJML (RAC).'
	@echo '  exec               execute with OpenJML without recompiling.'
	@echo '  check              check with OpenJML.'
	@echo '  check-purity       check with OpenJML and Purity (lib warnings disabled).'
	@echo '  check-purity-all   check with OpenJML and Purity (lib warnings enabled).'
	@echo '  clean              clean class files.'
	@echo '  help               print this message.'
