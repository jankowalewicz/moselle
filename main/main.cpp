// boilerplate code

#include "fileio/ini.h"
#include "profilemanager/profile.h"
#include "profilemanager/profile_creator.h"
#include "ui/homescreen.h"

#include <QApplication>
#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QPlainTextEdit>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    homescreen *window = new homescreen();
    QPlainTextEdit *editor = new QPlainTextEdit();
    window->setCentralWidget(editor);
    
    ini_class ini;
    ini.set_file("/projects/moselle-project/tests/fileio/TestFile.ini");
    QString head_val = ini.get_val("HEAD");
    //ini.create_new_val("CONTENT", "nothing");
    if (ini.write_val("HEAD", "test2")) {
        editor->insertPlainText("old value: " + head_val + "\nnew value: " + ini.get_val("HEAD") + "\nthe new value: " + ini.get_val("CONTENT"));
    }
    
    profile *default_profile = new profile("/projects/moselle-project/tests/profiles/default-profile.prof");
    editor->insertPlainText("\n\n\nProfile name: " + default_profile->get_profile_username() + "\nProfile fav playlists: \n");
    default_profile->add_to_fav_playlists("/home/moselle/library/TestPlaylist3.playlist");
    QStringList my_playlists = default_profile->get_profile_fav_playlists();
    for (int i=0; i < my_playlists.length(); i++) {
        editor->insertPlainText(my_playlists.at(i) + "\n");
    }
    
    profile_creator *new_profile = new profile_creator("Jan", "white", "none");
    new_profile->write_to_file("/projects/moselle-project/tests/profiles/creation.profile"); // should be done once because of file exist check
    
    profile *created_profile = new profile("/projects/moselle-project/tests/profiles/creation.profile");
    editor->insertPlainText("\n\n\nName of created profile: " + created_profile->get_profile_username() + "\n");
    
    window->show();
    return app.exec();
}
