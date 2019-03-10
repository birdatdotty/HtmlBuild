//#include "PageItem.h"
//#include "PostItem.h"

#include "../PageEdit/PageEdit.h"

#include <QComboBox>
#include <QPainter>


PageItem::PageItem(Site *site, QJsonObject item)
  : Site(site),
    stPage(item["page"].toString()),
    stName(item["name"].toString()),
    stTitle(item["title"].toString())
{
  self = this;
}

int PageItem::columnCount() const
{
  return 0;
}

QVariant PageItem::data(int column) const
{
  switch (column) {
    case 0: return stPage;
    case 1: return stName;
    case 2: return stTitle;
    case 3:
      return QVariant::fromValue(self);//QVariant::fromValue(qMakePair(self,3));
    default: return QVariant();
  }
}

bool PageItem::setData(int column, const QVariant &value)
{
  switch (column) {
    case 0: stPage = value.toString(); return true;
    case 1: stName = value.toString(); return true;
    case 2: stTitle = value.toString(); return true;
    default: return false;
  }
}

QString PageItem::getHtml()
{
  QString html, body;

  foreach(BaseItem* item, childItems)
    body += item->getHtml();

  QString tplHtml = getTplHtml();


  html = tplHtml.arg(stTitle,"%1","%2",body,"%3");

  return html;
}

QPair<QString,QString> PageItem::getCtx()
{
  QString html;
  QString body;

  foreach(BaseItem* item, childItems)
    body += item->getHtml();

  QString tplHtml0 = getTplHtml();
  QString tplHtml = tplHtml0.arg(stTitle, "%1", "%2", "%3", "%4");


  return qMakePair(tplHtml,body);
}

QString PageItem::getPage()
{ return stPage; }

QString PageItem::getName()
{ return stName; }

QString PageItem::getTitle()
{ return stTitle; }

void PageItem::setPage(QString a)
{ stPage = a; }

void PageItem::setName(QString a)
{ stName = a; }

void PageItem::setTitle(QString a)
{ stTitle = a; }

void PageItem::addNewChild()
{
}


QWidget *PageItem::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  int column = index.column();
  if (column == 3)
    {
      PageItem *self = const_cast<PageItem*>(this);
      const Site* site = dynamic_cast<const Site*>(this);
      PageEdit *pageEdit = new PageEdit(site, index, self);
      return pageEdit;
    }

  return new QWidget(parent);
}

void PageItem::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

  int column = index.column();
  if (column == 2)
    {
      painter->drawText(option.rect, "stTitle");
      return;
    }
//  if (column == 3)
//    drawButton(painter, option, "Настройки");


}

QJsonObject PageItem::json()
{
  QJsonObject data;

  data["page"] = stPage;
  data["name"] = stName;
  data["title"] = stTitle;
  QJsonArray posts;

  foreach(BaseItem* item, childItems)
    posts += item->json();

  data["posts"] = posts;


  return data;
}
