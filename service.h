#pragma once

#include "time.h"

class Service{
public:
  enum Company {
    kPosh,
    kGrotty
  };

  Time GetDuration() const;
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