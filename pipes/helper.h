#ifndef HELPER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<cstdio>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<climits>
#include<fcntl.h>
/*
 * It will iterate through all the lines in file and
 * put them in given vector
 */
int getFileContent(std::string infileName,std::vector<std::string>& vecOfStrs)
{
    // Open the File to read the content into buffer
    std::ifstream in(infileName.c_str());

    // Check if object is valid
    if (!in)
    {
        throw (std::runtime_error("Cannot open the File : " ));

    }

    std::string str;
    // Read the next line from File untill it reaches the end.
    while (std::getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if (str.size() > 0)
            vecOfStrs.push_back(str);
    }

    /*for (const auto& str : vecOfStrs)
        std::cout << str << '\n';*/



    in.close();
    return str.size();

}

int writeFileContent(std::string outfileName, std::vector<std::string>& vecOfStrs){
    std::string str;
    //Open the file to output the read buffer
    std::ofstream out(outfileName.c_str());

    if (!out)
    {
        std::cerr << "Write operation failed.";
        return false;
    }

    int result = getFileContent("sample.txt", vecOfStrs);//Test with binary as well

    if(result)
    {
        for (const auto& row : vecOfStrs)
            out << row << '\n';
    }
    out.close();

    return str.size();

}//Close of the write function


#endif
