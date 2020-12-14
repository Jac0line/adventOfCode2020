#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

int64_t countTrees(int right, int down, std::vector<std::string> stringLine)
{
   int64_t counter = 0;
   int j = 0;
   for(int i = 0; i <  stringLine.size(); i+=down) //down 1
   {
   	std::cout << "down:" << down;
   	std::cout << " i: " << i;
   	std::cout << " j: " << j;
   	std::cout << " counter: " << counter << '\n';
   	
   	std::string line = stringLine.at(i);
   	if(line[j] == '#')
   	{
   		counter++;
   	}
 	
	if( (j+right) >= line.size())
   	{
    		j = j - line.size() + right;
	}
   	else {
		j = j + right;
   	}   	
   }  
   std::cout << "counter: " << counter << '\n';
   return counter;
}

int main(){
   std::fstream inputFile;  
   inputFile.open("inputFileDay3.txt",std::ios::in); //open a file to perform read operation using file object
   std::vector<std::string> stringLine;

   //file to vector
   if (inputFile.is_open()){   //checking whether the file is open
        std::string line;
	int stringnr = 0;
      	while(getline(inputFile, line)){ //read data from file object and put it into string.
		stringLine.push_back(line);
		//std::cout << stringLine.at(stringnr) << '\n';
		stringnr++;
	}
      	inputFile.close(); //close the file object.
   }
   
   //read all lines and characters
   std::string line; 
   for(int i = 0; i <  stringLine.size(); ++i)
   {
   	line = stringLine.at(i);
   	for(int j = 0; j < line.size(); ++j)
   	{
   		//std::cout << line[j];
   	}
   	//std::cout << '\n';
   }  
     
   line = ""; 
   std::cout << "stringLine.size()" << stringLine.size() << '\n';
   int64_t c1 = countTrees(1, 1, stringLine);
   int64_t c2 = countTrees(3, 1, stringLine);
   int64_t c3 = countTrees(5, 1, stringLine);
   int64_t c4 = countTrees(7, 1, stringLine);
   int64_t c5 = countTrees(1, 2, stringLine);
   
   int64_t c6 = (c1*c2*c3*c4*c5);
   std::cout << c6 << '\n';
}
