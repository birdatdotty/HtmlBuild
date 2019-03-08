#include "SelectImg.h"

#include "../../../../Site/Site.h"

#include <QFileDialog>

SelectImg::SelectImg(const Site *site)
  : Site(site),
    addPics(new QPushButton("добавить"))
{
  setWindowTitle("Выбор изображения");
  QWidget *forMaximumWidth = new QWidget(this);
  pics.addWidget(forMaximumWidth, 0, 2);
  filter << "*.png" << "*.jpg";

  populate(filter);

  picsArea.setLayout(&pics);
  picsLayout.addWidget(&picsArea, 0, 0);

  resize(1280,720);

  actionLayout.addWidget(addPics);
  connect(addPics, &QPushButton::released, this, &SelectImg::addPic);

  mainLayout.addLayout(&picsLayout);
  mainLayout.addLayout(&actionLayout);

  setLayout(&mainLayout);
}

void SelectImg::changeImgSlot(QString img)
{
  changeImg(img);
  close();
}

void SelectImg::addPic()
{
  QString fileName = QFileDialog::getOpenFileName(this,
      tr("Open Image"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));

  QFile::copy(fileName, dir + "img/img" + GetRandomString(fileName));
  deleteWidgets();
  populate(filter);
}

void SelectImg::deleteWidgets()
{
  foreach (QWidget* widget, widgets)
    delete widget;

  widgets.clear();
}

void SelectImg::populate(QStringList filter)
{
  QStringList list = getFiles("img", filter);

  foreach ( QString file, list)
    {
      AddImg* img = new AddImg(file, this);
      widgets.push_back(img);
      pics.addWidget(img);
      connect(img, &AddImg::clkImg, this, &SelectImg::changeImgSlot);
    }
}
