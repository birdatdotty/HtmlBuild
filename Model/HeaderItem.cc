#include "HeaderItem.h"

HeaderItem::HeaderItem(QStringList data, const Site* site)
  : BaseItem(site),
    list(data)
{}

int HeaderItem::columnCount() const
{
  return list.size();
}
QVariant HeaderItem::data(int column) const
{
  return list.at(column);
}
bool HeaderItem::setData(int column, const QVariant &value)
{
  list[column] = value.toString();

  return true;
}

QString HeaderItem::getHtml() {
  return "";
}

void HeaderItem::paint(QPainter */*painter*/, const QStyleOptionViewItem &/*option*/, const QModelIndex &/*index*/) const
{

}

