#ifndef POSTITEM_H
#define POSTITEM_H

#include "../../Model/AbstractPostItem.h"

class PostItem : public AbstractPostItem
{
  public:
    PostItem(const Site* site, QJsonObject item);

    int columnCount() const;
    QVariant data(int column) const;
    bool setData(int column, const QVariant &value);

    QString getHtml();
    QString getBody();
    QString getShortCtx() const;
    QString getClass() const;
    QString getId() const;
    QString getImg() const;
    QString getTitle() const;

    void setCtx(QString);
    void setShortCtx(QString);
    void setClass(QString);
    void setId(QString);
    void setImg(QString);
    void setTitle(QString);

    QWidget* createEditor (const QModelIndex &, int column);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    virtual void paint(QPainter *painter,
                       const QStyleOptionViewItem &option,
                       const QModelIndex &index) const;


    QJsonObject json();

  private:
    PostItem* self;
    QString stId,
            stCtx,
            stShortCtx,
            stClass,
            stTitle,
            img;
    QString type = "default";

  private slots:
    void chageStClass(const QString &text);
};

AbstractPostItem* createPostItem(Site* site,QJsonObject item = QJsonObject());

#endif // POSTITEM_H
