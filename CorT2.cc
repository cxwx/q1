// cspell:disable
#include "CorT2.hh"
#include <cmath>
#include <iostream>
using namespace std;

double CorT2::t0() const {
  const double lightspeed = 2.99792458e10;  // [cm/s]
  const double observationlevels = geti(47);
  return ((first_intr_p() - observationlevels) / (lightspeed * cos(theta())) * 1e9);  // [ns]
}

ostream& operator<<(ostream& out, const CorT2& tmp) {
  out << static_cast<int>(tmp.evno()) << " " << static_cast<int>(tmp.id()) << " " << tmp.e0() << " " << tmp.theta() << " " << tmp.phi() << " " << tmp.first_intr_p() << " ";
  return out;
}
