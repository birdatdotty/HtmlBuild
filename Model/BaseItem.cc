#include "BaseItem.h"

#include <QPainter>
//#include "PostItem.h"

BaseItem::BaseItem()
{
  settings = new QPushButton();
}

BaseItem::~BaseItem()
{
  delete settings;
}

BaseItem *BaseItem::child(int number)
{
    return childItems.value(number);
}

int BaseItem::childCount() const
{
    return childItems.count();
}

int BaseItem::childNumber() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<BaseItem*>(this));

    return 0;
}

BaseItem *BaseItem::parent()
{
    return parentItem;
}

bool BaseItem::appendChild(BaseItem* child) {
  childItems.append(child);
  child->parentItem = this;
  return true;
}

QWidget *BaseItem::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  return new QWidget();
}

QJsonObject BaseItem::json()
{
  return QJsonObject();
}

#include <QDebug>
#include <QTime>
void BaseItem::draw(QPainter *painter, const QStyleOptionViewItem &option, QString text) const
{
  painter->save();
  bool sel = option.state & QStyle::State_Selected;
  if (sel)
    painter->fillRect(option.rect, option.palette.highlight());

//  int s = QTime::msec();;
  qInfo() << __LINE__ << text << option.rect;
//  painter->setPen(Qt::darkGray);
  if (!sel) {
      QPen pen(Qt::green);
//      pen.setWidth(2);
//      painter->setPen(pen);
  }
  painter->drawText(option.rect, text);

  painter->restore();

}
