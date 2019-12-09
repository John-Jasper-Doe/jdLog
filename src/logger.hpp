/**
 * @file logger.hpp
 *
 *
 *
 */

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <memory>

namespace logger {

class log_file;
class log_helper;

class log {
//  std::unique_ptr<log_file> lf_;
//  std::unique_ptr<log_helper> lh_;

public:
  log& instance() noexcept;
  log() noexcept;


  template <typename T>
  friend logger::log& operator<<(logger::log& l, T& v);


private:

//  void log(const char* s) {
//    h << s;
//    f = log_file("g");
//  }

};
}


template <typename T>
logger::log& operator<<(logger::log& l, T& v) {
  l << v;
  return l;
}

#endif /* LOGGER_HPP_ */


//#ifndef LOGGER_H
//#define LOGGER_H

//#include <fstream>
//#include <filesystem>

//namespace fs = std::filesystem;

//class Logger {
//  public:
//    enum Type {
//      DEBUG = 0,
//      INFO,
//      WARNING,
//      ERROR,
//      FATAL
//    };

//    ~Logger();

//    static Logger* getLogger(const fs::path &fileName);

//    static void log(const std::string msg, Type type = INFO, bool ss = false);
//    static void log_err(const std::string msg);
//    static void log_warn(const std::string msg);
//    static void log_fatal(const std::string msg);

//  private:
//    static std::fstream m_fstrm;
//    static std::string levels[5];

//    Logger();
//    Logger(const Logger&) = delete;
//    Logger& operator=(const Logger&) = delete;

//    Logger(Logger &&) = delete;
//    void operator=(const Logger&&) = delete;
//};

//#endif // LOGGER_H
