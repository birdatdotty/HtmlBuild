#include "PostPics.h"
#include "PostPicsEdit/PostPicsEdit.h"

//#include "../PageEdit/PageEdit.h"

#include <QPair>
#include <QComboBox>
#include <QTime>


PostPics::PostPics(const Site *site, QJsonObject item)
  : BaseItem(site),
    stId(item["id"].toString("")),
    stCtx(item["ctx"].toString("")),
    stShortCtx(item["shortCtx"].toString("")),
    stClass(item["class"].toString("pics")),
    stTitle(item["title"].toString("")),
    img(item["img"].toString(""))
{
  QJsonArray picArr = item["imgs"].toArray();
  for (int i = 0; i < picArr.size(); i++)
    {
      pics.append(picArr[i].toString());
    }

  self = this;
}

int PostPics::columnCount() const
{
  return 0;
}

QVariant PostPics::data(int column) const
{
  switch (column) {
    case 0: return stId;
    case 1:
      return QVariant::fromValue(self);
    case 2:
      return QVariant::fromValue(self);
    case 3:
      return QVariant::fromValue(self);

    default: return QVariant();
  }
}

bool PostPics::setData(int column, const QVariant &value)
{
  switch (column) {
    case 0: stId = value.toString(); return true;
    case 1: stCtx = value.toString(); return true;
    case 2: stClass = value.toString(); return true;
    default: return false;
  }
}

QString PostPics::getHtml()
{
  QString tpl_html, html;

  QString tmpCtx = stCtx;
  if (pics.size() == 0)
    return html;

  html = "<div class="+stClass+">";
  for (int i = 0; i < pics.size(); i++)
    {
      html += "<img alt='' src='" + pics[i] + "'>";
    };
  html += "</div>";

  return html;
}

QString PostPics::getBody() { return stCtx; }
QString PostPics::getShortCtx() const { return stShortCtx; }
QString PostPics::getClass() const { return stClass; }
QString PostPics::getId() const { return stId; }
QString PostPics::getImg() const { return img; }
QString PostPics::getTitle() const { return stTitle; }

void PostPics::setCtx(QString str) {stCtx = str;}
void PostPics::setClass(QString str) {stClass = str;}
void PostPics::setId(QString str) {stId = str;}
void PostPics::setImg(QString str) {img = str;}

void PostPics::setTitle(QString title)
{
  stTitle = title;
}

QWidget *PostPics::createEditor(QWidget *parent, const QStyleOptionViewItem &/*option*/, const QModelIndex &index) const
{
  int column = index.column();
  const QStringList classes = getClasses(type);
  if (column == 2)
    {
      QComboBox* editor = new QComboBox(parent);
      editor->addItems(classes);
      editor->setCurrentText(stClass);
      connect(editor, &QComboBox::currentTextChanged, this, &PostPics::chageStClass);

      return editor;
    }

  if ((column == 3) || (column == 1))
    {
      const Site* site = dynamic_cast<const Site*>(this);
      PostPicsEdit *edit = new PostPicsEdit(site, pics);
      connect(edit, &PostPicsEdit::updateImgList, this, &PostPics::changeImgList);
      return edit;
    }

  return new QWidget;

}

void PostPics::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  int column = index.column();
  if (column == 1)
    {
      int num = pics.size();
      switch (num) {
        case 0:
          BaseItem::draw(painter, option, "пусто");
          return;
        case 1:
          BaseItem::draw(painter, option, pics[0]);
          return;
        default:
          BaseItem::draw(painter, option, QString::number(num) + " картин(ок/ки)");
          return;
      }
    }
  if (column == 2)
    {
      BaseItem::draw(painter, option, stClass);
      return;
    }
  if (column == 3)
    {
      draw(painter, option, "Настройки...");
      return;
    }
}

QJsonObject PostPics::json()
{
  QJsonObject data;
  QJsonArray imgList;
  foreach (QString file, pics)
    imgList.push_back(file);

  data["id"] = stId;
  if (pics.size()>0)
    data["imgs"] = imgList;

  data["class"] = stClass;
  data["type"] = type;

  return data;
}

void PostPics::changeImgList(QStringList list)
{
  pics = list;
}

void PostPics::chageStClass(const QString &text)
{
  stClass = text;
}

BaseItem *createPostPicsItem(Site *site, QJsonObject item)
{
  if (item.isEmpty())
    {
      item["class"] = "pics";
      item["id"] = "pics" + QString::number(QTime::currentTime().second());
    }

  PostPics* postPics = new PostPics(site, item);

  return postPics;
}
