#ifndef MODELLIST_H
#define MODELLIST_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include <Site.h>
#include <BaseItem.h>

class BaseItem;
class PageItem;
class PostItem;
class AbstractPostItem;

class ModelList : public QAbstractItemModel
{
    Q_OBJECT

public:
    ModelList(BaseItem *rootItem, Site* site, QObject *parent = nullptr);
    ~ModelList() override;

    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    bool setHeaderData(int section, Qt::Orientation orientation,
                       const QVariant &value, int role = Qt::EditRole) override;

    void newPage();

    void startUpdate(PageItem* pageItem, int curRow);
    void endUpdate();


private:
    BaseItem *getItem(const QModelIndex &index) const;

    BaseItem *rootItem;
    Site* site;
    bool emty = false;
};
//! [2]

#endif // MODELLIST_H
