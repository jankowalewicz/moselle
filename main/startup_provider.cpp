// Copyright (c) 2018 Jan Kowalewicz. All rights reserved.

#include "startup_provider.h"

#include "fileio/ini.h"

#include <QString>
#include <QFileInfo>

int startup_provider::fire() {
    // pre-startup routine
    if (this->is_init_run()) {
        
    }
}

bool startup_provider::is_init_run() {
    QFileInfo fi("/home/moselle/index");
    if (!fi.exists()) {
        return true;
    } else {
        return false;
    }
    return false;
}

QString startup_provider::current_profile_path() {
    ini_class ini;
    return ini.get_val("CURRENT_PROFILE");
}
