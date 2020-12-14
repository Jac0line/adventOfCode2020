#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <map>
#include <regex>

std::string findString(std::string str)
{
	//str = "hgt:59cm byr:2029 cid:219 pid:9381688753 eyr:1992 hcl:#b6652a";
	auto index = str.find(' ');
	std::string pairStr;
	//std::cout<<" str: "<<str<<'\n';
	if (index != std::string::npos) 
	{
		//std::cout<<" found space"<<'\n';
		pairStr = str.substr(0,index);
	}
	else
	{
		auto index = str.find('\n');
		if (index != std::string::npos) 
		{
			//std::cout<<" found endline"<<'\n';
			pairStr = str.substr(0,index);
		}
		else
		{
			//std::cout<<" found nothing"<<'\n';
			pairStr = str.substr(0,str.length());
		}
	}
	//std::cout << "findString: " << pairStr << '\n';
	return pairStr;
}

std::pair<std::string,std::string> makePair(std::string str)
{
	auto index = str.find(':');
	std::pair<std::string,std::string> keyVal;
	if (index != std::string::npos) {

	   // Split around ':' character
	   keyVal = std::make_pair(
	      str.substr(0,index),
	      str.substr(index+1)
	   );

	   // Trim any leading ' ' in the value part
	   // (you may wish to add further conditions, such as '\t')
	   while (!keyVal.second.empty() && keyVal.second.front() == ' ') {
	      keyVal.second.erase(0,1);
	   } 
	}
	return keyVal;
}

int main(){
   std::fstream inputFile;  
   inputFile.open("inputFileDay4.txt",std::ios::in); //open a file to perform read operation using file object
   
   std::pair<std::string,std::string> pair_map;
   std::multimap<std::string,std::string> map;
//   list<std::pair<std::string,std::string>> pasport;

   int counter = 0;

   //file to vector
   int pasportID = 0;
   if (inputFile.is_open()){   //checking whether the file is open
        std::string line;
	int stringnr = 0;
      	while(getline(inputFile, line)){ //read data from file object and put it into string.
      		if(!line.empty())
      		{      	
      			while(!line.empty())
      			{
      				if(line.at(0) == ' ') {
	      				line.erase(0,1);
	   			} 
	    			std::string aPair = findString(line);
				pair_map = makePair(aPair);
 //     				pasport.insert(pair_map);
      				map.insert(pair_map);
				//std::cout << pair_map.first << pair_map.second << std::endl;  
				//std::cout<<"line.begin()+aPair.length()" << aPair.length()<<'\n';
		 		line.erase (line.begin(), line.begin()+aPair.length());

		 		//std::cout << "rest of line: " << line << '\n';
			}
      		}
      		else if(line.empty())
      		{   		
      			pasportID++;
      			//std::cout << "pasportID" << pasportID << '\n';
      			if(map.find("iyr") != map.end() 
      			&& map.find("hgt") != map.end()
      			&& map.find("byr") != map.end()
      			//&& map.find("cid") != map.end()
      			&& map.find("pid") != map.end()
      			&& map.find("eyr") != map.end()
      			&& map.find("hcl") != map.end()
      			&& map.find("ecl") != map.end())
      			{
      			
				//std::cout << "iyr: " << map.find("iyr")->second << std::endl;
				//std::cout << "hgt: " << map.find("hgt")->second << std::endl;
				//std::cout << "byr: " << map.find("byr")->second << std::endl;
				//std::cout << map.find("cid")->second << std::endl;
				//std::cout << "pid: " << map.find("pid")->second << std::endl;
				//std::cout << "eyr: " << map.find("eyr")->second << std::endl;
				//std::cout << "hcl: " << map.find("hcl")->second << std::endl;
				//std::cout << "ecl: " << map.find("ecl")->second << std::endl;
      				int byr = std::stoi(map.find("byr")->second);
      				int iyr = std::stoi(map.find("iyr")->second);
      				int eyr = std::stoi(map.find("eyr")->second);
      				std::string hgt = map.find("hgt")->second;
      				std::cout<<hgt.substr(0,(hgt.length()-2))<<std::endl;
      				std::cout<<hgt.substr((hgt.length()-2),(hgt.length()))<<std::endl;
      				if(hgt.substr((hgt.length()-2),(hgt.length())) == "cm" 
      				|| hgt.substr((hgt.length()-2),(hgt.length())) == "in")
      				{
	      				std::cout <<"hgt.length()"<<hgt.length();
	      				int hgtLength = std::stoi(hgt.substr(0,(hgt.length()-2)));
	      				std::string hgtMs = hgt.substr((hgt.length()-2),(hgt.length()));
	      				std::string hcl = map.find("hcl")->second;
	      				std::string ecl = map.find("ecl")->second;
	      				std::string pid = map.find("pid")->second;
	      				 
	      				if(
	      				(byr >= 1920 && byr <=2002)    				
	      				&& (iyr >= 2010 && iyr <=2020)
	      				&& (eyr >= 2010 && eyr <=2030)
	      				&& (( hgtMs == "cm" && (hgtLength >= 150 && hgtLength <= 193)) 
	      				|| (hgtMs == "in" && (hgtLength >= 59 && hgtLength <= 76)))
	      				&& (hcl[0] == '#' 
	      				&& (hcl[1] >='0' && hcl[1] <='f')
	      				&& (hcl[2] >='0' && hcl[2] <='f')
	      				&& (hcl[3] >='0' && hcl[3] <='f')
	      				&& (hcl[4] >='0' && hcl[4] <='f')
	      				&& (hcl[5] >='0' && hcl[5] <='f')
	      				&& (hcl[6] >='0' && hcl[6] <='f'))
	      				&& (ecl == "amb" || ecl == "blu" || ecl == "brn" 
	      				|| ecl == "gry" || ecl == "grn" || ecl == "hzl" 
	      				|| ecl == "oth")
	      				&& (pid[0] >='0' && pid[0] <='9'
	      				&& (pid[1] >='0' && pid[1] <='9')
	      				&& (pid[2] >='0' && pid[2] <='9')
	      				&& (pid[3] >='0' && pid[3] <='9')
	      				&& (pid[4] >='0' && pid[4] <='9')
	      				&& (pid[5] >='0' && pid[5] <='9')
	      				&& (pid[6] >='0' && pid[6] <='9')
	      				&& (pid[7] >='0' && pid[7] <='9')
	      				&& (pid[8] >='0' && pid[8] <='9'))
	      				)
	      				{     							      	
		      				counter++;
		      				std::cout << "counter1: " << counter << std::endl;
						std::cout << map.find("iyr")->second << std::endl;
						std::cout << map.find("hgt")->second << std::endl;
						std::cout << map.find("byr")->second << std::endl;
						//std::cout << map.find("cid")->second << std::endl;
						std::cout << map.find("pid")->second << std::endl;
						std::cout << map.find("eyr")->second << std::endl;
						std::cout << map.find("hcl")->second << std::endl;
						std::cout << map.find("ecl")->second << std::endl;
					}
				}
			}      			      			
      			map.clear();
      		}      		
	}
      	inputFile.close(); //close the file object.
      	std::cout << "counter: " <<counter;
   } 
}

//byr (Birth Year) - four digits; at least 1920 and at most 2002.
//iyr (Issue Year) - four digits; at least 2010 and at most 2020.
//eyr (Expiration Year) - four digits; at least 2020 and at most 2030.

//hgt (Height) - a number followed by either cm or in:
//If cm, the number must be at least 150 and at most 193.
//If in, the number must be at least 59 and at most 76.
//hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
//ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
//pid (Passport ID) - a nine-digit number, including leading zeroes.

//cid (Country ID) - ignored, missing or not.



