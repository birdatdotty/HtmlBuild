#include "Db.h"

Db::Db()
{

}

int Db::count(QString page)
{
  if (page == "index.html")
    return 2;
  if (page == "about.html")
    return 21;
  else
    return 3;
}

QString Db::getName(int i)
{
  switch (i) {
    case 0:
      return "post 1";
    case 1:
      return "post 2";
    default:
      return "new post";
  }
}

QString Db::getPost(int post, QString page) {
  if (page == "index.html")
    switch (post) {
      case 0:
        return "dasdsakdjkjkj";
      case 1:
        return "1111111111";
      default:
        return "default";
      }
  else {
      switch (post) {
        case 0:
          return "999999999";
        case 1:
          return "8888888";
        default:
          return "777777";
        }
    }
}

QVector<QVariant> Db::getHeaders()
{
  QVector<QVariant> list;
  list << "Страница" << "Название" << "Описание" << "config.html" << "map.html";

  return list;
}

QList<StPage> Db::getPageInfoList()
{
  StPage stPage0 = {"index.html", "Main Page", "Главная", 0};
  StPage stPage1 = {"about.html", "Description", "Обо мне", 12};
  StPage stPage3 = {"about2.html", "Description", "Обо мне", 12};

  QList<StPage> list;
  list << stPage0 << stPage1 << stPage3;
  return list;
}
