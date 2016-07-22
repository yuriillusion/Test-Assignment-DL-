#include "time.h"
#include <iomanip>

Time::Time(const unsigned hours, const unsigned minutes)
    : hours_(hours), minutes_(minutes){}

std::ostream& operator<<(std::ostream& out, const Time& time) {
  out << std::setfill('0') << std::setw(2) << time.hours_;
  out << ':';
  out << std::setfill('0') << std::setw(2) << time.minutes_;
  return out;
}

void Time::set_hours(const unsigned& hours) {
  hours_ = hours;
}

void Time::set_minutes(const unsigned& minutes) {
  minutes_ = minutes;
}

unsigned Time::hours() const {
  return hours_;
}

unsigned Time::minutes() const {
  return minutes_;
}

std::istream& operator>>(std::istream& in, Time& time) {
  char waste_character;
  in >> time.hours_ >> waste_character >> time.minutes_;
  return in;
}

bool operator<(const Time& time1, const Time& time2){
  if (time1.hours_ < time2.hours_) {
    return true;
  } else if (time1.hours_ == time2.hours_ && time1.minutes_ < time2.minutes_) {
    return true;
  } else {
    return false;
  }
}

bool operator<=(const Time& time1, const Time& time2) {
  return !(time2 < time1);
}

bool operator>=(const Time& time1, const Time& time2) {
  return time2 <= time1;
}

bool operator==(const Time& time1, const Time& time2) {
  return time1.hours_ == time2.hours_ && time1.minutes_ == time2.minutes_;
}