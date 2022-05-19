#include <iostream>
#include "cFileEditor.h"

int main()
{
    system("chcp 65001");
    cFileEditor FE; //=cFileEditor("c:\\");
    if (FE.fileOpen()==false)
        std::cout<<"Ошибка";
   while (FE.doAction()==true);
    if ( FE.fileClose())
        std::cout<<"Ошибка";

    return 0;
}
