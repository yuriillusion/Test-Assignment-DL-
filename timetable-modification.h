#pragma once

#include "timetable.h"

Timetable ReadInitialTable(std::istream& in, int capacity=0);
std::vector<Timetable> ProduceModifiedTimetables(const Timetable& initial_timetable);
void DistributeService(Service& service, Timetable& posh_timetable, Timetable& grotty_timetable);
void WriteModifiedTables(std::ostream& out, const std::vector<Timetable>& timetables);