#include "Delegate.h"
#include <QPainter>
#include <QApplication>
#include <QComboBox>


#include "../Model/PageItem.h"
#include "../PageEdit/PageEdit.h"


Delegate::Delegate(Site* site, QWidget *parent)
  : QStyledItemDelegate(parent),
    Site(site)
{

}

void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{
  QVariant item = index.data();

  if (item.canConvert<BaseItem*>()) {
    BaseItem* baseItem = item.value<BaseItem*>();
    if (baseItem)
      baseItem->paint(painter, option, index);

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
