#ifndef POST_H
#define POST_H

#include <QObject>

class Post : public QString
{
  public:
    Post(QString a, int id = 0, QString table = QString());

  private:
    int id;
    QString table;
};

#endif // POST_H
