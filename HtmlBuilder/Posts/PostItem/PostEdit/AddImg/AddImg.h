#ifndef ADDIMG_H
#define ADDIMG_H

#include <QPushButton>

#include <Site.h>

class AddImg : public QPushButton,
               public Site
{
  Q_OBJECT
  public:
    AddImg(QString fileName, const Site* site);
    AddImg(QPixmap *qPixmap, const Site* site);
    AddImg(QString txt = "ADD");
    AddImg(const Site* site);
    AddImg(AddImg*);
    void setDir(QString dir);
    QString getSrc();

  signals:
    void clkImg(QString);
    void changeImg(QString);

  private:
    QString url;
    QString file;

  public slots:
    void setImg(QString fileName);

  private slots:
    void slotImg();
};

#endif // ADDIMG_H
