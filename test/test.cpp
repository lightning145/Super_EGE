#include "../include/super_ege.h"

int main()
{
    bool super_run = true;

    initgraph(1280,720,true);
    setcaption("Game");

    setbkcolor(1,0,0,1);

    present();

    while (super_run)
    {
        if(getch())
        {
            super_run = false;
        }
    }
    
    closegraph();

    return 0;
}