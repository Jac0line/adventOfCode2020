#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
   fstream inputFile;
   vector<int> linesVector;
   inputFile.open("inputFile.txt",ios::in); //open a file to perform read operation using file object
   if (inputFile.is_open()){   //checking whether the file is open
      string line;
      while(getline(inputFile, line)){ //read data from file object and put it into string.
         linesVector.push_back(stoi(line));
      }
      inputFile.close(); //close the file object.
   }
   
   int sum = 0;
   for(int i = 0; i < linesVector.size(); i++)
   {
   	for(int j = 1; j < linesVector.size()-1; j++)
   	{   		
   		if((linesVector.at(i) + linesVector.at(j)) == 2020)
   		{
   			sum = 	linesVector.at(i) * linesVector.at(j);
   			cout << sum << "\n";
   			break;
   		}	
   	}  
   }  
   
   int sum3 = 0;
   for(int i = 0; i < linesVector.size(); i++)
   {
   	for(int j = 1; j < linesVector.size()-1; j++)
   	{   	
   		for(int k = 2; k < linesVector.size()-2; k++)
   		{	   	
   			if((linesVector.at(i) + linesVector.at(j) + linesVector.at(k)) == 2020)
   			{
   				sum3 = 	(linesVector.at(i) * linesVector.at(j) * linesVector.at(k));
   				cout << "sum of 3: " << sum3 << "\n";
   				break;
   			}
   		}	
   	}  
   }     
}
