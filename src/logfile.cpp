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


log_file::log_file(std::string& file) noexcept {
  fstrm_ = std::make_unique<std::fstream>(new std::fstream(), [](std::fstream& fs) { fs.close(); });

  open(file);
}

bool log_file::open(std::string& file) noexcept {
  fstrm_->exceptions(std::fstream::failbit | std::fstream::badbit);
  fstrm_->open(file, std::ios::out | std::ios::app);
  fstrm_->unsetf(std::ios::skipws);

  return fstrm_->is_open();
}



} /* logger:: */
