#pragma once
#include "header.h"
#include "under.hpp"

class Forward {
public:
  Underlying _under;
};

class Option {
public:
  int a;
  int b;
};

class European : public Option {
public:
  int d();
};
