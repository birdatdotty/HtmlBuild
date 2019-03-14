#include "AddImg.h"

#include <QRect>

AddImg::AddImg(QString fileName, const Site* site)
  : Site(site)
{
  if (fileName.size() > 0)
    {
      QString img = fileName;
      file = img;
      url = img;
      setImg(fileName);
    }
}

AddImg::AddImg(QPixmap *qPixmap, const Site *site)
  : Site(site)
{
  QIcon icon(*qPixmap);
  setIcon(icon);
  setIconSize(QSize(500,500));
}


AddImg::AddImg(const Site* site)
  : Site(site)
{}

AddImg::AddImg(AddImg*parent)
  : Site(parent),
    url(parent->url)
{}

void AddImg::setDir(QString newDir)
{
  dir = newDir;
}

QString AddImg::getSrc()
{
  return url;
}

void AddImg::setImg(QString fileName)
{
  file = fileName;
  url = fileName;
  setText("");
  QPixmap pixmap(dir + fileName);
  QIcon icon(pixmap);
  setIcon(icon);
  setIconSize(QSize(500,500));

  connect(this, &QPushButton::released, this, &AddImg::slotImg);
}

void AddImg::slotImg()
{
  clkImg(file);
  changeImg(file);
}
