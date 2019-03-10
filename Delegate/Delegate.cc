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


  if (column == 3)
    {
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

  if (item.canConvert<BaseItem*>()) {
      BaseItem* baseItem = item.value<BaseItem*>();
      AbstractPostItem* postItem = dynamic_cast<AbstractPostItem*>(baseItem);
      postItem->paint(painter, option, index);
      return;
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
  const QStringList classes = getClasses();

  if (item.canConvert<BaseItem*>()) {
      BaseItem* baseItem = item.value<BaseItem*>();
      return baseItem->createEditor(parent, option, index);
  }

  return QStyledItemDelegate::createEditor(parent, option, index);
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  QVariant item = index.data();
  if (!item.canConvert<BaseItem*>())
    QStyledItemDelegate::setEditorData(editor, index);
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const
{
  QStyledItemDelegate::setModelData(editor, model, index);
}
