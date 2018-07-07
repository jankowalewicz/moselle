// Copyright (c) 2018 Jan Kowalewicz. All rights reserved.

#include <QString>

class ini_class {
    public:
    bool set_file(const QString &_file_path);
    QString get_val(const QString &by_key);
    bool write_val(const QString &by_key, const QString &new_val);
    bool create_new_val(const QString &key, const QString &val);
    
    protected:
    bool file_exists(const QString &_file_path);
    
    private:
    QString file_path;
};
