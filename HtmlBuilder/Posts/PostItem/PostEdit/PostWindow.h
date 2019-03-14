#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Widget.h"
#include "PostEditor.h"

#include <Site.h>

#include "../PostItem.h"


class PostWindow : public QMainWindow
{
  Q_OBJECT
public:
  // stCtx, stId, stClass, stListClass
  explicit PostWindow(const Site*site, PostItem* postItem,
                      QStringList stListClass, QWidget *parent = nullptr);
  ~PostWindow();


signals:

public slots:

private:
  Widget *widget;

  QToolBar *tb;
};

#endif // MAINWINDOW_H
