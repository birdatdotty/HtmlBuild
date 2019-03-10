#include "HtmlBuild.h"
#include "Model/Item.h"
#include "Model/Model.h"
#include "Db.h"
#include "Model/Page/Page.h"

#include "Model/ModelList.h"
#include "Model/HeaderItem.h"
#include "Model/PageItem.h"
#include "Posts/posts.h"

#include <QList>
#include <QPair>

#include <QTextStream>

#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>

#include "config.h"

#include "Posts/PostItem/PostEdit/PostWindow.h"
#include "Posts/PostItem/PostItem.h"
//#include "PostPicsEdit/PostPicsEdit.h"

HtmlBuild::HtmlBuild(Site*site, QWidget *parent)
  : QWidget(parent),
    Site(site),
    mainLayout(new QGridLayout),
    view(new QTreeView()),
    ok(new QPushButton("OK")),
    test(new QPushButton("Создать страницу"))
{
  int row = 0;

  mainLayout->addWidget(view, ++row, 0, 1, 2);
  mainLayout->addWidget(ok, ++row, 0, 1, 2);
  mainLayout->addWidget(test, ++row, 0, 1, 2);

  resize(1280,720);
  setLayout(mainLayout);

  Db* db = new Db();
  QList<StPage> pageList = db->getPageInfoList();


  QVector<QVariant> list = db->getHeaders();
  QStringList strs;
  item = new Item(list);

  for (StPage i: pageList) {
    new Page(db, i.page, i.description, i.name, item);
  }

  // JSON_FILE
  loadFile();
  modelList = new ModelList(header, site);
  view->setModel(modelList);

  // Delegate
  delegate = new Delegate(this);
  view->setItemDelegate(delegate);

  connect(ok, &QPushButton::released, this, &HtmlBuild::clkClose);
  connect(test, &QPushButton::released, this, &HtmlBuild::clkAddPage);
}

HtmlBuild::~HtmlBuild()
{

}

void HtmlBuild::saveFile(QString fileName, QString ctx)
{
  // https://stackoverflow.com/questions/20860691/save-data-to-file-in-qt#answer-20860957
  QFile file(dir + "/" + fileName);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
      return;

  QTextStream out(&file);
  out.setCodec("utf-8");
  out << ctx.toUtf8();
  out.flush();
  file.close();
}

void HtmlBuild::saveFile(QString path, QString fileName, QString ctx)
{
  QFile file(path + "/" + fileName);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
      return;

  QTextStream out(&file);
  out.setCodec("utf-8");
  out << ctx.toUtf8();
  out.flush();
  file.close();
}

void HtmlBuild::loadFile()
{
  QString dataJson;
  QFile jsonFile(JSON_PATH JSON_DATA);
  jsonFile.open(QFile::ReadOnly);
  if (jsonFile.isOpen())
    dataJson = jsonFile.readAll();
  else
    dataJson = "{\"list\":[\"index.html\"],\"pagesCtx\":"
               "[{\"name\":\"name\",\"page\":\"index.html\","
               "\"posts\":[{\"class\":\"center\","
               "\"ctx\":\"пустой блок\",\"id\":\"ds\",\"title\":\"\","
               "\"shortCtx\":\"blank\"}],\"title\":\"Title\"}]}";


  QJsonObject data = QJsonDocument().fromJson(dataJson.toUtf8()).object();
  header = new HeaderItem(QStringList() << "Страница/id" << "Название/ctx" << "Заголовок/class" << "Параметры");
  QJsonArray pagesCtx = data["pagesCtx"].toArray();
  for(int i = 0; i < pagesCtx.size(); i++)
    {
      QJsonObject jsonPage = pagesCtx[i].toObject();
      QJsonArray jsonPosts = jsonPage["posts"].toArray();
      PageItem *pageItem = new PageItem(this, jsonPage);

      for (int j = 0; j < jsonPosts.size(); j++)
        {
          QJsonObject jsonPost = jsonPosts[j].toObject();
          buildPost(pageItem, jsonPost);
        }

      header->appendChild(pageItem);
    }

}

void HtmlBuild::clkClose() {
  QList<QString> files; // page
  QMap<QString,QPair<QString,QString>> pageList; // page, html
  QMap<QString,QString> menuList; // page, name
  QMap<QString,QString> menus; // page, navbar

  QJsonObject save;
  QJsonArray savePages;
  QJsonArray saveList;

  int rows = header->childCount();
  for (int i = 0; i < rows; i++) {
    PageItem* row = dynamic_cast<PageItem*>(header->child(i));
    QPair<QString,QString> ctx = row->getCtx();

    files.append(row->getPage());
    saveList.append(row->getPage());
    pageList.insert(row->getPage(), row->getCtx());
    menuList.insert(row->getPage(), row->getName());
    savePages.append(row->json());
  }

  for (QString file: files)
    {
      QString nav = navbar(getName(file), file, files, menuList);
      menus.insert(file, nav);
    }

  for (QString file: files)
    {
      QPair<QString,QString> preCtx = pageList[file];
      QString tpl = preCtx.first;
      QString body = preCtx.second;

      QString ctx = tpl.arg(htmlHeader(), menus[file], body, htmlfooter());
      saveFile(file,ctx);
    }

  save["pagesCtx"] = savePages;
  save["list"] = saveList;
  QJsonDocument saveDoc(save);
  QString saveData1 = saveDoc.toJson(QJsonDocument::Compact);

  saveFile(JSON_PATH, JSON_DATA, saveData1);

  destroy();
  close();
}

void HtmlBuild::clkAddPage()
{
  modelList->newPage();
}
