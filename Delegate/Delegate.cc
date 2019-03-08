#include "Delegate.h"
#include <QPainter>
#include <QApplication>
#include <QComboBox>


#include "../Model/PageItem.h"
#include "../PageEdit/PageEdit.h"
#include "../Model/AbstractPostItem.h"

Delegate::Delegate(Site* site, QWidget *parent)
  : QStyledItemDelegate(parent),
    Site(site)
{

}


void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{
  QVariant item = index.data();
  int column = index.column();

//  bool sel = option.state & QStyle::State_Selected;
//  if (sel)
//    painter->fillRect(option.rect, option.palette.highlight());

//  if ((column == 2) && item.canConvert<QPair<BaseItem*,QString>>())
//    {
//      QPair<AbstractPostItem*,QString> data = qvariant_cast<QPair<AbstractPostItem*,QString>>(item);
////      PostItem* postItem = data.first;
//      QVariant shortString = data.second;
//      painter->drawText(option.rect, shortString.toString());
//      return;
//    }

  if (column == 3)
    {
//      qInfo () << "+++" << item;
      QStyleOptionButton button;
      QRect r = option.rect;//getting the rect of the cell
      int x,y,w,h;
      w = r.width()-2;//160;//button width
      h = r.height()-2;//30;//button height
      x = r.left() + 1;// + r.width() - w;//the X coordinate
      y = r.top() - 1;//the Y coordinate
      button.rect = QRect(x,y,w,h);
      button.text = "Настройки";
      button.state = QStyle::State_Enabled;

      QApplication::style()->drawControl( QStyle::CE_PushButton, &button, painter);
      return;
    }

//  if (item.canConvert<QPair<AbstractPostItem*,int>>()) {
//    QPair<AbstractPostItem*,int> tmp = qvariant_cast<QPair<AbstractPostItem*,int>>(item);
//    AbstractPostItem* baseItem = tmp.first;
//    int itemNum = tmp.second;

//    baseItem->paint(painter, option, index);


////    QPair<AbstractPostItem*,int> data = qvariant_cast<QPair<AbstractPostItem*,int>>(item);
////    AbstractPostItem* postItem = data.first;
////    QVariant shortString = postItem->getShortData(column);
////    painter->drawText(option.rect, shortString.toString());
//    return;
//  }
  if (item.canConvert<BaseItem*>()) {
      BaseItem* baseItem = item.value<BaseItem*>();
      AbstractPostItem* postItem = dynamic_cast<AbstractPostItem*>(baseItem);
      postItem->paint(painter, option, index);

    }

  QStyledItemDelegate::paint(painter, option, index);
}

QSize Delegate::sizeHint(const QStyleOptionViewItem &option,
               const QModelIndex &index) const
{
  return QStyledItemDelegate::sizeHint(option, index);
}

QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                      const QModelIndex &index) const
{
  QVariant item = index.data();
  int column = index.column();
  const QStringList classes = getClasses();


  if (item.canConvert<BaseItem*>()) {
      BaseItem* baseItem = item.value<BaseItem*>();
      AbstractPostItem* postItem = dynamic_cast<AbstractPostItem*>(baseItem);
      QWidget* edit = postItem->createEditor(parent, option, index);
      return edit;
  }


  if ((column == 2) && item.canConvert<QPair<BaseItem*,QString>>())
    {
      QPair<AbstractPostItem*,QString> data = qvariant_cast<QPair<AbstractPostItem*,QString>>(item);
      QComboBox* editor = new QComboBox(parent);

      editor->addItems(classes);
      editor->setCurrentText(data.second);
      return editor;
    }

  if (column == 3)
    {
      BaseItem* item = qvariant_cast<BaseItem*>(index.data(Qt::UserRole));
      return item->createEditor(parent, option, index);
    }
    if (item.canConvert<QPair<BaseItem*,int>>())
      {
        QPair<BaseItem*,int> data = qvariant_cast<QPair<BaseItem*,int>>(item);
        BaseItem* baseItem = data.first;
        QWidget* pageEdit = baseItem->createEditor(parent, option, index);
        return pageEdit;
      }



  return QStyledItemDelegate::createEditor(parent, option, index);
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  QVariant item = index.data();
//  if (!item.canConvert<QPair<BaseItem*,int>>())
  if (!item.canConvert<BaseItem*>())
    QStyledItemDelegate::setEditorData(editor, index);
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const
{
  QStyledItemDelegate::setModelData(editor, model, index);
}
