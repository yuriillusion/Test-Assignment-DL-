#include "timetable.h"
#include <algorithm>

Timetable::Timetable(int capacity) {
  table_.reserve(capacity);
}

Timetable::Timetable(const Timetable& timetable) : table_(timetable.table_) {}

Timetable Timetable::Sort() const {
  Timetable sorted_timetable(*this);
  std::sort(sorted_timetable.table_.begin(), sorted_timetable.table_.end());
  return sorted_timetable;
}

void Timetable::Push(Service service) {
  table_.push_back(service);
}

const std::vector<Service>& Timetable::table() const {
  return table_;
}

std::istream& operator>>(std::istream& in, Timetable& timetable) {
  while (in.good()) {
    Service service;
    in >> service;
    timetable.table_.push_back(service);
  }
  return in;
}

std::ostream& operator<<(std::ostream& out, const Timetable& timetable) {
  const int kTableSize = timetable.table_.size();
  for (int i = 0; i < kTableSize; i++) {
    out << timetable.table_[i] << std::endl;
  }
  return out;
}