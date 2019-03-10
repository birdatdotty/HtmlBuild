#include "PostItem.h"
#include "../PostEdit/PostWindow.h"
#include "../Site/Site.h"

#include "../PageEdit/PageEdit.h"

#include <QPair>

PostItem::PostItem(const Site *site, QJsonObject item)
  : AbstractPostItem(site, item),
    stId(item["id"].toString("")),
    stCtx(item["ctx"].toString("")),
    stShortCtx(item["shortCtx"].toString("")),
    stClass(item["class"].toString("")),
    stTitle(item["title"].toString("")),
    img(item["img"].toString(""))
{
  self = this;
}

int PostItem::columnCount() const
{
  return 0;
}

QVariant PostItem::data(int column) const
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

QVariant PostItem::getShortData(int column) const
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


bool PostItem::setData(int column, const QVariant &value)
{
  switch (column) {
    case 0: stId = value.toString(); return true;
    case 1: stCtx = value.toString(); return true;
    case 2: stClass = value.toString(); return true;
    default: return false;
  }
}

QString PostItem::getHtml()
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

QString PostItem::getBody()
{
  return stCtx;
}

QString PostItem::getShortCtx() const
{
  return stShortCtx;
}
QString PostItem::getClass() const
{
  return stClass;
}
QString PostItem::getId() const
{
  return stId;
}

QString PostItem::getImg() const
{
  return img;
}

QString PostItem::getTitle() const
{
  return stTitle;
}

void PostItem::setCtx(QString str) {stCtx = str;}
void PostItem::setShortCtx(QString str) {stShortCtx = str;}
void PostItem::setClass(QString str) {stClass = str;}
void PostItem::setId(QString str) {stId = str;}
void PostItem::setImg(QString str) {img = str;}

void PostItem::setTitle(QString title)
{
  stTitle = title;
}

#include <QDebug>
QWidget *PostItem::createEditor(const QModelIndex &, int column)
{
  qInfo() << "QWidget *PostItem::createEditor(const QModelIndex &, int column)";
  if (column == 3)
    {
      const QStringList classes = getClasses();

      PostWindow *postWindow = new PostWindow(self, self, classes);
      return postWindow;
    }


  return new QWidget();
}

QWidget *PostItem::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  int column = index.column();
  if (column == 3)
    {
      const QStringList classes = getClasses();

      PostWindow *postWindow = new PostWindow(self, self, classes);
      return postWindow;
    }

  return new QWidget;

}

void PostItem::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}

QJsonObject PostItem::json()
{
  QJsonObject data;
  data["id"] = stId;
  data["ctx"] = stCtx;
  data["shortCtx"] = stShortCtx;
  data["class"] = stClass;
  if (img.size()>0)
    data["img"] = img;
  data["type"] = type;
  data["title"] = stTitle;

  return data;
}

