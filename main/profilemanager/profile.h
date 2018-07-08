// Copyright (c) 2018 Jan Kowalewicz. All rights reserved.

#ifndef __profile_h__
#define __profile_h__

#include "../fileio/ini.h"

#include <QString>
#include <QStringList>

class profile {
    public:
    profile(const QString &_profile_file);
    ~profile();
    
    // returning
    QString get_profile_creator();
    QString get_profile_username();
    QString get_profile_fav_color();
    QString get_profile_picture();
#if 0
    QString get_profile_pref_bluetooth_device();
    QStringList get_profile_bluetooth_inf();
#endif
    QStringList get_profile_fav_playlists();
    QStringList get_profile_fav_radios();
#if 0
    QStringList get_profile_fav_apps();
#endif

    protected:
    ini_class *ini;
    QString profile_file;
    bool profile_exists_and_correct(const QString &_profile_file);
    QStringList list_helper(const QString &l);
};

#endif // __profile_h__
