#ifndef BASEITEM_H
#define BASEITEM_H

#include <QObject>

class BaseItem : public QObject
{
  Q_OBJECT
public:
  explicit BaseItem(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BASEITEM_H