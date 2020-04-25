# Makefile for p3
# COSC 160
# Spring 2019
# 

CPP = g++
CFLAGS = -pg -Wall -std=c++0x
SRCS = main.cpp ProcessTimer.cpp HashTable1.cpp HashTable2.cpp
OBJS = ${SRCS:.cpp=.o}
INCLS = ${SRCS:.cpp=.h}

p3: $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o p3

$(OBJS):
	$(CPP) $(CFLAGS) -c $*.cpp

depend: Makefile.dep
	$(CPP) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(SRCS) $(INCLS) Makefile Makefile.dep Main.h ProcessTimer.h HashTable1.h HashTable2.h HashNode.h

clean:
	rm -f *.o p3 core

include Makefile.dep
			
