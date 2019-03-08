#include "Item.h"

#include <QStringList>


Item::Item(const QVector<QVariant> &data, Item *parent)
{
    parentItem = parent;
    itemData = data;
}

Item::~Item()
{
    qDeleteAll(childItems);
}

Item *Item::child(int number)
{
    return childItems.value(number);
}

int Item::childCount() const
{
    return childItems.count();
}

int Item::childNumber() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<Item*>(this));

    return 0;
}

int Item::columnCount() const
{
    return itemData.count();
}

QVariant Item::data(int column) const
{
    return itemData.value(column);
}

//bool Item::insertChildren(int position, int count, int columns)
//{
//    if (position < 0 || position > childItems.size())
//        return false;

//    for (int row = 0; row < count; ++row) {
//        QVector<QVariant> data(columns);
//        Item *item = new Item(data, this);
//        childItems.insert(position, item);
//    }

//    return true;
//}

//bool Item::insertColumns(int position, int columns)
//{
//    if (position < 0 || position > itemData.size())
//        return false;

//    for (int column = 0; column < columns; ++column)
//        itemData.insert(position, QVariant());

//    foreach (Item *child, childItems)
//        child->insertColumns(position, columns);

//    return true;
//}

Item *Item::parent()
{
    return parentItem;
}

//bool Item::removeChildren(int position, int count)
//{
//    if (position < 0 || position + count > childItems.size())
//        return false;

//    for (int row = 0; row < count; ++row)
//        delete childItems.takeAt(position);

//    return true;
//}

//bool Item::removeColumns(int position, int columns)
//{
//    if (position < 0 || position + columns > itemData.size())
//        return false;

//    for (int column = 0; column < columns; ++column)
//        itemData.remove(position);

//    foreach (Item *child, childItems)
//        child->removeColumns(position, columns);

//    return true;
//}

bool Item::setData(int column, const QVariant &value)
{
    if (column < 0 || column >= itemData.size())
        return false;

    itemData[column] = value;
    return true;
}

bool Item::appendChild(Item* child) {
  childItems.append(child);
  return true;
}
