#ifndef BASE_MODULE_H
#define BASE_MODULE_H

#include <vector>
#include <iostream>

class BaseModule {
  public:
    BaseModule();
    BaseModule(std::string module_name);
    virtual void Init();
    void Loop();
  private:
    virtual void Poll();
    void CreateTimer(std::string timer_name);
    
    std::string _module_name;
};

#endif
