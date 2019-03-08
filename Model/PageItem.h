#ifndef PAGEITEM_H
#define PAGEITEM_H

#include "BaseItem.h"
#include "../Site/Site.h"

#include <QStyledItemDelegate>

class PageItem : public BaseItem,
                 public Site
{
  public:
    PageItem(Site*site, QJsonObject item);


    int columnCount() const;
    QVariant data(int column) const;
    bool setData(int column, const QVariant &value);

    QString getHtml();
    QString getPage();
    QPair<QString,QString> getCtx(); // pageTpl, postList
    QString getName();
    QString getTitle();

    void setPage(QString);
    void setName(QString);
    void setTitle(QString);

    void addNewChild();
    QWidget* createEditor (const QModelIndex &index, int column);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    virtual void paint(QPainter *painter,
                       const QStyleOptionViewItem &option,
                       const QModelIndex &index) const;

    QJsonObject json();

  private:
    PageItem* self;
    QString stPage,
            stName,
            stTitle;
};

#endif // PAGEITEM_H
