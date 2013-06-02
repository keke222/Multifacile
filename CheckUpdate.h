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

#ifndef CHECKUPDATE_H
#define CHECKUPDATE_H

#define VERSION 315

#include <QTcpSocket>
#include <QDataStream>

typedef enum UpdateType UpdateType;

enum UpdateType
{
    NoUpdate, NormalUpdate, UpdaterUpdate
};

class CheckUpdate : public QTcpSocket
{
    Q_OBJECT
public:
    CheckUpdate(QObject *parent, const int version);
    void tryConnection();
private:
    quint16 messageSize;
    int actualVersion;
    inline void Connection();
public slots:
    void dataReceived();
    void sendRequest();
signals:
    void checkUpdateAnswer(UpdateType);
};

#endif // CHECKUPDATE_H
