/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CorT1.hh                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenxu <chenxu@mail.ustc.edu.cn>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 19:12:47 by chenxu            #+#    #+#             */
/*   Updated: 2024/05/12 18:30:28 by chenxu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// cspell:disable
#ifndef CORSIKASUBBLOCK_HH_
#define CORSIKASUBBLOCK_HH_

#include <TObject.h>
#include <iostream>
#include <string>
class CorT1 : public TObject {
 protected:
  float fLia[312];  // NOLINT

 public:
  inline float* getLia() { return fLia; }  // NOLINT
  CorT1();
  ~CorT1() override;
  CorT1(const CorT1&);
  CorT1(CorT1&&) noexcept;  // TODO(chenxu): &&
  CorT1& operator=(const CorT1&);
  CorT1& operator=(CorT1&&) noexcept;

  void read(float* lia, int n);      // flawfinder: ignore
  void read(std::istream&, int n);   // flawfinder: ignore
  void write(std::ostream&, int n);  // flawfinder: ignore
  inline void set(float* lia) {
    const int size = sizeof(this->fLia);
    std::memcpy(this->fLia, lia, size);  // flawfinder: ignore NOLINT
  }
  inline void get(float* lia) const {
    const int size = sizeof(this->fLia);
    std::memcpy(lia, this->fLia, size);  // flawfinder: ignore NOLINT
  }

  [[nodiscard]] inline float geti(const int& i) const { return fLia[i]; }  // NOLINT
  [[nodiscard]] inline auto getType() const { return std::string(reinterpret_cast<const char*>(&fLia[0])); }

  void clear();
  virtual void read(float* lia) = 0;  // flawfinder: ignore

  virtual void read(std::istream&) = 0;   // flawfinder: ignore
  virtual void write(std::ostream&) = 0;  // flawfinder: ignore

  void print_nothin(std::ostream& out = std::cout);
  inline void read_nothin(float* lia) { read(lia, 273); }           // flawfinder: ignore
  inline void read_thin(float* lia) { read(lia, 312); }               // flawfinder: ignore
  inline void read_nothin(std::istream& in) { read(in, 312); }      // flawfinder: ignore
  inline void read_thin(std::istream& in) { read(in, 312); }          // flawfinder: ignore
  inline void write_nothin(std::ostream& out) { write(out, 312); }  // flawfinder: ignore
  inline void write_thin(std::ostream& out) { write(out, 312); }      // flawfinder: ignore

  friend bool operator==(CorT1&, CorT1&);
  friend void copy(CorT1& to, const CorT1& from);  // NOLINT
  ClassDefOverride(CorT1, 1)  // NOLINT
};

void copy(CorT1& to, const CorT1& from);  // NOLINT
bool operator==(CorT1&, CorT1&);

#endif  // CORSIKASUBBLOCK_HH_
