// https://www.walletfox.com/course/qtcheckablelist.php # variant 1
#ifndef CHECKABLELIST_H
#define CHECKABLELIST_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>


class CheckableList: public QWidget
{
public:
  CheckableList(QWidget* parent = nullptr);
  void updateList(QStringList);
  QStringList getList();
  void startChecked(QStringList);

public slots:
    void highlightChecked(QListWidgetItem* item);

private:
    QListWidget* widget;
    QGroupBox* viewBox;

    void createListWidget();
    void createOtherWidgets();
    void createLayout();
    void createConnections();
};

#endif // CHECKABLELIST_H
