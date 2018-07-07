// boilerplate code

#include "fileio/ini.h"
#include <QApplication>
#include <QMainWindow>
#include <QString>
#include <QPlainTextEdit>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QMainWindow window;
    QPlainTextEdit *editor = new QPlainTextEdit();
    window.setCentralWidget(editor);
    
    ini_class ini;
    ini.set_file("/projects/moselle-project/tests/fileio/TestFile.ini");
    QString head_val = ini.get_val("HEAD");
    ini.create_new_val("CONTENT", "nothing");
    if (ini.write_val("HEAD", "test2")) {
        editor->setPlainText("old value: " + head_val + "\n\n\nnew value: " + ini.get_val("HEAD") + "\n\n\nthe new value: " + ini.get_val("CONTENT"));
    }
    window.show();
    return app.exec();
}
