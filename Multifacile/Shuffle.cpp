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

#include "Shuffle.h"

Shuffle::Shuffle(bool shuffle) : _needShuffle(shuffle) {}

void Shuffle::getNumbers(int tab[])
{
        srand(time(0));

        for (int i=0; i<10; ++i)
            _numbers[i] = i+1;
        if(_needShuffle)
        {

            for (int i=0; i<(10-1); ++i)
            {
                int r = i + (rand() % (10-i));
                int temp = _numbers[i]; _numbers[i] = _numbers[r]; _numbers[r] = temp;
            }
        }
            for(int i = 0; i<10; ++i)
                tab[i] = _numbers[i];
}
void Shuffle::getNumbers(int tab[], unsigned short array[])
{
    srand(time(0));

    for (int i=0; i<10; ++i)
        _numbers[i] = i;

    for (int i=0; i<(10-1); ++i)
    {
        int r = i + (rand() % (10-i));
        int temp = _numbers[i]; _numbers[i] = _numbers[r]; _numbers[r] = temp;
    }
    for(int i = 0; i<10; ++i)
    {
        ++_numbers[i];
        tab[i] = _numbers[i];
    }
    for(int i = 0; i < (10-1); ++i)
    {
        int r = i + (rand() % (10-i));
        int temp = _numbers[i]; _numbers[i] = _numbers[r]; _numbers[r] = temp;
    }
    for(int i = 0; i < 10; ++i)
        array[i] = _numbers[i];
}
