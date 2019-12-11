#include <iostream>


//#include "loghelper.hpp"
#include "logger.hpp"
#include "logfile.hpp"

using namespace std::literals;


int main(/*int argc, char** argv*/) {
  std::cout << "Start ...\n" << std::endl;


  jdlog::log_file log("test.log"s);

  std::array<unsigned char, 200> arr;
  std::generate(std::begin(arr), std::end(arr), []() { return rand() % 26 + 'a'; });

  log.flush(arr);

//  log << 5 << " str" ;
//  logger::log_helper log;
//  std::string str = "ddddd";

//  log << 3;
//  log << str;
//  log << "str ";
//  log << 4.5;
//  log << logger::endl;

  return 0;

}
