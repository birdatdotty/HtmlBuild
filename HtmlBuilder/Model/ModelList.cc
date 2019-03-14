#include <QtWidgets>

#include "PageItem.h"
#include "ModelList.h"

//! [0]
ModelList::ModelList(BaseItem *rootItem1, Site* site, QObject *parent)
    : QAbstractItemModel(parent),
      site(site)
{
  rootItem = rootItem1;

}
//! [0]

//! [1]
ModelList::~ModelList()
{
    delete rootItem;
}
//! [1]

//! [2]
int ModelList::columnCount(const QModelIndex & /* parent */) const
{
    return rootItem->columnCount();
}
//! [2]

QVariant ModelList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole && role != Qt::UserRole)
        return QVariant();

    BaseItem *item = getItem(index);

    if (role == Qt::UserRole)
      return QVariant::fromValue(item);

    return item->data(index.column());
}

//! [3]
Qt::ItemFlags ModelList::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

BaseItem *ModelList::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        BaseItem *item = static_cast<BaseItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return rootItem;
}

QVariant ModelList::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex ModelList::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    BaseItem *parentItem = getItem(parent);

    BaseItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex ModelList::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    BaseItem *childItem = getItem(index);
    BaseItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}

int ModelList::rowCount(const QModelIndex &parent) const
{
    BaseItem *parentItem = getItem(parent);

    return parentItem->childCount();
}

bool ModelList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    BaseItem *item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index);

    return result;
}

bool ModelList::setHeaderData(int section, Qt::Orientation orientation,
                              const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal)
        return false;

    bool result = rootItem->setData(section, value);

    if (result)
        emit headerDataChanged(orientation, section, section);

    return result;
}

void ModelList::newPage()
{
  int len = rootItem->childCount();
  QJsonObject jsonPage;
  jsonPage["page"] = "page.html";
  jsonPage["name"] = "page.html";
  jsonPage["title"] = "Title";

  PageItem *pageItem = new PageItem(site, jsonPage);

  beginInsertRows(QModelIndex(), len, len + 1);
  rootItem->appendChild(pageItem);
  endInsertRows();

}

void ModelList::startUpdate(PageItem* pageItem, int curRow)
{
  int len = pageItem->childCount();

  if (len == 0)
    emty = true;

  if (emty)
    beginResetModel();

  else
    beginInsertRows(index(curRow,0), len, len + 1);
}

void ModelList::endUpdate()
{
  if (emty)
    {
      emty = false;
      endResetModel();
    }
  else
    endInsertRows();
}
