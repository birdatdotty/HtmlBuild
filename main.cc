#include "HtmlBuild.h"
#include <QApplication>
#include "Site/Site.h"

#include <functional>

typedef Site*(*createSite)(QString);

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
//  createSite =

//std::function<Site*(QString)> a = [](QString d){return new Site(d);};
  createSite a = [](QString d){return new Site(d);};
  static QString dir = "/var/www/html";
  Site *site = a(dir);//new Site(dir);

  HtmlBuild w(site);
  w.show();

  QObject::connect(&w, &HtmlBuild::close, &app, &QCoreApplication::quit);

  return app.exec();
}
