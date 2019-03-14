#include "CheckableList.h"

CheckableList::CheckableList(QWidget* parent)
  : QWidget (parent)
{
  setWindowTitle("Checkable list in Qt");

  createListWidget();
  createOtherWidgets();
  createLayout();
  createConnections();
}

void CheckableList::updateList(QStringList strList)
{
//  QStringList strList;
//  strList << "monitor" << "mouse" << "keyboard" << "hard disk drive"
//          << "graphic card" << "sound card" << "memory" << "motherboard";

  widget->clear();
  widget->addItems(strList);

  QListWidgetItem* item = nullptr;
  for(int i = 0; i < widget->count(); ++i){
      item = widget->item(i);
      item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
      item->setCheckState(Qt::Unchecked);
  }

}


QStringList CheckableList::getList()
{
  QStringList checked;
  QListWidgetItem* item = nullptr;
  for(int i = 0; i < widget->count(); ++i)
    {
      item = widget->item(i);
      if (item->checkState() == Qt::Checked)
        checked.append(item->text());
    }

  return checked;
}

#include <QDebug>
void CheckableList::startChecked(QStringList list)
{
  QListWidgetItem* item = nullptr;
  for(int i = 0; i < widget->count(); ++i)
    {
      item = widget->item(i);
      QString line = item->text();
      qInfo() << list.indexOf(line) << line;

      if (list.indexOf(line) >= 0)
        item->setCheckState(Qt::Checked);
    }
}

void CheckableList::createListWidget(){
    widget = new QListWidget;
}

void CheckableList::createOtherWidgets(){
    viewBox = new QGroupBox(tr("Найденые библиотеки"));
}

void CheckableList::createLayout(){
    QVBoxLayout* viewLayout = new QVBoxLayout;
    viewLayout->addWidget(widget);
    viewBox->setLayout(viewLayout);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(viewBox);

    setLayout(mainLayout);
}

void CheckableList::createConnections(){
  connect(widget, &QListWidget::itemChanged, this, &CheckableList::highlightChecked);
}

void CheckableList::highlightChecked(QListWidgetItem *item){
    if(item->checkState() == Qt::Checked)
        item->setBackgroundColor(QColor("#ffffb2"));
    else
        item->setBackgroundColor(QColor("#ffffff"));
}
