// Copyright (c) 2018 Jan Kowalewicz. All rights reserved.

#include "profile_creator.h"

#include "../fileio/ini.h"

#include <QString>
#include <QFile>
#include <QFileInfo>

profile_creator::profile_creator(const QString &_profile_username, const QString &_profile_fav_color, const QString &_profile_picture) : profile_username(_profile_username), profile_fav_color(_profile_fav_color), profile_picture(_profile_picture) {
    ini = new ini_class();
}

profile_creator::~profile_creator() {
    delete ini;
}

bool profile_creator::write_to_file(const QString &file_path) {
    QFileInfo fi(file_path);
    if (!fi.exists()) {
        QFile new_f(file_path);
        
        if (new_f.open(QIODevice::ReadWrite))
            new_f.close();
        
        ini->set_file(file_path);
        ini->create_new_val("PVER", "1.0");
        ini->create_new_val("CREATOR", "sys");
        ini->create_new_val("USERNAME", profile_username);
        ini->create_new_val("FAV_COLOR_SYS", profile_fav_color);
        ini->create_new_val("PROFILE_PICTURE", profile_picture);
        return true;
    } else {
        return false;
    }
    return false;
}
