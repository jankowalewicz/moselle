// Copyright (c) 2018 Jan Kowalewicz. All rights reserved.

#include "homescreen.h"

#include <QMainWindow>
#include <QWidget>
#include <QFileInfo>

homescreen::homescreen(QWidget *parent) : QMainWindow(parent) {
    if (this->is_devenv()) {
        this->resize(320, 240);
    } else {
        this->showFullScreen(); // fit to screen if we're on end device
    }
}

homescreen::~homescreen() {
    
}

bool homescreen::is_devenv() {
    QFileInfo fi("/home/moselle/index");
    if (!fi.exists()) {
        return true;
    } else {
        return false;
    }
    return true;
}
