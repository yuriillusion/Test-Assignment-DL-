#pragma once

#include "time.h"

class Service{
public:
  enum Company {
    kPosh,
    kGrotty
  };

  Time GetDuration() const;
  // Returns true if a bus corresponding to *this departs before and comes
  // later than the bus corresponding to a service.
  bool Contains(const Service& service) const;
  Company company() const;

  friend std::istream& operator>>(std::istream& in, Service& service);
  friend std::ostream& operator<<(std::ostream& out, const Service& service);
  friend bool operator<(const Service& service1, const Service& service2);

private:
  Company company_;
  Time departure_time_;
  Time arrival_time_;
};