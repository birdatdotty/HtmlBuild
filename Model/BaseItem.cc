#include "BaseItem.h"

#include <QApplication>
#include <QPainter>
#include <QApplication>

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

void BaseItem::draw(QPainter *painter, const QStyleOptionViewItem &option, QString text) const
{
  bool sel = option.state & QStyle::State_Selected;

  painter->save();
  if (sel)
    {
      painter->fillRect(option.rect, option.palette.highlight());
      painter->setPen(Qt::white);
      painter->drawText(option.rect, text);
    }
  else
      painter->drawText(option.rect, text);

  painter->restore();

}

void BaseItem::drawButton(QPainter *painter, const QStyleOptionViewItem &option, QString text) const
{
  QStyleOptionButton button;

  QRect r = option.rect;
  int x,y,w,h;
  w = r.width() - 2;
  h = r.height() - 2;
  x = r.left() + 1;
  y = r.top() - 1;

  button.rect = QRect(x,y,w,h);
  button.text = text;
  button.state = QStyle::State_Enabled;

  QApplication::style()->drawControl( QStyle::CE_PushButton, &button, painter);
}
