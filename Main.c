#include <iostream>
#include "SerialIlia.h"

using namespace std;

int main(int argc, char** argv){
  bool check;
  check = checkSerial();
  if(check){
    cout << "Success!" << endl;
    ifstream myfile; //serial input file
    string serial; //serial string
    string flag;
    myfile.open ("license.txt");
    getline(myfile,serial);
    myfile.close();
    cout << "The flag is:" << endl;
    cout << "Flag={" << serial << "}"<< endl;
  }else{
    cout << "Serial is incorrect!" << endl;
  }

  return 0;
}
