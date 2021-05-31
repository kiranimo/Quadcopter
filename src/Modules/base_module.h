#ifndef BASE_MODULE_H
#define BASE_MODULE_H

#include <vector>
#include <iostream>
#include <memory>
#include "module_data_wrapper.h"

class BaseModule {
  public:
    virtual std::shared_ptr<ModuleData> Init();
    void Loop(ModuleDataWrapper* data);
    std::string _module_name;
  protected:
    virtual void Poll(ModuleDataWrapper* data);
    void CreateTimer(std::string timer_name);
    
};


#endif
