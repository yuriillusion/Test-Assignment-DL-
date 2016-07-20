#pragma once

#include <string>

class Time {
public:
  static const unsigned kHourBase = 24;
  static const unsigned kMinuteBase = 60;

  Time(const unsigned hours=0, const unsigned minutes=0);

  void set_hours(const unsigned& hours);
  void set_minutes(const unsigned& minutes);
  unsigned hours() const;
  unsigned minutes() const;

  friend std::istream& operator>>(std::istream& in, Time& time);
  friend std::ostream& operator<<(std::ostream& out, const Time& time);
  friend bool operator<(const Time& time1, const Time& time2);
  friend bool operator<=(const Time& time1, const Time& time2);
  friend bool operator>=(const Time& time1, const Time& time2);
  friend bool operator==(const Time& time1, const Time& time2);

private:
  unsigned hours_;
  unsigned minutes_;
};