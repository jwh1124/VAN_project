include $(ORACLE_HOME)/precomp/lib/env_precomp.mk

LFLAGS=$(PFLAGS)
LFLAGS64=-I.

SF_C_INCS=$(SF_XDSP_API_INC)
SF_C_LIBS=$(SF_XDSP_API_LIB)

INCLUDE=$(I_SYM). $(I_SYM)$(PRECOMPHOME)public $(I_SYM)$(RDBMSHOME)public $(I_SYM)$(RDBMSHOME)demo $(I_SYM)$(PLSQLHOME)public $(I_SYM)$(NETWORKHOME)public
LIBDIR=-L$(ORACLE_HOME)/lib/ -lclntsh -lm

all : thread_server batch timeout_server\

thread_server: thread_server.pc
	proc $(PROCFLAGS) $(@).pc
	cc -pthread $(LFLAGS) $(LFLAGS64) $(SF_C_INCS) -c -g $(@).c
	cc -pthread $(LFLAGS) $(LFLAGS64)  -o $(@) $(@).o $(LIBDIR) $(SF_C_LIBS)
	rm $(@).lis $(@).o
	
batch: batch.pc
	proc $(PROCFLAGS) $(@).pc
	cc -pthread $(LFLAGS) $(LFLAGS64) $(SF_C_INCS) -c -g $(@).c
	cc -pthread $(LFLAGS) $(LFLAGS64)  -o $(@) $(@).o $(LIBDIR) $(SF_C_LIBS)
	rm $(@).lis $(@).o
	
timeout_server: timeout_server.pc
	proc $(PROCFLAGS) $(@).pc
	cc -pthread $(LFLAGS) $(LFLAGS64) $(SF_C_INCS) -c -g $(@).c
	cc -pthread $(LFLAGS) $(LFLAGS64)  -o $(@) $(@).o $(LIBDIR) $(SF_C_LIBS)
	rm $(@).lis $(@).o