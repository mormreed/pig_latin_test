#include <iostream>
#include <string>

int main ()
{
  int index=0,length=0,vowelpos=1,i=0,j=0;
  int vcodes [] = {65,69,73,85,97,101,105,111,117};
  bool vowel = false,vowelposf = false;
  /*List of vowel ASCII codes:
  A - 65
  E - 69
  I - 73
  O - 79
  U - 85
  a - 97
  e - 101
  i - 105
  o - 111
  u - 117
  */
  std::string input,output,intermediate;
  
  std::cout << "Please enter a string to be put into Pig Latin: \n";
  std::getline(std::cin,input);
  
  length = input.length();
    
  while(input.length()>0) {
    index = input.find_first_of(" ");
    if(index==-1) {
      index = input.length();
    }
    intermediate = input.substr(0,index);
    if((index+1)<input.length()) {
      input = input.substr(index+1);
    } else {
      input = "";
    }

    //Trim following whitespace
    if(intermediate.find_last_of(" ") != -1) {
      intermediate.replace(intermediate.find_first_of(" "),1,"");
    }
          
    for(i=0;i<10;i++) {
      if(vcodes[i]==intermediate[0]) {
        vowel = true;
      }
    }
    
    if(vowel==false) {
      for(i=0;i<intermediate.length();i++) {
        for(j=0;j<10;j++) {
          if(vcodes[j]==intermediate[i] && vowelposf == false) {
            vowelpos = i;
            vowelposf = true;
          }
        }
      }
      vowelposf = false;
      intermediate = intermediate.substr(vowelpos,intermediate.length()-1) + intermediate.substr(0,vowelpos) + "ay";
    } else {
      intermediate = intermediate + "yay";
      vowel = false;
    }
    
    output = output + " " + intermediate;
  }
  
  if(output.find_first_of(" ")==0) {
    output = output.substr(1);
  }
  
  std::cout << "Your phrase in Pig Latin is: \n" << output << "\n";
  
  return 0;
}

