/**
 * @file loghelper.cpp
 *
 *
 *
 */


#include "loghelper.hpp"

namespace logger {

logger::log_helper & operator<<(logger::log_helper& l, const logger::endl_&) {
  l.str_[l.pos_in_str_] = '\n';
  std::copy_n(std::begin(l.str_), ++l.pos_in_str_, std::begin(l.buf_) + l.pos_in_buf_);
  l.pos_in_buf_+= l.pos_in_str_;
  l.pos_in_str_ = 0;
  return l;
}

logger::log_helper & operator<<(logger::log_helper& l, const logger::flush_&) {
  std::copy_n(std::begin(l.str_), l.pos_in_str_, std::begin(l.buf_) + l.pos_in_buf_);
  l.pos_in_buf_+= l.pos_in_str_;
  l.pos_in_str_ = 0;
  return l;
}

} /* logger:: */
