// Copyright (c) 2018 Jan Kowalewicz. All rights reserved.

#include "ini.h"

#include <QString>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>

bool ini_class::set_file(const QString &_file_path) {
    if (this->file_exists(_file_path)) {
        file_path = _file_path;
        return true;
    } else {
        return false;
    }
    return false;
}

QString ini_class::get_val(const QString &by_key) {
    if (!file_path.isEmpty()) {
        QFile f(file_path);
        if (f.open(QIODevice::ReadOnly)) {
            QTextStream in(&f);
            while (!in.atEnd()) {
                QString l = in.readLine();
                QString key(by_key + " = ");
                int key_pos = l.indexOf(key);
                if (key_pos >= 0) {
                    return l.mid(key_pos + key.length());
                }
            }
        }
    } else {
        return by_key;
    }
    return by_key;
}

bool ini_class::write_val(const QString &by_key, const QString &new_val) {
    if (!file_path.isEmpty()) {
        QString cnt;
        QString old_val = this->get_val(by_key);
        QFile f(file_path);
        if (f.open(QIODevice::ReadWrite)) {
            QTextStream rd(&f);
            cnt = rd.readAll();
        }
        f.resize(0);
        f.close();
        QString old_l(by_key + " = " + old_val);
        QString new_l(by_key + " = " + new_val);
        cnt.replace(old_l, new_l);
        if (f.open(QIODevice::ReadWrite)) {
            QTextStream wr(&f);
            wr << cnt;
            return true;
        }
    } else {
        return false;
    }
    return false;
}

bool ini_class::create_new_val(const QString &key, const QString &val) {
    if (!file_path.isEmpty()) {
        QFile f(file_path);
        if (f.open(QIODevice::ReadWrite)) {
            QTextStream wr(&f);
            QString cnt = wr.readAll();
            f.resize(0);
            wr << cnt + key + " = " + val << endl;
            return true;
        }
    } else {
        return false;
    }
    return false;
}

bool ini_class::file_exists(const QString &_file_path) {
    QFileInfo fi(_file_path);
    return fi.exists();
}
