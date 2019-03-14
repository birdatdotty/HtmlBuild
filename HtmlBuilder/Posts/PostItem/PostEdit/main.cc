//#include "widget.h"
#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w("aaa bbb ccc", "aaa...", "ID", "CLASS2", QStringList() << "CLASS1" << "CLASS2" << "CLASS3"<< "CLASS4");
  w.show();

  return a.exec();
}
