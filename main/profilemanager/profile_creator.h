// Copyright (c) 2018 Jan Kowalewicz. All rights reserved.

#ifndef __profile_creator_h__
#define __profile_creator_h__

#include "../fileio/ini.h"

#include <QString>

class profile_creator {
    public:
    profile_creator(const QString &_profile_username, const QString &_profile_fav_color, const QString &_profile_picture);
    ~profile_creator();
    
    bool write_to_file(const QString &file_path);
    
    protected:
    QString profile_username;
    QString profile_fav_color; // as plain
    QString profile_picture; // absolute path
    ini_class *ini;
};

#endif // __profile_creator_h__
