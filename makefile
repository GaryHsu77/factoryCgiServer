
all: FactoryHome.cgi FactoryPSW.cgi FactoryProcess.cgi

FactoryHome.cgi: FactoryHome.c FactoryCGI.h
	gcc FactoryHome.c -o FactoryHome.cgi

FactoryPSW.cgi: FactoryPSW.c FactoryCGI.h
	gcc FactoryPSW.c -o FactoryPSW.cgi

FactoryProcess.cgi: FactoryProcess.c FactoryCGI.h
	gcc FactoryProcess.c -o FactoryProcess.cgi

clean:
	-rm -f *.cgi
	-rm -f *.exe
	-rm -f *~

tools: Tool1.exe

Tool1.exe: Tool1.c
	gcc Tool1.c -o Tool1.exe


