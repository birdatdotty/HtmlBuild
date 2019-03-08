#ifndef WIDGETIMG_H
#define WIDGETIMG_H

#include <QWidget>
#include <QVBoxLayout>
//#include <IconPreviewArea
#include <QLabel>

#include <QIcon>
#include <QStringList>
#include <QVector>

#include <QPushButton>

class WidgetImg : public QWidget
{
  Q_OBJECT
public:
  explicit WidgetImg(QWidget *parent = nullptr);
  ~WidgetImg();

signals:

public slots:

private:
  QVBoxLayout mainLayout;
  QPushButton *img;

  QIcon icon;
};

#endif // WIDGETIMG_H
