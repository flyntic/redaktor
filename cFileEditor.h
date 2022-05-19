//
// Created by Student on 19.05.2022.
//

#ifndef FILEREDAKTOR_CFILEEDITOR_H
#define FILEREDAKTOR_CFILEEDITOR_H

#include <string>
#include <iostream>

class cFileEditor {
private:
    enum enOpen{
        openRead=1,
        openWrite=2
    };
    enum enAccess{
        accessSymbol=1,
        accessStroka=2
    };
public:
 //  cFileEditor(std::string str)
  //  {

    //    defaultFilePath=str;

 //   }

    bool fileOpen()
    {
        char nameFile[100];
        enOpen typeOpen;
        int temp;
        std::cout<<"Введите название файла";
        std::cin >>nameFile;

        std::cout << "Открыть файл для  \n "<< openRead<<" - Чтения\n" << openWrite<<" - Записи\n";
        std::cin >>temp;

        typeOpen=(enOpen)temp;

        switch(typeOpen)
        {
            case openRead:         currentFile= fopen(nameFile,"r");
            case openWrite:         currentFile= fopen(nameFile,"w");
        }

        if (currentFile==NULL) return false;

        currentNameFile=nameFile;
        this->typeOpen=typeOpen;
        return true;

    }
    bool fileClose()
    {
        fclose(currentFile);
        return true;
    };

   bool doAction()
   {
       std::cout<<"Выберите тип доступа к файлу :";
       std::cout << accessStroka<<" - Построчно\n" << accessSymbol<<" - Посимвольно\n";
       enAccess typeAccess;
       int temp;
       std::cin >>temp;
       typeAccess=(enAccess)temp;

       bool endWork=false;
       do {


           switch (typeOpen) {
               case openRead:
                   std::cout >> doRead(typeAccess);

                   endWork=feof(currentFile);

                   break

               case openWrite:

                  endWork=doWrite(std::cin, typeAccess);

                  break
           }

       } while endWork;

   }


private:
    std::string defaultFilePath;
    std::string currentNameFile;
    FILE * currentFile;
    enOpen typeOpen;

    char * doRead(  enAccess typeAccess)
    {

        switch(typeAccess)
        {
            case accessSymbol:
                return fgetc(currentFile); break;

            case accessStroka:
                                        char *str=malloc(100);
                                         fgets (str,100,currentFile);break;
                                         return str;
        }

        return nullptr;

    }

    bool doWrite(char * str,enAccess typeAccess)
    {
        if (str[0]=='0') return false;

        switch(typeAccess)
        {
            case accessSymbol:
                  fputc(str,currentFile); break;

            case accessStroka:
                fputs (str,currentFile);break;
        }

        return true;
    }
};


#endif //FILEREDAKTOR_CFILEEDITOR_H
