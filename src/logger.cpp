#include "logger.hpp"


#include "loghelper.hpp"
#include "logfile.hpp"

namespace logger {

log& log::instance() noexcept {
  static log l;
  return l;
}

log::log() noexcept
//  : lf_(std::make_unique<log_file>())
//  , lh_(std::make_unique<log_helper>())
{ }



} /* logger:: */





















////#include "time_date.h"

//#include <iostream>

//using namespace std;

//string Logger::levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "FATAL"};
//fstream Logger::m_fstrm;

//Logger* Logger::getLogger(const fs::path &fileName) {
//    static Logger logger;
//    m_fstrm.exceptions (fstream::failbit | fstream::badbit );
//    m_fstrm.open(fileName.c_str(), ios::out | ios::app);
//    m_fstrm.unsetf(ios::skipws);
//    log("Start logging", Logger::INFO, true);
//    return &logger;
//}

//Logger::Logger() {}

//Logger::~Logger() {
//  log("Stopped logging\n", Logger::INFO, true);
//  m_fstrm.close();
//}

//void Logger::log(const string msg, Type type, bool ss) {
//  if (!ss)
//    cout << msg << endl;
//  if (m_fstrm.is_open()) {
//    m_fstrm << /*strTimeStamp() <<*/ " : [ " << levels[static_cast<int>(type)] << " ] " << msg << endl;
//  }
//  else
//    cout << "Unable to open log file" << endl;
//}

//void Logger::log_err(const string msg) {
//  log(msg, Logger::ERROR);
//}

//void Logger::log_warn(const string msg) {
//  log(msg, Logger::WARNING);
//}

//void Logger::log_fatal(const string msg) {
//  log(msg, Logger::FATAL);
//}
