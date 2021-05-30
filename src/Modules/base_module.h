#ifndef BASE_MODULE_H
#define BASE_MODULE_H

#include <vector>
#include <iostream>
#include <mutex>

class ModuleData {
  public: 
    ModuleData();
    int GetCtr();
    void SetCtr(int val);

  private:
    int _ctr;
    std::mutex _m;
};


class BaseModule {
  public:
    BaseModule();
    BaseModule(std::string module_name);
    virtual void Init();
    void Loop(ModuleData* data);
  private:
    virtual void Poll(ModuleData* data);
    void CreateTimer(std::string timer_name);
    
    std::string _module_name;
};

#endif
