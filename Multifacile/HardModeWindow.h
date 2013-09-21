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

#ifndef HARDMODEWINDOW_H
#define HARDMODEWINDOW_H

#include "MediumModeWindow.h"
#include "CustomMessageBox.h"

class HardModeWindow : public MediumModeWindow
{
    Q_OBJECT

public:
    HardModeWindow();
    ~HardModeWindow() {}

    const unsigned short int getMultiple() { return 1; }
private:
    unsigned short int _multiple[10];
    void correct();
public slots:
    void Retry();
};

#endif // HARDMODEWINDOW_H
