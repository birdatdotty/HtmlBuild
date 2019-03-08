#ifndef HEADERITEM_H
#define HEADERITEM_H

#include "BaseItem.h"

class HeaderItem : public BaseItem
{
  public:
    HeaderItem(QStringList data);

    int columnCount() const;
    QVariant data(int column) const;
    bool setData(int column, const QVariant &value);

    QString getHtml();
    QWidget* createEditor (const QModelIndex &,int);

  private:
    QStringList list;
};

#endif // HEADERITEM_H
