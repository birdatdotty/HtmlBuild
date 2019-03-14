#include "InputPath.h"

#include <QFileDialog>
#include <QFile>
#include <QDir>


InputPath::InputPath()
  : settings("dotty.su", "HtmlBuild")
{
  mainLayout = new QVBoxLayout;
  inputLayout = new QHBoxLayout;

  label = new QLabel("Введите путь:");
  settings.beginGroup("default");
  QString dir = settings.value("dirLibs").toString();
  QString libsString = settings.value("libs").toString();
  edit = new QLineEdit(dir);
  buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  openPath = new QPushButton("...");

  checkableList = new CheckableList();


  connect(openPath, &QPushButton::released, this, &InputPath::slotOpenPath);
  connect(edit, &QLineEdit::textChanged, this, &InputPath::changePath);
  connect(buttons->button(QDialogButtonBox::Ok), &QPushButton::released, this, &InputPath::slotOk);
  connect(buttons->button(QDialogButtonBox::Cancel), &QPushButton::released, this, &QDialog::close);

  changePath(dir);
  checkableList->startChecked(libsString.split(" "));

  inputLayout->addWidget(label);
  inputLayout->addWidget(edit, 1);
  inputLayout->addWidget(openPath);

  mainLayout->addLayout(inputLayout, 1);
  mainLayout->addWidget(checkableList);
  mainLayout->addWidget(buttons);

  setLayout(mainLayout);
}

void InputPath::slotOpenPath()
{
  QString path = QFileDialog::getExistingDirectory(this,
                                              tr("Выбрать путь"), "/",
                                                   QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
  if (path.size() == 0)
    return;

  edit->setText(path);
}

void InputPath::changePath(const QString& path)
{
  QDir dir(path);
  if (dir.exists())
    {
      QStringList libs = dir.entryList(QStringList() << "*.so" << "*.dll", QDir::Files);
      checkableList->updateList(libs);
    }
  else
    checkableList->updateList(QStringList());
}

void InputPath::slotOk()
{
  QString dir = edit->text();
  QString libs = checkableList->getList().join(" ");

  settings.setValue("dirLibs", dir);
  settings.setValue("libs", libs);
  settings.sync();

  QMessageBox msgBox;
  msgBox.setText("Перезапустите программу!");
  msgBox.exec();

  close();
}
