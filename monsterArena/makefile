 #CXX and FLAGS
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

 #SOURCES
SRCS = *.cpp

 #HEADERS
HEADERS = *.hpp

 #OBJECTS
OBJS = *.o

 #DOCUMENTATION
DOCS = *.pdf

 #PROGRAMS
PROGS = tourn

 #COMPRESSED FILE
TAR = cs162_Assignment4_mathewmcdade.tar.bz2

# #####################################################
# #BUILD and TAR
# #####################################################

tourn: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o tourn

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOCS} makefile

##################
#CLEAN
##################

clean:
	rm -f ${PROGS} *.o *~
