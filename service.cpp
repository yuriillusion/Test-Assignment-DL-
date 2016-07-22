#include "service.h"

Time Service::GetDuration() const {
  int hour_difference = arrival_time_.hours() - departure_time_.hours();
  int minute_difference = arrival_time_.minutes() - departure_time_.minutes();
  if (minute_difference < 0) {
    minute_difference += Time::kMinuteBase;
    hour_difference -= 1;
  }
  if (IsNightService()) {
    hour_difference += Time::kHourBase;
  }
  return Time(hour_difference, minute_difference);
}

bool Service::IsNightService() const {
  return is_night_service_;
}

bool Service::Contains(const Service& service) const {
  const bool is_night1 = IsNightService();
  const bool is_night2 = service.IsNightService();
  if (is_night1 && is_night2 || !is_night1 && !is_night2) {
    return departure_time_ <= service.departure_time_ &&
      arrival_time_ >= service.arrival_time_;
  } else if (is_night1) {
    return departure_time_ <= service.departure_time_ &&
      service.arrival_time_ < Time(Time::kHourBase, 0U) ||
      service.departure_time_ >= Time(0U, 0U) &&
      service.arrival_time_ <= arrival_time_;
  } else {
    return false;
  }
}

Service::Company Service::company() const {
  return company_;
}

std::istream& operator>>(std::istream& in, Service& service) {
  std::string company_name;
  in >> company_name;
  if (company_name == "Posh") {
    service.company_ = Service::kPosh;
  } else {
    service.company_ = Service::kGrotty;
  }
  in >> service.departure_time_ >> service.arrival_time_;
  service.is_night_service_ = (service.arrival_time_ < service.departure_time_);
  return in;
}

std::ostream& operator<<(std::ostream& out, const Service& service) {
  std::string company_name;
  if (service.company_ == Service::kPosh) {
    company_name = "Posh";
  } else {
    company_name = "Grotty";
  }
  out << company_name << ' ' << service.departure_time_ << ' ' <<
    service.arrival_time_;
  return out;
}

bool operator<(const Service& service1, const Service& service2) {
  if (service2.Contains(service1)) {
    if (service1.arrival_time_ == service2.arrival_time_ &&
      service1.departure_time_ == service2.departure_time_) {
      return service1.company_ == Service::kPosh;
    }
    return true;
  }
  else if (service1.Contains(service2)) {
    return false;
  }
  else {
    return service1.departure_time_ < service2.departure_time_;
  }

}