#include <QtWidgets>

#include "Item.h"
#include "Model.h"


Model::Model(Item *rootItem1, QObject *parent)
    : QAbstractItemModel(parent)
{
  rootItem = rootItem1;
}
//! [0]

//! [1]
Model::~Model()
{
    delete rootItem;
}
//! [1]

//! [2]
int Model::columnCount(const QModelIndex & /* parent */) const
{
    return rootItem->columnCount();
}
//! [2]

QVariant Model::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    Item *item = getItem(index);

    return item->data(index.column());
}

//! [3]
Qt::ItemFlags Model::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

Item *Model::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        Item *item = static_cast<Item*>(index.internalPointer());
        if (item)
            return item;
    }
    return rootItem;
}

QVariant Model::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex Model::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    Item *parentItem = getItem(parent);

    Item *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex Model::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    Item *childItem = getItem(index);
    Item *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}

int Model::rowCount(const QModelIndex &parent) const
{
    Item *parentItem = getItem(parent);

    return parentItem->childCount();
}

bool Model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    Item *item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index);

    return result;
}

bool Model::setHeaderData(int section, Qt::Orientation orientation,
                              const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal)
        return false;

    bool result = rootItem->setData(section, value);

    if (result)
        emit headerDataChanged(orientation, section, section);

    return result;
}

QModelIndex Model::getIndex0()
{
    return createIndex(0, 0);
}
