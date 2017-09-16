#include <QApplication>
#include <vigener.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window *main = new Window(0);
    main->show();


    return a.exec();
}
