/**
 * @file logfile.hpp
 *
 *
 *
 */

#ifndef LOGFILE_HPP_
#define LOGFILE_HPP_

#include <fstream>
#include <functional>
#include <memory>

namespace jdlog {

class log_file {
  using fstrm_t =
      std::unique_ptr<std::fstream, std::function<void(std::fstream*)>>;

  fstrm_t fstrm_;

 public:
  log_file() = delete;
  ~log_file() = default;

  explicit log_file(std::string file) noexcept { open(file); }

  bool open(std::string& file) noexcept;

  bool is_open() const noexcept { return fstrm_->is_open(); }

  template <std::size_t SZ>
  void flush(std::array<unsigned char, SZ>& buf) {
    if (fstrm_->is_open())
      *fstrm_ << buf.data();
    else {
      throw std::runtime_error("File is not open");
    }
  }
};

} /* logger:: */

#endif /* LOGFILE_HPP_ */
