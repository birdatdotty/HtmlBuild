#ifndef ABSTRACTPOSTITEM_H
#define ABSTRACTPOSTITEM_H

#include "BaseItem.h"
#include "../Site/Site.h"

#include <QStyledItemDelegate>

class AbstractPostItem : public BaseItem,
                         public Site
{
public:
  AbstractPostItem(const Site* site, QJsonObject item);
  virtual void paint(QPainter *painter,
                     const QStyleOptionViewItem &option,
                     const QModelIndex &index) const = 0;

  virtual QJsonObject getNewObject() = 0;
};

#endif // ABSTRACTPOSTITEM_H
