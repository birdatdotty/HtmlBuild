#include "PageEdit.h"
#include "../Model/ModelList.h"

PageEdit::PageEdit(const Site *site, const QModelIndex &index0, PageItem* pageItem)
  : Site(site),
    lPageIndex(new QLabel("Страница:")),
    lPageName(new QLabel("Название")),
    lPageTitle(new QLabel("Заголовок:")),

    ePageIndex(new QLineEdit(pageItem->getPage())),
    ePageName(new QLineEdit(pageItem->getName())),
    ePageTitle(new QLineEdit(pageItem->getTitle())),

    selectPost(new QComboBox()),

    bAddPost(new QPushButton("добавить post")),
    bOk(new QPushButton("ОК")),
    bCancel(new QPushButton("Отмена")),

    pageItem(pageItem),
    index(index0),
    curRow(index0.row()),
    site(site)
{
  model = const_cast<ModelList*>((dynamic_cast<const ModelList*>(index0.model())));
//  selectPost->addItem("txt1", "data1");
//  selectPost->addItem("txt2", "data2");
//  selectPost->addItem("txt3", "data3");
  selectPost->addItems(getItemClasses());

  mainLayout.addWidget(lPageIndex, 1, 0);
  mainLayout.addWidget(lPageName, 2, 0);
  mainLayout.addWidget(lPageTitle, 3, 0);

  mainLayout.addWidget(ePageIndex, 1, 1);
  mainLayout.addWidget(ePageName, 2, 1);
  mainLayout.addWidget(ePageTitle, 3, 1);

  mainLayout.addWidget(selectPost, 4, 0);
  mainLayout.addWidget(bAddPost, 4, 1);
  mainLayout.addWidget(bOk, 5, 0);
  mainLayout.addWidget(bCancel, 5, 1);

  connect(bAddPost, &QPushButton::released, this, &PageEdit::clkAddPost);
  connect(bOk, &QPushButton::released, this, &PageEdit::clkOk);
  connect(bCancel, &QPushButton::released, this, &QWidget::close);

  connect(selectPost, &QComboBox::currentTextChanged, [=](QString txt){

//      qInfo() << selectPost->
    });

  setLayout(&mainLayout);
}

PageEdit::~PageEdit()
{
  delete lPageIndex;
  delete lPageName;
  delete lPageTitle;
  delete ePageIndex;
  delete ePageName;
  delete ePageTitle;

  delete selectPost;

  delete bAddPost;
////error:
////  QPaintDevice::metrics: Device has no metric information
////  Unrecognised metric 19678528!
//  delete bOk;
//  delete buttons;
}

void PageEdit::clkAddPost()
{
////  {"class":"right","ctx":"","id":"IDвлввв",
////  "img":"/img/carusel2.jpg","shortCtx":"уrrrr",
////  "title":"eeeeER","type":"default"}
//  QJsonObject postData;
//  postData["class"] = "right";
//  postData["ctx"] = "<p>новая</p>";
//  postData["id"] = "new";
//  postData["img"] = "";
//  postData["shortCtx"] = "новый post";
//  postData["title"] = "новый post";

//  AbstractPostItem* post = new PostItem(site, postData);
//  model->newPost(curRow, pageItem, post);

  QJsonObject postData;
  postData["type"] = selectPost->currentText();
  buildPost(pageItem, postData);


  close();
}
void PageEdit::clkOk()
{
  QString index = ePageIndex->text();
  QString name = ePageName->text();
  QString title = ePageTitle->text();
  if ((index.size()>0) && (name.size()>0) && (title.size()>0))
    {
      pageItem->setPage(index);
      pageItem->setName(name);
      pageItem->setTitle(title);

      close();
    }
}
