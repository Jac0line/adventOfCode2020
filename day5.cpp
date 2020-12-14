#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <math.h>  
#include <list>

int main(){
   std::fstream inputFile;  
   inputFile.open("inputFileDay5.txt",std::ios::in);   
   std::vector<std::string> stringLine;

   if (inputFile.is_open()){   //checking whether the file is open
        std::string line;
	int stringnr = 0;
      	while(getline(inputFile, line)){ 
		stringLine.push_back(line);
		//std::cout << stringLine.at(stringnr) << '\n';
		stringnr++;
	}
      	inputFile.close(); //close the file object.
   }
   
   //read all lines and characters
   std::string line; 
   int maxRow = 127;
   int minRow = 0;
   int maxCol = 7;
   int minCol = 0;
   int rownr = -1;
   int colnr = -1;
   std::list<int> seatNumbers;
   for(int i = 0; i <  stringLine.size(); ++i)
   {
	line = stringLine.at(i);
	float rownrMax = 127;
	float rownrMin = 0;
	float colnrMax = 7;
	float colnrMin = 0;
	float seatId = 0;
   	for(int j = 0; j < line.size(); ++j)
   	{
   		//std::cout << line[j];
   		if( j >= 0 && j < 7)//part of rownr
   		{
   			
			if(line[j] == 'F')//lower half
			{			//127 - 63 = 127-0 =127 / 2 = 63.5
				rownrMax = (rownrMax - ceil((rownrMax-rownrMin)/2));
			}  
			else if(line[j] == 'B')//upper half
			{
				rownrMin = (round((rownrMax-rownrMin)/2)+rownrMin);
			}
			//std::cout << line[j] << "rownrMin" << rownrMin << "rownrMax" << rownrMax <<std::endl;;
		}		
		else if( j >= 7 && j < 10)
		{
			if(line[j] == 'L') //lower half
			{
				colnrMax = (colnrMax - ceil((colnrMax - colnrMin)/2));
			}  
			else if(line[j] == 'R') //upper half
			{
				colnrMin = (round((colnrMax-colnrMin)/2)+colnrMin);
				
			}
			//std::cout << line[j] << "colnrMin" << colnrMin << "colnrMax" << colnrMax <<std::endl;;
		}
		else{
		
		std::cout << "j"<<j << " : " << line[j]<<std::endl; 	
		}	

   	}
   	
	if(rownrMax == rownrMin && colnrMax == colnrMin)
	{
		seatId = (rownrMax * 8)+colnrMax;
		seatNumbers.push_back(seatId);
		//std::cout << seatId << std::endl;
	}
	else{
		std::cout << "Not good ya" << std::endl;
	}
   	//std::cout << " rownrMin: " << rownrMin << " rownrMax: " << rownrMax
   	//<< " colnrMin: " << colnrMin << " colnrMax: " << colnrMax << std::endl;
   }  
   seatNumbers.sort();
   int lastSeat = -1;
   for (auto v : seatNumbers){
        std::cout << v << "\n";
        if(v != lastSeat)
        {
        	if(lastSeat + 1 != v)
        	{
        		std::cout<< "MY SEAT? : " << v-1;
        	}
        	lastSeat = v;
        }
   }
}
