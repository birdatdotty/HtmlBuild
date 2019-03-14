#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QMenuBar>
#include <QAction>
#include <QDialogButtonBox>
#include <QPushButton>

class HtmlBuild;
class BaseItem;
class Site;

class MainWindow : public QMainWindow
{
  Q_OBJECT
typedef  BaseItem*(*makePost)(Site*,QJsonObject);
public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  HtmlBuild *widget;

  QMenu *menuFile,
        *menuSettings;

  QAction *newPage,
          *modules;

  QDialogButtonBox *buttonBox;
  void addPlugins(QMap<QString,makePost>* genPost,QString file);

private slots:
  void slotNewPage();
  void slotSetPath();
  void message(QString, int = 2000);
};

#endif // MAINWINDOW_H
