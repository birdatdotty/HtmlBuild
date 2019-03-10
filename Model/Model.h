#ifndef MODEL_H
#define MODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

class Item;

class Model : public QAbstractItemModel
{
    Q_OBJECT

public:
    Model(Item *rootItem, QObject *parent = nullptr);
    ~Model() override;

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

    QModelIndex getIndex0();

private:
    Item *getItem(const QModelIndex &index) const;

    Item *rootItem;
};
//! [2]

#endif // MODEL_H
