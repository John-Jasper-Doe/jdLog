/**
 * @file logfile.hpp
 *
 *
 *
 */


#include "logfile.hpp"

#include <fstream>
#include <filesystem>
#include <array>
#include <memory>

namespace logger {


log_file::log_file(const char *file) noexcept {
  fstrm_ = std::unique_ptr<std::fstream>(new std::fstream(), [](std::fstream &fs) { fs.close(); });

  open(file);
}

bool log_file::open(const char* file) noexcept {
  fstrm_->exceptions(std::fstream::failbit | std::fstream::badbit);
  fstrm_->open(file, std::ios::out | std::ios::app);
  fstrm_->unsetf(std::ios::skipws);

  return fstrm_->is_open();
}



} /* logger:: */
