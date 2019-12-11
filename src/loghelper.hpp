/**
 * @file loghelper.hpp
 *
 *
 *
 */




#ifndef LOGHELPER_H_
#define LOGHELPER_H_


#include <array>
#include <algorithm>


namespace jdlog {


constexpr std::size_t buff_size = 1048576; /* 1 MB */
constexpr std::size_t str_size = 2048;  /* 2 kB */


namespace detail {

class endl_ {};
class flush_ {};

} /* detail:: */

using endl_ = detail::endl_;
using flush_ = detail::flush_;

[[maybe_unused]]static endl_ endl;
[[maybe_unused]]static flush_ flush;



class log_helper {

  std::array<unsigned char, buff_size> buf_;
  std::array<unsigned char, str_size> str_;

  std::size_t pos_in_str_{0};
  std::size_t pos_in_buf_{0};

public:
  log_helper() = default;
  ~log_helper() = default;

  log_helper(const log_helper&) = delete;
  log_helper(log_helper&&) = delete;
  log_helper& operator=(const log_helper&) = delete;
  log_helper& operator=(log_helper&&) = delete;

  template <typename T>
  friend jdlog::log_helper & operator<<(jdlog::log_helper& l, const T& v);
  friend jdlog::log_helper & operator<<(jdlog::log_helper& l, const jdlog::endl_&);
  friend jdlog::log_helper & operator<<(jdlog::log_helper& l, const jdlog::flush_&);
};


template <typename T>
jdlog::log_helper & operator<<(jdlog::log_helper& l, const T& v) {
  if constexpr (std::is_integral_v<T> || std::is_floating_point_v<T>) {
    std::string s_num = std::to_string(v);
    std::copy(std::begin(s_num), std::end(s_num), std::begin(l.str_) + l.pos_in_str_);
    l.pos_in_str_ += s_num.size();
  }
  else {
    std::copy(std::begin(v), std::end(v), std::begin(l.str_) + l.pos_in_str_);
    if constexpr (std::is_same_v<T, std::string>) {
      l.pos_in_str_ += std::size(v);
    }
    else {
      l.pos_in_str_ += (std::size(v) - 1);
    }
  }
  return l;
}

} /* logger:: */

#endif /* LOGHELPER_H_ */
