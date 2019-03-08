#include "PostPics.h"
#include "PostPicsEdit/PostPicsEdit.h"

//#include "../PageEdit/PageEdit.h"

#include <QPair>
#include <QTime>

PostPics::PostPics(const Site *site, QJsonObject item)
  : AbstractPostItem(site, item),
    stId(item["id"].toString("")),
    stCtx(item["ctx"].toString("")),
    stShortCtx(item["shortCtx"].toString("")),
    stClass(item["class"].toString("")),
    stTitle(item["title"].toString("")),
    img(item["img"].toString(""))
{
  QJsonArray picArr = item["imgs"].toArray();
  for (int i = 0; i < picArr.size(); i++)
    {
      pics.append(picArr[i].toString());
    }

  self = this;
}

int PostPics::columnCount() const
{
  return 0;
}

QVariant PostPics::data(int column) const
{
  switch (column) {
    case 0: return stId;
    case 1:
//      return QVariant::fromValue(this);
//      return this;
//      return QVariant::fromValue(self);
      return QVariant::fromValue(qMakePair(self,1));
//    case 1: return stCtx;
    case 2: return QVariant::fromValue(qMakePair(self,stClass));
    case 3:
      return QVariant::fromValue(qMakePair(self,3));
    default: return QVariant();
  }
}

QVariant PostPics::getShortData(int column) const
{
  switch (column) {
    case 0: return stId;
    case 1:
      return stShortCtx;
    case 2: return stClass;
    case 3:
      return QVariant::fromValue(qMakePair(self,3));
    default: return QVariant();
  }
}


bool PostPics::setData(int column, const QVariant &value)
{
  switch (column) {
    case 0: stId = value.toString(); return true;
    case 1: stCtx = value.toString(); return true;
    case 2: stClass = value.toString(); return true;
    default: return false;
  }
}

QString PostPics::getHtml()
{
  QString tpl_html, html;

  QString tmpCtx = stCtx;
  if (stTitle.size()>0)
    tmpCtx = "<h3>" + stTitle + "</h3>" + stCtx;

  tpl_html = getDiv(stClass);
  if (img.size() == 0)
    html = tpl_html.arg(stId, tmpCtx, "");
  else
    html = tpl_html.arg(stId, tmpCtx, "<div><img alt='' src='" + img + "'></div>");
  return html;
}

QString PostPics::getBody() { return stCtx; }
QString PostPics::getShortCtx() const { return stShortCtx; }
QString PostPics::getClass() const { return stClass; }
QString PostPics::getId() const { return stId; }
QString PostPics::getImg() const { return img; }
QString PostPics::getTitle() const { return stTitle; }

void PostPics::setCtx(QString str) {stCtx = str;}
void PostPics::setShortCtx(QString str) {stShortCtx = str;}
void PostPics::setClass(QString str) {stClass = str;}
void PostPics::setId(QString str) {stId = str;}
void PostPics::setImg(QString str) {img = str;}

void PostPics::setTitle(QString title)
{
  stTitle = title;
}

QWidget *PostPics::createEditor(const QModelIndex &, int column)
{
//  qInfo() << "QWidget *PostPics::createEditor(const QModelIndex &, int column)";
//  if (column == 3)
//    {
//      PostPicsEdit *edit = new PostPicsEdit(this, pics);
//      return edit;
//    }


  return new QWidget();
}

QWidget *PostPics::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  int column = index.column();
  if (column == 3)
    {
      const Site* site = dynamic_cast<const Site*>(this);
      PostPicsEdit *edit = new PostPicsEdit(site, pics);
      return edit;
    }

  return new QWidget;

}

void PostPics::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}

QJsonObject PostPics::json()
{
  QJsonObject data;
  QJsonArray imgList;
  foreach (QString file, pics)
    imgList.push_back(file);

//  data["id"] = stId;
//  data["ctx"] = stCtx;
//  data["shortCtx"] = stShortCtx;
//  data["class"] = stClass;
  if (pics.size()>0)
    data["imgs"] = imgList;
  data["type"] = type;
//  data["title"] = stTitle;

  return data;

//  QJsonObject data;
//  data["id"] = stId;
//  data["ctx"] = stCtx;
//  data["shortCtx"] = stShortCtx;
//  data["class"] = stClass;
//  if (img.size()>0)
//    data["img"] = img;
//  data["type"] = type;
//  data["title"] = stTitle;

  //  return data;
}

QJsonObject PostPics::getNewObject()
{
  QJsonObject newObject;
  newObject["type"] = type;
  newObject["id"] = "post" + QString::number(QTime::currentTime().second());

  return newObject;
}

AbstractPostItem *createPostPicsItem(Site *site, QJsonObject item)
{
  if (item.isEmpty())
    {
      item["id"] = "post" + QString::number(QTime::currentTime().second());
    }

  return new PostPics(site, item);
}
