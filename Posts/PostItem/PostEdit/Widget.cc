#include "Widget.h"

#include <QFileDialog>


Widget::Widget(const Site*site, PostItem* postItem,
               QStringList stListClass, QWidget *parent)
  : QWidget(parent),
    Site(site)
{
  QString stCtx = postItem->getBody(),
          stId = postItem->getId(),
          stClass = postItem->getClass(),
          stImg = postItem->getImg(),
          stName = postItem->getShortCtx();

  editor = new PostEditor(stCtx);
  imgs = new WidgetImg();
  lName = new QLabel("Имя:");
  lId = new QLabel("Id:");
  lCtx = new QLabel("ctx:");
  lClass = new QLabel("class:");
  lAddImg = new QLabel("картинка:");
  lTitle = new QLabel("Заголовок:");
  eName = new QLineEdit(stName);
  eId = new QLineEdit(stId);
  eTitle = new QLineEdit(postItem->getTitle());
  eClass = new QComboBox();

  eClass->addItems(stListClass);
  eClass->setCurrentText(stClass);

  mainLayout.addLayout(&leftLayout, 1);
  mainLayout.addLayout(&rightLayout);

  leftLayout.addWidget(lTitle);
  leftLayout.addWidget(eTitle);
  leftLayout.addWidget(editor);

  rightLayout.addWidget(lName, 0, 0/*, Qt::AlignTop*/);
  rightLayout.addWidget(eName, 0, 1/*, Qt::AlignTop*/);

  rightLayout.addWidget(lId, 1, 0/*, Qt::AlignTop*/);
  rightLayout.addWidget(eId, 1, 1/*, Qt::AlignTop*/);

  rightLayout.addWidget(lClass, 2, 0/*, Qt::AlignTop*/);
  rightLayout.addWidget(eClass, 2, 1/*, Qt::AlignTop*/);


  QStringList filter;
  filter << "*.jpg";

  if (stImg.size() > 0)
    bAddImg = new AddImg(stImg, this);
  else
    bAddImg = new AddImg(this);

  connect(bAddImg,  &QPushButton::released, [=](){
    SelectImg* selectImg = new SelectImg(this);
    connect(selectImg, &SelectImg::changeImg,
            bAddImg, &AddImg::setImg);

    selectImg->exec();
  });

//clkImg
  rightLayout.addWidget(lAddImg, 3, 0, 1, 2);
  rightLayout.addWidget(bAddImg, 4, 0, 1, 2);


//  connect(addImg, &QPushButton::released, [=](){
//    QString path = QFileDialog::getOpenFileName(this, "OpenFile", QString(), "Images (*.png)");
//    editor->addImg(path);
//  });
  setLayout(&mainLayout);
  connect(bAddImg, &AddImg::clkImg,[=](QString url)
    {
      imgFile = url;
    });

  connect(bAddImg, &AddImg::changeImg, [=](QString src)
    {
      imgFile = src;
    });

  connect(editor, &PostEditor::updateSignal,[=](QString html)
    {
      postItem->setShortCtx(eName->text());
      postItem->setId(eId->text());
      postItem->setClass(eClass->currentText());
      postItem->setCtx(html);
      postItem->setImg(getImg());
      postItem->setTitle(getTitle());

      finish();
    });

}

QToolBar *Widget::getTb()
{
  return editor->getTb();
}

QMenu *Widget::getMenuFormat()
{
  return editor->getMenuFormat();
}

QString Widget::getImg()
{
  return bAddImg->getSrc();
}

QString Widget::getTitle()
{
  return eTitle->text();
}

Widget::~Widget() {
  delete editor;
  delete imgs;
  delete lName;
  delete lId;
  delete lCtx;
  delete lClass;
  delete lAddImg;
  delete eName;
  delete eId;
  delete eClass;
  delete bAddImg;
}
