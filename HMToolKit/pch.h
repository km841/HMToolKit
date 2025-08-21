#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <atomic>
#include <algorithm>
#include <ostream>
#include <sstream>
#include "hmGetSet.h"

using hmTypeBool = int;
using hmIdType = long long;
using hmMTimeType = unsigned long long;

#if defined(__cplusplus)
#define HM_TYPE_CAST(T, V) static_cast<T>(V)
#else
#define HM_TYPE_CAST(T, V) ((T)(V))
#endif

