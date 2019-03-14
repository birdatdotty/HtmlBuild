#include "MainWindow.h"

#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>
#include <QLibrary>

#include "InputPath/InputPath.h"
#include "HtmlBuild.h"
#include "Posts/posts.h"

typedef Site*(*createSite)(QString);

#include <QDebug>
void MainWindow::addPlugins(QMap<QString,makePost>* genPost,QString file)
{
  QLibrary lib( file );
  if(lib.load())
    {
      typedef void (*Init)(QMap<QString,makePost>*);
      Init init = (Init) lib.resolve("addPlugin");
      message("Подключен: " + file);
      init(genPost);
    }
  else
      message("Error: " + lib.errorString());
}


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  QSettings settings("dotty.su", "HtmlBuild");
  message("load", 100);
  buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  connect(buttonBox->button(QDialogButtonBox::Ok), &QPushButton::released, [=]() {statusBar()->showMessage("message", 2000);});

  QMap<QString,makePost> genPost;
  genPost.insert("default", createPostItem);
  genPost.insert("pics", createPostPicsItem);

  settings.beginGroup("default");
  QString dirLibs = settings.value("dirLibs").toString();
  QStringList libs = settings.value("libs").toString().split(" ");
  for (int i = 0; i < libs.size(); i++)
    {
      QString lib = dirLibs + "/" + libs[i];
      qInfo() << lib;
      addPlugins(&genPost, lib);
    }

  static QString dir = "/var/www/html";
  Site *site = new Site(dir, genPost);

  widget = new HtmlBuild(site);
  newPage = new QAction("Создать страницу", this);
  modules = new QAction("Выбрать модули", this);

  menuFile = new QMenu("Сайт");
  menuFile->addAction(newPage);

  menuSettings = new QMenu("Настройки");
  menuSettings->addAction(modules);

  menuBar()->addMenu(menuFile);
  menuBar()->addMenu(menuSettings);
  setCentralWidget(widget);


  connect(newPage, &QAction::triggered, this, &MainWindow::slotNewPage);
  connect(modules, &QAction::triggered, this, &MainWindow::slotSetPath);

  connect(widget, &HtmlBuild::close,
          this, &QWidget::close);

  resize(1280,720);
}

MainWindow::~MainWindow()
{
  delete newPage;
  delete menuFile;
  delete menuSettings;
  delete widget;
}

void MainWindow::slotNewPage()
{
  qInfo() << "void MainWindow::slotNewAct()";
  widget->clkAddPage();
}

void MainWindow::slotSetPath()
{
//  bool ok;
//  QString path = QInputDialog::getText(this, tr("Путь к модулям"),
//                                           tr("ВВедите путь:"), QLineEdit::Normal,
//                                           QDir::home().dirName(), &ok);
//  if (ok)
//    {

//      message("новый путь: " + path);
//    }
  InputPath *inputPath = new InputPath();
  inputPath->exec();
}

void MainWindow::message(QString msg, int t)
{
  statusBar()->showMessage(msg, t);
}
