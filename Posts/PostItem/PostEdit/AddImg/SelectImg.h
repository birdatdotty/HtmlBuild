#ifndef SELECTIMG_H
#define SELECTIMG_H

#include <QDialog>
#include <QGridLayout>
#include <QScrollArea>
#include <QList>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "AddImg.h"


class Site;

class SelectImg : public QDialog,
                  public Site
{
  Q_OBJECT
  public:
    SelectImg(const Site*);

  private:
  //  QString dir;
    QVBoxLayout mainLayout;
    QHBoxLayout actionLayout;
    QGridLayout picsLayout, pics;
    QScrollArea picsArea;
    QList<AddImg*> list;
    QPushButton *addPics;
    QList<QWidget*> widgets;


    QStringList filter;

    void deleteWidgets();
    void populate(QStringList filter = QStringList());

  private slots:
    void changeImgSlot(QString);
    void addPic();

  signals:
    void changeImg(QString);

};

#endif // SELECTIMG_H
