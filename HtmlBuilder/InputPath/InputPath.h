#ifndef INPUTPATH_H
#define INPUTPATH_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSettings>

#include "CheckableList/CheckableList.h"

class InputPath : public QDialog
{
public:
  InputPath();

private:
  QLabel *label;
  QLineEdit *edit;
  QDialogButtonBox *buttons;
  QPushButton *openPath;
  QSettings settings;

CheckableList *checkableList;

  QVBoxLayout *mainLayout;
  QHBoxLayout *inputLayout;

private slots:
  void slotOpenPath();
  void changePath(const QString&);
  void slotOk();
};

#endif // INPUTPATH_H
