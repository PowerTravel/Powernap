# Valid workstations are "OSX" and "UNIX"
WORKSTATION = OSX


# POSSIBLE UNIX LINKS FLAGS:
# -lglfw3 -lGLU -lGL -lX11 -lXxf86vm -lXrandr -lpthread -lXi  -lXrandr -lXcursor -lXfixes



#==== Common flags, settings and obj-files Settings ====#
# CXX 		is the active compiler
# TARGET	is the name of the executable file
# C_WFLAGS	contain common warning flags
# C_OBJS	contain common object-files. Object files should be named after the soruce
#		files but have .o - extention.

CXX = g++ -g
TARGET = main.out
TESTTARGET = test.out
C_WFLAGS = -Wall -Wsign-compare 
C_OBJS = main.o MainWindow.o  ShaderTools.o Timer.o

# == System Specific flags == #
# Objs 		are to be named the same as the source-files except for .o - extention
# WFLAGS 	are warning-flag and compiler flags
# INCLUDEFLAGS 	are paths to headers
# LINKFLAGS 	are the actual source-packages that needs linking.

#==== UNIX Specific Settings ====#
ifeq ($(WORKSTATION),UNIX)
OBJS = $(C_OBJS)
WFLAGS = $(C_WFLAGS)
#INCLUDEFLAGS = `pkg-config --cflags gtk+-2.0`
#LINKFLAGS = -export-dynamic -lm -lXext -lX11 `pkg-config --libs gtk+-2.0` -lGL -lGLEW -lGLU -lglut
INCLUDEFLAGS =
LINKFLAGS = -export-dynamic -lglfw3 -lGLU -lGL -lGLEW -lX11 -lpthread -lXi -lXrandr -lXcursor -lXxf86vm -lassimp

endif

#==== OSX Specific Settings ====#
ifeq ($(WORKSTATION),OSX)
OBJS = $(C_OBJS)
WFLAGS = $(C_WFLAGS)
INCLUDEFLAGS = -I/opt/local/include 
LINKFLAGS = -framework OpenGL -framework cocoa -framework IOKit -lglfw3 -lGLEW -lassimp

endif

#=== Execution ===#
# DEPS		is used to recompile *.o files whos header files have been edited
# OFLAGS 	is used for building Object files.
# TargetFLAGS 	is used for building target.

DEPS := $(OBJS:.o=.d)

OFLAGS = $(INCLUDEFLAGS) $(WFLAGS) -std=c++11
TARGETFLAGS = $(LINKFLAGS)

# Buld Target
all: $(TARGET) 

# Remove Target, *.o and *.d files
clean:	
	rm -f $(OBJS) $(DEPS) $(TARGET) *.gch

tidy:
	rm -f $(OBJS) $(DEPS)

# Clean up and rebuild from scratch
rebuild: clean all

# Build target
$(TARGET):  $(OBJS)	
	$(CXX)  $(OBJS) $(TARGETFLAGS) -o $(TARGET) 

# Build object files
%.o: %.cpp
	$(CXX) -MMD -MP -D$(WORKSTATION) $(OFLAGS) -c $<

# Include dependencies
-include $(DEPS)


### TEST PROGRAMS ###

TESTTARGET = test.out
#TESTOBJ = Hvec.cpp hvectest.cpp # Hvec
TESTOBJ = Hmat.cpp Hvec.cpp hmattest.cpp  # Hmat

test:
	$(CXX) -std=c++11 -g $(TESTOBJ) -o $(TESTTARGET)
	
cleantest:
	rm -f $(TESTTARGET)
