TYPE = APP

NAME = Microbe

SYSTEM_INCLUDE_PATHS = /boot/common/include/python2.6

SRCS = App.cpp
SRCS += MainWindow.cpp
SRCS += MainView.cpp
SRCS += PythonPlugin.cpp
LIBS = be python2.6

RDEFS = Microbe.rdef

# include the makefile-engine
include $(BUILDHOME)/etc/makefile-engine
