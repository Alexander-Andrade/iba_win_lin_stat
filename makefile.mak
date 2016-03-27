PROGRAM = SysThreading.exe
CPPSOURCES = main.cpp
CPPOBJECTS = main.obj
CPPFLAGS = /RTC1 /EHsc
CPP = icl
#link objects
$(PROGRAM): $(CPPOBJECTS)
	link.exe /out:$@ $(CPPOBJECTS)
#build objects
main.obj:  main.cpp Thread.h WinThread.h
	
#clean
clean: del $(CPPOBJECTS) $(PROGRAM)