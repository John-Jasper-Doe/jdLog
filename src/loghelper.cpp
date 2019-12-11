/**
 * @file loghelper.cpp
 *
 *
 *
 */


#include "loghelper.hpp"

namespace jdlog {

jdlog::log_helper & operator<<(jdlog::log_helper& l, const jdlog::endl_&) {
  l.str_[l.pos_in_str_] = '\n';
  std::copy_n(std::begin(l.str_), ++l.pos_in_str_, std::begin(l.buf_) + l.pos_in_buf_);
  l.pos_in_buf_+= l.pos_in_str_;
  l.pos_in_str_ = 0;
  return l;
}

jdlog::log_helper & operator<<(jdlog::log_helper& l, const jdlog::flush_&) {
  std::copy_n(std::begin(l.str_), l.pos_in_str_, std::begin(l.buf_) + l.pos_in_buf_);
  l.pos_in_buf_+= l.pos_in_str_;
  l.pos_in_str_ = 0;
  return l;
}

} /* logger:: */
