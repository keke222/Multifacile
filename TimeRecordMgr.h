/*Copyright (C) <2013> <Plestan> <K�vin>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.*/

#ifndef TIMERECORDMGR_H
#define TIMERECORDMGR_H

#include <QDomDocument>
#include <QFile>
#include <QSettings>
#include <QStringList>
#include <QTextStream>

#include <QDebug>

bool readXML(QIODevice &device, QSettings::SettingsMap &map);
bool writeXML(QIODevice &device, const QSettings::SettingsMap &map);

const QSettings::Format XML = QSettings::registerFormat("xml", readXML, writeXML);

typedef enum RecordState RecordState;

enum RecordState
{
    RECORD, UNVALIDRECORD, NORECORD
};



class TimeRecordMgr : public QSettings
{
    Q_OBJECT
public:
    TimeRecordMgr(Scope scope, const QString &organisation, const int time, const QString &group, const QString &table = QString());

    void CompareTime();
    void SaveRecordInFile();

    static void returnTime(int tab[]);


    QString read();

private:

    int newTime;

    bool hardMode;

    QString Group;
    QString Table;

    inline int returnValue() const;

    inline bool isKeyExist() const;
    
signals:
    void isNewRecord(RecordState, int);
        
};

#endif // TIMERECORDMGR_H
