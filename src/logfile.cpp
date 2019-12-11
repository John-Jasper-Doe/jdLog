/**
 * @file logfile.hpp
 *
 *
 *
 */

#include "logfile.hpp"

#include <array>

namespace jdlog {

bool log_file::open(std::string& file) noexcept {
  fstrm_ = fstrm_t(new std::fstream(), [](std::fstream* fs) { fs->close(); });

  fstrm_->exceptions(std::fstream::failbit | std::fstream::badbit);
  fstrm_->open(file, std::ios::out | std::ios::app);
  fstrm_->unsetf(std::ios::skipws);

  return fstrm_->is_open();
}

} /* logger:: */
