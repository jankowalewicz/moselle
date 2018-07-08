// Copyright (c) 2018 Jan Kowalewicz. All rights reserved.

#ifndef __homescreen_h__
#define __homescreen_h__

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class homescreen : public QMainWindow {
    Q_OBJECT
    public:
    explicit homescreen(QWidget *parent = 0);
    ~homescreen();
    
    protected:
    bool is_devenv();
};

#endif // __homescreen_h__
