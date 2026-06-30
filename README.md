# BUG report


* build and install dictionary first
```bash
git clone https://github.com/cxwx/q1
cd q1
mkdir build
cd build
cmake ../ -CMAKE_INSTALL_PREFIX={where u like to install}
make install
```

* then run

```bash
root p1.cpp
```

```log
╰─ root p1.cpp
Info in <info>: ROOT: Rint, ver: 6.41.01,
build time: 20260520 1332, tversion 0
𝒞𝒳:  0 >->
Processing p1.cpp...
In file included from libtestIO dictionary payload:9:
/Users/cx/software/q1/CorT2.hh:6:22: error: base class has incomplete type
class CorT2 : public CorT1 {
              ~~~~~~~^~~~~
libtestIO dictionary forward declarations' payload:7:113: note: forward declaration of 'CorT1'
class  __attribute__((annotate("$clingAutoload$/Users/cx/software/q1/CorT1.hh")))  CorT1;
                                                                                                                ^
In file included from libtestIO dictionary payload:9:
/Users/cx/software/q1/CorT2.hh:10:3: error: only virtual member functions can be marked 'override'
```
