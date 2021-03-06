TYPE = APP

NAME = Microbe

SYSTEM_INCLUDE_PATHS = /boot/common/include/python2.6

SRCS = App.cpp
SRCS += Highlighter.cpp
SRCS += MainWindow.cpp
SRCS += MainView.cpp
SRCS += PythonPlugin.cpp
SRCS += TextRange.cpp
LIBS = be python2.6 tracker #stdc++

RDEFS = Microbe.rdef

# include the makefile-engine
include $(BUILDHOME)/etc/makefile-engine
