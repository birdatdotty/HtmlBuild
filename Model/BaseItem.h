#ifndef BASEITEM_H
#define BASEITEM_H

#include <QObject>
#include <QVariant>
#include <QPushButton>
#include <QModelIndex>

#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include <QStyledItemDelegate>


#include "../Site/Site.h"

class BaseItem : public QObject,
                 public Site
{
  Q_OBJECT
  public:
    explicit BaseItem(const Site*);
    ~BaseItem();

    BaseItem *child(int number);
    int childCount() const;
    BaseItem *parent();
    int childNumber() const;

    bool appendChild(BaseItem* child);


    virtual int columnCount() const  = 0;
    virtual QVariant data(int column) const = 0;
    virtual bool setData(int column, const QVariant &value) = 0;

    virtual QString getHtml() = 0;
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;


    virtual QJsonObject json();
    virtual void paint(QPainter *painter,
                       const QStyleOptionViewItem &option,
                       const QModelIndex &index) const = 0;

  signals:

  public slots:

  protected:
    QList<BaseItem*> childItems;
    BaseItem *parentItem;
    QPushButton *settings;

    void draw(QPainter *painter, const QStyleOptionViewItem &option, QString text) const;
    void drawButton(QPainter *painter, const QStyleOptionViewItem &option, QString text) const;



};

#endif // BASEITEM_H
