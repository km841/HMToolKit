#pragma once

#define HM_STANDARD_NEW_BODY(thisClass)                                                           \
  auto result = new thisClass;                                                                     \
  result->InitializeObjectBase();                                                                  \
  return result

#define hmStandardNewMacro(thisClass)                                                             \
  thisClass* thisClass::New()                                                                      \
  {                                                                                                \
    HM_STANDARD_NEW_BODY(thisClass);                                                              \
  }