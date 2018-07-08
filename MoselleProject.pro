# Copyright (c) 2018 Jan Kowalewicz. All rights reserved.

QT += core gui widgets network multimedia bluetooth
TARGET = msle
TEMPLATE = app

SOURCES += main/main.cpp \
            main/fileio/ini.cpp \
            main/profilemanager/profile.cpp

HEADERS += main/fileio/ini.h \
            main/profilemanager/profile.h
