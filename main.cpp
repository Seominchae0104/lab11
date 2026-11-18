#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "student.h"


namespace SeoMinchae2649083{
    void readWriteStudentDataFile(std::ifstream& fin, std::ofstream& fout)
    {
        std::vector <student> v;

        while(! fin.eof())
        {
             student s; 

            std::streambuf* origBuf{std::cout.rdbuf()};
            std::cout.rdbuf(nullptr);
            fin >> s; 
            std::cout.rdbuf(origBuf);
            
            v.push_back(s);

        }

        for(const auto& vi: v)
           fout << vi;

    }

}


int main()
{

    using namespace SeoMinchae2649083;
    
    std::ifstream fin{"studentData.txt"};

    if(fin.fail())
    {
        std::cout << "file fail";
        std::exit(1);
    }
    
    std::ifstream fout {"out,txt"};
    std::string filename;
    std:: cout << "file name:";
    std::cin >> filename;
    filename = filename + ".txt";
    fout.open(filename);
   
    if(fout.fail())
    {
        std::cout << "file fail";
        std::exit(1);
    }

    readWriteStudentDataFile(fin, cout);

    fin.close();
    fout.close();
   


    return 0;

}