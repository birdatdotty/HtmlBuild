#ifndef POSTPICS_H
#define POSTPICS_H

#include "../../Model/AbstractPostItem.h"

class PostPics : public AbstractPostItem
{
  public:
//    PostItem(const Site* site, QString stId, QString stCtx, QString stShortCtx, QString stClass, QString title, QString img = "");
    PostPics(const Site* site, QJsonObject item);

    int columnCount() const;
    QVariant data(int column) const;
    QVariant getShortData(int column) const;
    bool setData(int column, const QVariant &value);

    QString getHtml();
    QString getBody();
    QString getShortCtx() const;
    QString getClass() const;
    QString getId() const;
    QString getImg() const;
    QString getTitle() const;

    void setCtx(QString);
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
    PostPics* self;
    QString stId,
            stCtx,
            stShortCtx,
            stClass,
            stTitle,
            img;
    QStringList pics;
    QString type = "pics";

  private slots:
    void changeImgList(QStringList);
    void chageStClass(const QString& text);
};

AbstractPostItem *createPostPicsItem(Site *site, QJsonObject item);

#endif // POSTITEM_H
