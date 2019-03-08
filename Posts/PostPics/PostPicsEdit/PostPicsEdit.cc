#include "PostPicsEdit.h"

#include <QFileDialog>

PostPicsEdit::PostPicsEdit(const Site* site, QStringList list)
  : Site(site),
    label(new QLabel("Картинки:")),
    btnAddImg(new QPushButton("Добавить"))
{
  picsLayout.addWidget(label,0,1);
  picsLayout.addWidget(new QWidget(), 0, 5);

  foreach(QString url, list)
    {
      AddImg* addImg = new AddImg(url, site);
      imgs.append(addImg);
      picsLayout.addWidget(addImg);
    }

  mainLayout.addLayout(&picsLayout);
  mainLayout.addWidget(btnAddImg);
  connect(btnAddImg, &QPushButton::released, this, &PostPicsEdit::addImg);

  setLayout(&mainLayout);
}

PostPicsEdit::~PostPicsEdit() {
//  delete label;
}

void PostPicsEdit::addImg()
{
  QString newFile = QFileDialog::getOpenFileName(this,
                                                 tr("Картинки"), dirImg,
                                                 tr("картинки (*.png *.jpeg *.jpg)"));
  newFile = newFile.split(dir)[1];
  AddImg* addImg = new AddImg(newFile, this);
  imgs.append(addImg);
  picsLayout.addWidget(addImg);

}
