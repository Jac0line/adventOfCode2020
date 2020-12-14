#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

int count_char(std::string c, std::string s) {
  int count = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == c[0]) 
    {
    	count++;
    }
  }
  return count;
}

int main(){
   std::fstream inputFile;
   
  std::ifstream inFile("inputFileDay2.txt"); 
  int count = std::count(std::istreambuf_iterator<char>(inFile), 
             std::istreambuf_iterator<char>(), '\n');
  std::cout << "Total amount of passwords: " << count << '\n';
  int elements = 4;
  	  
  int min = 0; //0   //pos1
  int max = 0; //1   //pos2
  std::string character; //2
  std::string stringPwd; //3
  int counter = 0; 
  int counterPart2 = 0;
  
  //std::array<std:: linesVector[min][max][character][string];
   std::string array[count][elements];
   inputFile.open("inputFileDay2.txt",std::ios::in); //open a file to perform read operation using file object
   if (inputFile.is_open()){   //checking whether the file is open
      std::string line;
        std::regex words_regex("[^\\s:-]+");

	int stringnr = 0;
      	while(getline(inputFile, line)){ //read data from file object and put it into string.
		auto words_begin = std::sregex_iterator(line.begin(), line.end(), words_regex);
    		auto words_end = std::sregex_iterator();	
	
		int id = 0;
    		for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    		{
    	 		array[stringnr][id] = (*i).str();
    	 		id++; 	
	        }
	        int nrOfChars = count_char(array[stringnr][2], array[stringnr][3]);
	        if(nrOfChars >= std::stoi(array[stringnr][0]) && nrOfChars <= std::stoi(array[stringnr][1]))
	        {
	        	counter++;
	        }
	        
	        min = std::stoi(array[stringnr][0]);
		max = std::stoi(array[stringnr][1]);
		stringPwd = array[stringnr][3];
		character = array[stringnr][2];
	
		if(stringPwd.at(min-1) == character.at(0) ^ stringPwd.at(max-1) == character.at(0))			
        	{	        		
        		counterPart2++;
        	}
	        stringnr++;       		        
	}
      	inputFile.close(); //close the file object.
   }   
   std::cout << "Correct passwords part 1: " << counter << '\n';  
   std::cout << "Correct passwords part 2: " << counterPart2 << '\n';   
       
}



