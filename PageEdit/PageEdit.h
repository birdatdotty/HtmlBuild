#ifndef PAGEEDIT_H
#define PAGEEDIT_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QModelIndex>
#include <QComboBox>

#include "../Model/PageItem.h"

class ModelList;

class PageEdit
  : public QWidget,
    public Site
{
  Q_OBJECT
public:
  explicit PageEdit(const Site *site, const QModelIndex &index, PageItem* pageItem);
  ~PageEdit();

private:
  QGridLayout mainLayout;

  QLabel *lPageIndex,
         *lPageName,
         *lPageTitle;
  QLineEdit *ePageIndex,
            *ePageName,
            *ePageTitle;
  QComboBox *selectPost;
  QPushButton *bAddPost;
  QPushButton *bOk;
  QPushButton *bCancel;
  QDialogButtonBox *buttons;

  PageItem* pageItem;
  ModelList* model;
  const QModelIndex &index;
  const int curRow;
  const Site* site;

private slots:
  void clkAddPost();
  void clkOk();

};

#endif // PAGEEDIT_H
