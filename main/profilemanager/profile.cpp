// Copyright (c) 2018 Jan Kowalewicz. All rights reserved.

#include "profile.h"
#include "../fileio/ini.h"

#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QRegExp>

profile::profile(const QString &_profile_file) {
    if (profile_exists_and_correct(_profile_file)) {
        ini = new ini_class();
        profile_file = _profile_file;
        ini->set_file(profile_file);
    } else {
        profile_file = "E";
    }
}

profile::~profile() {
    delete ini;
}

QString profile::get_profile_creator() {
    return ini->get_val("CREATOR");
}

QString profile::get_profile_username() {
    return ini->get_val("USERNAME");
}

QString profile::get_profile_fav_color() {
    return ini->get_val("FAV_COLOR_SYS");
}

QString profile::get_profile_picture() {
    // This contains the absolute path to the picture on system.
    return ini->get_val("PROFILE_PICTURE");
}

QStringList profile::get_profile_fav_playlists() {
    QString all_playlists = ini->get_val("FAV_PLAYLISTS");
    return this->list_helper(all_playlists);
}

QStringList profile::get_profile_fav_radios() {
    QString all_radios = ini->get_val("FAV_RADIOS");
    return this->list_helper(all_radios);
}

bool profile::profile_exists_and_correct(const QString &_profile_file) {
    QFileInfo fi(_profile_file);
    if (fi.exists()) {
        QString cnt;
        QFile f(_profile_file);
        if (f.open(QIODevice::ReadOnly)) {
            QTextStream rd(&f);
            cnt = rd.readAll();
            f.close();  
        } else {
            return false;
        }
        if (cnt.contains("PVER = 1.0")) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
    return false;
}

QStringList profile::list_helper(const QString &l) {
    QRegExp pattern("\\(([^()]+)\\)");
    pattern.setMinimal(true);
    QStringList ret;
    int pos = 0;
    while ((pos = pattern.indexIn(l, pos)) != -1) {
        ret << pattern.cap(1);
        pos += pattern.matchedLength();
    }
    return ret;
}
