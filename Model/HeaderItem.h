#ifndef HEADERITEM_H
#define HEADERITEM_H

#include "BaseItem.h"

class HeaderItem : public BaseItem
{
  public:
    HeaderItem(QStringList data, const Site* site);

    int columnCount() const;
    QVariant data(int column) const;
    bool setData(int column, const QVariant &value);

    QString getHtml();

    virtual void paint(QPainter *painter,
                       const QStyleOptionViewItem &option,
                       const QModelIndex &index) const;
  private:
    QStringList list;
};

#endif // HEADERITEM_H
