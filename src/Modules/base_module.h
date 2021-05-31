#ifndef BASE_MODULE_H
#define BASE_MODULE_H

#include <vector>
#include <iostream>
#include "module_data_wrapper.h"

class BaseModule {
  public:
    // BaseModule(std::string module_name);
    virtual void Init();
    void Loop(ModuleDataWrapper* data);
  protected:
    virtual void Poll(ModuleDataWrapper* data);
    void CreateTimer(std::string timer_name);
    
    std::string _module_name;
};


#endif
