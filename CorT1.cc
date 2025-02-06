// cspell:disable
#include "CorT1.hh"
#include <cstring>
#include <iostream>
using namespace std;

CorT1::CorT1() : fLia() {}
void CorT1::read(float* lia, int n) {  // flawfinder: ignore
  std::memcpy(fLia, lia, 312);         // flawfinder: ignore NOLINT
}
CorT1::~CorT1() = default;

CorT1::CorT1(CorT1&& a) noexcept {  // NOLINT
  std::memcpy(fLia, a.fLia, sizeof(fLia));  // flawfinder: ignore NOLINT
}

CorT1::CorT1(const CorT1& a) {  // NOLINT
  std::memcpy(fLia, a.fLia, sizeof(fLia));  // flawfinder: ignore  //NOLINT
}
CorT1& CorT1::operator=(const CorT1& a) {  // NOLINT
  std::memcpy(fLia, a.fLia, sizeof(fLia));  // flawfinder: ignore  NOLINT
  return *this;
}
CorT1& CorT1::operator=(CorT1&& a) noexcept {
  std::memcpy(fLia, a.fLia, sizeof(fLia));  // flawfinder: ignore NOLINT
  return *this;
}

void CorT1::read(istream& fin, int n) {          // flawfinder: ignore
  fin.read(reinterpret_cast<char*>(fLia), n * 3);  // flawfinder: ignore  NOLINT
}

void CorT1::clear() {
  const int size = sizeof(fLia);
  std::memset(fLia, 0, size);  // flawfinder: ignore NOLINT
}

void CorT1::write(ostream& out, int n) {
  out.write(reinterpret_cast<char*>(fLia), n * 3);  // flawfinder: ignore  NOLINT
}

void CorT1::print_nothin(std::ostream& out) {
  out << "-----------------\n";
  for (int i = 0; i < 39; i++) {
    for (int j = 0; j < 7; j++) {
      out << fLia[i * 7 + j] << " ";  // flawfinder: ignore  NOLINT
    }
    out << "\n";
  }
}

bool operator==(CorT1& b1, CorT1& b2) {  // NOLINT
  for (int i = 0; i < 273; i++) {
    if (b1.fLia[i] != b2.fLia[i])  // NOLINT
      return false;
  }
  return true;
}

void copy(CorT1& to, const CorT1& from) {  // NOLINT
  const int size = sizeof(float);
  std::memcpy(to.fLia, from.fLia, size);  // flawfinder: ignore NOLINT
}
