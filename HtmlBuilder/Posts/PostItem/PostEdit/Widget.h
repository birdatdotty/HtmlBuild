#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

#include "PostEditor.h"
#include "WidgetImg.h"

#include "AddImg/AddImg.h"
#include "AddImg/SelectImg.h"
#include <Site.h>


#include "../PostItem.h"

class Widget : public QWidget,
               public Site
{
  Q_OBJECT
public:
  explicit Widget(const Site*site, PostItem* postItem,
                  QStringList stListClass, QWidget *parent = nullptr);
  ~Widget();
  QToolBar *getTb();
  QMenu *getMenuFormat();
  QString getImg();
  QString getTitle();

signals:
  void finish();

public slots:
private:
  QHBoxLayout mainLayout;
  QVBoxLayout leftLayout;
  QGridLayout rightLayout;

  PostEditor* editor;
  WidgetImg* imgs;
  AddImg* bAddImg;
  QString imgFile;

  QLabel *lName, *lId, *lCtx, *lClass, *lAddImg, *lTitle;
  QLineEdit *eName, *eId, *eTitle;
  QComboBox *eClass;
};

#endif // WIDGET_H
