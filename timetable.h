#pragma once

#include <vector>
#include "service.h"

class Timetable {
public:
  explicit Timetable(int capacity=0);
  Timetable(const Timetable& timetable);

  Timetable Sort() const;
  void Push(Service service);
  const std::vector<Service>& table() const;

  friend std::istream& operator>>(std::istream& in, Timetable& timetable);
  friend std::ostream& operator<<(std::ostream& out, const Timetable& timetable);

private:
  std::vector<Service> table_;
};