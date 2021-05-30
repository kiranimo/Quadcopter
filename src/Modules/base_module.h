#ifndef BASE_MODULE_H
#define BASE_MODULE_H

#include <vector>
#include <iostream>
#include "share_module_data.h"

class BaseModule {
  public:
    BaseModule();
    BaseModule(std::string module_name);
    virtual void Init();
    void Loop(ShareModuleData* data);
  protected:
    virtual void Poll(ShareModuleData* data);
    void CreateTimer(std::string timer_name);
    
    std::string _module_name;
};


#endif
