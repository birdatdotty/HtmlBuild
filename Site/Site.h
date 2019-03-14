#ifndef SITE_H
#define SITE_H

#include <QString>
#include <QStringList>

#include <QMap>
#include <QSet>

#include <QJsonObject>


class BaseItem;
class Site;

typedef  BaseItem*(*makePost)(Site*,QJsonObject);

class Site
{
  public:
    Site(QString dir, QMap<QString,makePost> genPost);
    Site(const Site*);

    QStringList getFiles(QString dir, QStringList filter = QStringList());
    QStringList getItemClasses() const;

    bool buildPost(BaseItem* parent, QJsonObject&);

  protected:
    QString dir;
    QString dirImg;
    QStringList getClasses () const;
    QStringList getClasses (QString type) const;
    QString GetRandomString(QString fileName, const int randomStringLength = 4);
    QString htmlHeader();
    QString htmlfooter();
    QString getName(QString page);
    QString getDiv(QString className);
    QString getTplHtml();
    QString navbar(QString name, QString &page, QList<QString> pages, QMap<QString,QString> &list);
    QJsonObject jsonPostConfig;


  private:
    QStringList classes;
    QString stHtmlHeader;
    QString stHtmlFooter;
    QString tplHtml;
    QMap<QString,QString> divs;
    QMap<QString,makePost> genPost;
    QJsonObject newPosts;

    void updateConfig();
};

#endif // SITE_H
