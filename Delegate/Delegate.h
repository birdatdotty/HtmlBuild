#ifndef DELEGATE_H
#define DELEGATE_H

#include <QStyledItemDelegate>

#include <QPushButton>

#include "../Site/Site.h"

class Delegate : public QStyledItemDelegate,
                 public Site
{
public:
  Delegate(Site*site, QWidget *parent = nullptr);

  void paint(QPainter *painter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const override;
  QSize sizeHint(const QStyleOptionViewItem &option,
                 const QModelIndex &index) const override;
  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const override;
  void setEditorData(QWidget *editor, const QModelIndex &index) const override;
  void setModelData(QWidget *editor, QAbstractItemModel *model,
                    const QModelIndex &index) const override;

  private:

};

#endif // DELEGATE_H
