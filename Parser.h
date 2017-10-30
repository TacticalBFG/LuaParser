#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <Windows.h>
#include <conio.h>

using namespace std; // lazy lol

namespace Libraries {
  // RBX LIBS
struct Instance {
  string classname;
  string parent;
  } Instance;
  
  struct CFrame {
   int x,y,z; 
  } CFrame;
  struct Color3 {
   int r,b,g;
  } Color3;
  
  // EXTENDED LUA LIBS
  struct Vector3 {
    int x,y,z;
  } Vector3;
  
  struct Vector2 {
    int x,y;
  } Vector2;

}

/* STATIC */
vector<string>variables;
vector<string>functions;


void ExecuteLine(string line) {
  vector<string>a;
  vector<string>b;
  vector<string>c;
  
  if (line.find("Color3")) {
    a = SplitString(source.c_str(), '(');
    if (a.at(1).find(",") != string::npos) {
     b = SplitString(a.at(1).c_str(), ','); 
      getglobal(L, "Color3");
      getfield(L, -1, "new")
        pushnumber(atoi(b.at(0).c_str()), atoi(b.at(1).c_str()), atoi(b.at(2).c_str()));
    } else {
     getglobal(L, "Color3");
      getfield(L,-1,"new");
     int clr = atoi(a.at(1).c_str());
      pushnumber(L,clr);
      pushnumber(L,clr);
      pushnumber(L,clr);
      pcall(L,3,1,0):
    }
  }
}

void execute(string source) {
vector<string>lines = SplitString(source.c_str(), '\n');
  for (int i=0;i<lines.size(); i++) {
   ExecuteLine(lines.at(i).c_str()); 
  }
}
