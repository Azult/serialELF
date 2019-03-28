#include "SerialIlia.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <openssl/sha.h>

using namespace std;

struct productCreds {
  char serial[11];
  char name[256];
} ;

bool checkSerial(){
  cout << "[Start]" << endl;

  // Define user creds struct
  struct productCreds creds;

  //Load file
  ifstream myfile; //serial input file
  string serial, name; //serial string
  myfile.open ("license.txt");
  getline(myfile,serial);
  getline(myfile,name);
  myfile.close();
  // cout << "The serial is: " << serial << endl;

  if(check1(serial.length())){
    strcpy(creds.serial, serial.c_str());
  }else{
    return false;
  }

  if(name.length() < 255){
    strcpy(creds.name, name.c_str());
  }else{
    return false;
  }

  //Creating a char array from the serial
  if(check2(creds)){
    return true;
  }

  return false;
}

bool check1(int len){
  if (len != 10){
    return false;
  }
  return true;
}

bool check2(struct productCreds ser){
  char xorMe[6];

  for(int i = 0; i < 5 ; i++){
    xorMe[i] = (int)ser.serial[i] ^ (int)ser.serial[5+i];
  }
  xorMe[5] = '\0';
  ser.name[5] = '\0';

  return !strcmp(ser.name,xorMe);
}
