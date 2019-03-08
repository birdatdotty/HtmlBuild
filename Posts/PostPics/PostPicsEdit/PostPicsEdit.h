#ifndef POSTPICSEDIT_H
#define POSTPICSEDIT_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QList>
#include <QPushButton>

#include "../../../Site/Site.h"
#include "../../PostItem/PostEdit/AddImg/AddImg.h"

class PostPicsEdit : public QWidget,
    public Site
{
public:
  PostPicsEdit(const Site* site, QStringList pics);
  ~PostPicsEdit();
  QJsonObject json();

private:
  QVBoxLayout mainLayout;
  QGridLayout picsLayout;
  QList<AddImg*> imgs;


  QLabel *label;
  QPushButton *btnAddImg;

private slots:
  void addImg();
  QString type = "testPostPics";
};

#endif // POSTPICSEDIT_H
