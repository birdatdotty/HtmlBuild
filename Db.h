#ifndef DB_H
#define DB_H

#include <QString>
#include <QList>

#include "Model/Item.h"

struct StPage {
  QString  page,
                  description,
                  name;
  int id;
};


class Db
{
  public:
    Db();
    int count(QString page);
    QString getName(int);
    QString getPost(int post, QString page);
    QVector<QVariant> getHeaders();
    QList<StPage> getPageInfoList();
};

#endif // DB_H
