#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=g77
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/lib/src/events.o \
	${OBJECTDIR}/lib/src/handle.o \
	${OBJECTDIR}/lib/src/memory.o \
	${OBJECTDIR}/lib/src/messages.o \
	${OBJECTDIR}/lib/src/properties.o \
	${OBJECTDIR}/vendor/bockel/radixtree/src/radixtree.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgwi.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgwi.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgwi.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgwi.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgwi.a

${OBJECTDIR}/lib/src/events.o: lib/src/events.c 
	${MKDIR} -p ${OBJECTDIR}/lib/src
	${RM} "$@.d"
	$(COMPILE.c) -g -DUNICODE -D_UNICODE -Ivendor/bockel/radixtree/src -Ilib/src -Ilib/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/src/events.o lib/src/events.c

${OBJECTDIR}/lib/src/handle.o: lib/src/handle.c 
	${MKDIR} -p ${OBJECTDIR}/lib/src
	${RM} "$@.d"
	$(COMPILE.c) -g -DUNICODE -D_UNICODE -Ivendor/bockel/radixtree/src -Ilib/src -Ilib/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/src/handle.o lib/src/handle.c

${OBJECTDIR}/lib/src/memory.o: lib/src/memory.c 
	${MKDIR} -p ${OBJECTDIR}/lib/src
	${RM} "$@.d"
	$(COMPILE.c) -g -DUNICODE -D_UNICODE -Ivendor/bockel/radixtree/src -Ilib/src -Ilib/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/src/memory.o lib/src/memory.c

${OBJECTDIR}/lib/src/messages.o: lib/src/messages.c 
	${MKDIR} -p ${OBJECTDIR}/lib/src
	${RM} "$@.d"
	$(COMPILE.c) -g -DUNICODE -D_UNICODE -Ivendor/bockel/radixtree/src -Ilib/src -Ilib/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/src/messages.o lib/src/messages.c

${OBJECTDIR}/lib/src/properties.o: lib/src/properties.c 
	${MKDIR} -p ${OBJECTDIR}/lib/src
	${RM} "$@.d"
	$(COMPILE.c) -g -DUNICODE -D_UNICODE -Ivendor/bockel/radixtree/src -Ilib/src -Ilib/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/src/properties.o lib/src/properties.c

${OBJECTDIR}/vendor/bockel/radixtree/src/radixtree.o: vendor/bockel/radixtree/src/radixtree.c 
	${MKDIR} -p ${OBJECTDIR}/vendor/bockel/radixtree/src
	${RM} "$@.d"
	$(COMPILE.c) -g -DUNICODE -D_UNICODE -Ivendor/bockel/radixtree/src -Ilib/src -Ilib/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/vendor/bockel/radixtree/src/radixtree.o vendor/bockel/radixtree/src/radixtree.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgwi.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
