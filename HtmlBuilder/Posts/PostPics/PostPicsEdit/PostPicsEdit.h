#ifndef POSTPICSEDIT_H
#define POSTPICSEDIT_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QList>
#include <QPushButton>

#include <Site.h>
#include "../../PostItem/PostEdit/AddImg/AddImg.h"

class PostPicsEdit : public QWidget,
    public Site
{
  Q_OBJECT
public:
  PostPicsEdit(const Site* site, QStringList pics);
  ~PostPicsEdit();
  QJsonObject json();

private:
  QVBoxLayout mainLayout;
  QGridLayout picsLayout;
  QList<AddImg*> imgs;


  QLabel *label;
  QPushButton *btnAddImg,
              *btnOk;

  QString type = "testPostPics";

private slots:
  void addImg();
  void applyImgs();

signals:
  void updateImgList(QStringList);
};

#endif // POSTPICSEDIT_H
