// Filename - test-json-parser.c

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include "base_visitor.cpp"

int main()
{

  std::ifstream myfile; 
  myfile.open("code.js");

  std::string source_code;

  if (myfile.is_open()){
    while ( myfile ) {
      source_code += myfile.get();
    }
  }

  myfile.close();

  base_ast(source_code);

  return 0;
}