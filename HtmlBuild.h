#ifndef HTMLBUILD_H
#define HTMLBUILD_H

#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QPushButton>


#include "Model/ModelList.h"
#include "Model/HeaderItem.h"
#include "Model/PageItem.h"
//#include "Model/PostItem.h"

#include "Delegate/Delegate.h"
#include "Model/Item.h"

#include "Site/Site.h"

class HtmlBuild : public QWidget, public Site
{
  Q_OBJECT

  public:
    HtmlBuild(Site* site, QWidget *parent = nullptr);
    ~HtmlBuild();

  private:
    QGridLayout *mainLayout;
    QTreeView *view;
    QPushButton *ok,
                *test;
//    Db* db;
    Item* item;
    HeaderItem *header;

    Delegate *delegate;
    ModelList* modelList;
    void saveFile(QString file, QString ctx);
    void saveFile(QString path, QString fileName, QString ctx);
    void loadFile();


  signals:
    void close();

  private slots:
    void clkClose();
    void clkAddPage();
};

#endif // HTMLBUILD_H
