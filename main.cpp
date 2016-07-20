#include "timetable-modification.h"
#include <fstream>

int main(int argc, char* argv[]) {
  std::ifstream in("input.txt");
  const int kCapacity = 50;
  Timetable initial_timetable = ReadInitialTable(in, kCapacity);
  in.close();
  std::vector<Timetable> modified_timetables = ProduceModifiedTimetables(initial_timetable);
  std::ofstream out("output.txt");
  WriteModifiedTables(out, modified_timetables);
  out.close();
}