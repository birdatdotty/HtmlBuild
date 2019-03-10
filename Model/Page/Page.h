#ifndef PAGE_H
#define PAGE_H

#include <QObject>
#include <QList>

class Db;
class Item;
class Post;

class Page
{
public:
  Page(Db* db, QString page, QString pageDescription, QString pageName, Item* parent);
//  Item* getItem(Item* parent);

private:
  Db* db;
  QString page, pageDescription, pageName;
  QList<Post*> *pages;

//  Item* parent;
};

#endif // PAGE_H
