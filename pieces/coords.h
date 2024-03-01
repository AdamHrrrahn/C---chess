#ifndef COORDS_H
#define COOrDS_H

class Coords
{
    public:
        Coords(){x = -1; y = -1;};
        Coords(int a, int b){x = a; y = b;};
        int x;
        int y;
};
#endif