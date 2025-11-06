#include <QApplication>
#include <QWidget>
#include "widgets.hpp"
#include <QFile>
#include <QScreen>
#include <QIcon>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Calculator");

    window.setWindowIcon(QIcon("calculator.png"));

    QFile styleFile("style.css");
    styleFile.open(QFile::ReadOnly);
    QString style = styleFile.readAll();
    qApp->setStyleSheet(style);

    Qt_widgets(window);

    window.setFixedSize(QSize(350, 350));

    window.show();
    return app.exec();

}