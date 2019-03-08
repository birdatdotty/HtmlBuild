#include "WidgetImg.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTableWidget>
#include <QTableWidgetItem>

WidgetImg::WidgetImg(QWidget *parent)
  : QWidget(parent),
    img(new QPushButton("Картинка"))
{
  mainLayout.setAlignment(Qt::AlignTop);
  img->setFixedSize(200,200);
  mainLayout.addWidget(img);

  setLayout(&mainLayout);
}

WidgetImg::~WidgetImg()
{
  delete img;
}
