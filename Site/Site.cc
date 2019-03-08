#include "Site.h"

#include "config.h"

#include <QStringList>
#include <QDir>
#include <QTime>
#include <QMap>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "../Posts/posts.h"

#include <functional>

Site::Site(QString dir)
  : dir(dir),
    dirImg(dir+"/img/")
{
  const Site* site = this;

  genPost.insert("default", createPostItem);
  genPost.insert("pics", createPostPicsItem);
//  newPosts["default"] =

  updateConfig();
}

void Site::updateConfig()
{
  QFile jsonFile(JSON_PATH JSON_CONFIG);
  jsonFile.open(QFile::ReadOnly);
  if (jsonFile.isOpen())
    {
      QString dataJson = jsonFile.readAll();
      QJsonObject data = QJsonDocument().fromJson(dataJson.toUtf8()).object();

      QJsonArray htmlHeaderArreay = data["aHtmlHeader"].toArray();
      for (int i = 0; i < htmlHeaderArreay.size(); i++)
        stHtmlHeader += htmlHeaderArreay[i].toString();

      stHtmlFooter = data["stHtmlFooter"].toString();
      tplHtml = data["tplHtml"].toString();
      QJsonObject jsonDivs = data["divs"].toObject();
      for (auto key: jsonDivs.keys())
        {
          classes << key;
          divs[key] = jsonDivs[key].toString();
        }
    }
}

Site::Site(Site *parent)
  : dir(parent->dir),
    dirImg(parent->dirImg),
    classes(parent->classes),
    stHtmlHeader(parent->stHtmlHeader),
    stHtmlFooter(parent->stHtmlFooter),
    tplHtml(parent->tplHtml),
    divs(parent->divs),
    genPost(parent->genPost)
{}

Site::Site(const Site *parent)
  : dir(parent->dir),
    dirImg(parent->dirImg),
    classes(parent->classes),
    stHtmlHeader(parent->stHtmlHeader),
    stHtmlFooter(parent->stHtmlFooter),
    tplHtml(parent->tplHtml),
    divs(parent->divs),
    genPost(parent->genPost)
{}

QStringList Site::getFiles(QString d, QStringList filter)
{
  QStringList files;
  QDir selectDir(dir);
  selectDir.cd(d);
  QString stDir = dir + "/" + d + "/";
//  dirImg

  foreach (QString file, selectDir.entryList(filter))
    files.append("/" + d + "/" + file);

  return files;
}

QStringList Site::getItemClasses() const
{
  QStringList list;
  list << "default" << "pics";

  return list;
}

QStringList Site::getClasses() const
{
  return classes;
}

QString Site::GetRandomString(QString fileName, const int randomStringLength)
{
  QString suffix = fileName.split(".").last();
  qsrand(static_cast<uint>(QTime::currentTime().msec()));
  const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");

 QString randomString;
 for(int i=0; i<randomStringLength; ++i)
   {
     int index = qrand() % possibleCharacters.length();
     QChar nextChar = possibleCharacters.at(index);
     randomString.append(nextChar);
   }

 if (suffix.size() > 0)
   randomString += "." + suffix;

 return randomString;
}

QString Site::htmlHeader()
{
  return stHtmlHeader;
}

QString Site::htmlfooter()
{
  return stHtmlFooter;
}

QString Site::getName(QString /*page*/)
{
  return "Волар";
}

QString Site::getDiv(QString className)
{
  // %1 - id
  // %2 - text
  // %3 - img

  for(auto it = divs.begin(); it != divs.end(); ++it)
  {
      if (className == it.key())
        return it.value();
  }

  return divs["default"];
}

QString Site::getTplHtml()
{
  return tplHtml;
}

QString Site::navbar(QString name, QString &page, QList<QString> pages, QMap<QString, QString> &list)
{
  QString menu = "<nav class='navbar navbar-expand-lg navbar-light bg-light'><a class='navbar-brand' href='/'>";
          menu += name;
          menu += "</a><button class='navbar-toggler' type='button' data-toggle='collapse' data-target='#navbarNav' aria-controls='navbarNav' aria-expanded='false' aria-label='Toggle navigation'><span class='navbar-toggler-icon'></span></button><div class='collapse navbar-collapse' id='navbarNav'><ul class='navbar-nav'>";


  for(QString key: pages)
    {
      if (page == key)
        menu += "<li class='nav-item active'><a class='nav-link' href='/" + key + "'>" + list[key] +"</a></li>";
      else
        menu += "<li class='nav-item'><a class='nav-link' href='/" + key + "'>" + list[key] +"</a></li>";
    }

  menu += "</ul></div></nav>";


  return menu;
}

bool Site::buildPost(BaseItem* parent, QJsonObject &item)
{
  QString type = item["type"].toString();
  if (genPost.contains(type))
    {
      AbstractPostItem* child = genPost[type](this,item);
      parent->appendChild(child);
      return true;

    }
  return false;
}
