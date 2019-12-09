/**
 * @file logfile.hpp
 *
 *
 *
 */




#ifndef LOGFILE_HPP_
#define LOGFILE_HPP_

#include <iosfwd>
#include <fstream>
//#include <filesystem>
//#include <array>
#include <memory>




namespace logger {

namespace detail {

//void fstrm_close()

} /* detail:: */


class log_file {
  std::unique_ptr<std::fstream> fstrm_;

public:
  log_file() = delete;
  ~log_file() { fstrm_->close(); }

  explicit log_file(const char* file) noexcept;

  bool open(const char* file) noexcept;

  bool is_open() const noexcept { return fstrm_->is_open(); }


  template <std::size_t SZ>
  void flush(std::array<unsigned char, SZ>& buf) {
    if (fstrm_->is_open())
      fstrm_ << buf;
    else {
      throw std::runtime_error("File is not open");
    }
  }

};


} /* logger:: */

#endif /* LOGFILE_HPP_ */
