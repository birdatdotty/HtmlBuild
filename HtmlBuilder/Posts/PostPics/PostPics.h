#ifndef POSTPICS_H
#define POSTPICS_H

#include <BaseItem.h>

class PostPics : public BaseItem
{
  public:
    PostPics(const Site* site, QJsonObject item);

    int columnCount() const;
    QVariant data(int column) const;
    bool setData(int column, const QVariant &value);

    QString getHtml();

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    virtual void paint(QPainter *painter,
                       const QStyleOptionViewItem &option,
                       const QModelIndex &index) const;


    QJsonObject json();

  private:
    PostPics* self;
    QString stId,
            stClass;
    QStringList pics;
    QString type = "pics";

  private slots:
    void changeImgList(QStringList);
    void chageStClass(const QString& text);
};

BaseItem *createPostPicsItem(Site *site, QJsonObject item);

#endif // POSTITEM_H
