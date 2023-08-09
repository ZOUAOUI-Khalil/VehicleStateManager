#include "VAR.h"

VAR::VAR()
{

}
 int VAR::variable = 0;
 /*void VAR::saveinivalues(const QString &path,const QString &groupename,const QString &Name,const QString &Value) {

     QSettings settings (path,QSettings::IniFormat);
     settings.beginGroup(groupename);
     settings.setValue(Name,Value);
     settings.endGroup();

 }

 QString VAR::readinivalues(const QString &path,const QString &groupename,const QString &Name) {
     auto Value= QString();
     QSettings settings (path,QSettings::IniFormat);
     settings.beginGroup(groupename);
     Value=settings.value(Name, QString()).toString();
     settings.endGroup();
     return Value;
 }*/
