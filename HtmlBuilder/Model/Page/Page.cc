#include "../Item.h"
#include "Page.h"
#include "Post.h"

#include <QVector>

Page::Page(Db* db, QString page, QString pageDescription, QString pageName, Item* parent)
  : page(page),
    pageDescription(pageDescription),
    pageName(pageName),
    pages(new QList<Post*>)

{
  QVector<QVariant> iList;
  iList << page << pageDescription << pageName;
  Item* page22 = new Item(iList, parent);
  parent->appendChild(page22);


    QVector<QVariant> listPost;
    listPost << "" << "Страница" << "Название";
    Item* post133 = new Item(listPost, page22);
    Item* post233 = new Item(listPost, page22);
    page22->appendChild(post133);
    page22->appendChild(post233);

}
