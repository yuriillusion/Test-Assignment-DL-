#include "timetable-modification.h"

Timetable ReadInitialTable(std::istream& in, int capacity) {
  Timetable initial_timetable(capacity);
  in >> initial_timetable;
  return initial_timetable;
}

std::vector<Timetable> ProduceModifiedTimetables(const Timetable& initial_timetable) {
  Timetable sorted_timetable = initial_timetable.Sort();
  const std::vector<Service> sorted_table = sorted_timetable.table();
  Timetable posh_timetable, grotty_timetable;
  const int kTableSize = sorted_table.size();
  const Time kMaxTime = Time(1, 0);

  int last_index = kTableSize;

  Service current_service;
  for (int i = 0; i < kTableSize; i++) {
    current_service = sorted_table[i];
    if (current_service.GetDuration() <= kMaxTime) {
      DistributeService(current_service, posh_timetable, grotty_timetable);
      last_index = i;
      break;
    }
  }

  Service last_service = sorted_table[last_index];
  for (int i = last_index + 1; i < kTableSize; i++) {
    Service current_service = sorted_table[i];
    if (!current_service.Contains(last_service) && current_service.GetDuration() <= kMaxTime) {
      DistributeService(current_service, posh_timetable, grotty_timetable);
      last_service = current_service;
    }
  }
  return{ posh_timetable, grotty_timetable };
}

void DistributeService(Service& service, Timetable& posh_timetable, Timetable& grotty_timetable) {
  switch (service.company()) {
    case Service::kPosh: {
      posh_timetable.Push(service);
      break;
    }
    case Service::kGrotty: {
      grotty_timetable.Push(service);
      break;
    }
  }
}

void WriteModifiedTables(std::ostream& out, const std::vector<Timetable>& timetables) {
  for (int i = 0; i < timetables.size(); i++) {
    out << timetables[i] << std::endl;
  }
}