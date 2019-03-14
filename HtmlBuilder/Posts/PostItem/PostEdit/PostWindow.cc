#include "PostWindow.h"

#include <QMenuBar>
#include <QApplication>
#include "PostEditor.h"


PostWindow::PostWindow(const Site*site, PostItem* postItem,
                       QStringList stListClass, QWidget *parent)
  : QMainWindow(parent)
{

  widget = new Widget(site, postItem, stListClass);
    tb = widget->getTb();
    addToolBar(Qt::LeftToolBarArea,tb);

  //format
    QMenu *menuFormat = widget->getMenuFormat();
    menuBar()->addMenu(menuFormat);

  //help
    QMenu *helpMenu = menuBar()->addMenu(tr("Help"));
  //  helpMenu->addAction(tr("About"), this, &TextEdit::about);
    helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);


    setCentralWidget(widget);
    resize(1280,720);
    connect(widget, &Widget::finish, [=](){close();});
}

PostWindow::~PostWindow() {
  delete widget;
}
