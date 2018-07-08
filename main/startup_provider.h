// Copyright (c) 2018 Jan Kowalewicz. All rights reserved.

#ifndef __startup_provider_h__
#define __startup_provider_h__

#include <QString>

class startup_provider {
    public:
    int fire();
    
    protected:
    bool is_init_run();
    QString current_profile_path();
};

#endif // __startup_provider_h__
