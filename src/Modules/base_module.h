#ifndef BASE_MODULE_H
#define BASE_MODULE_H

#include <vector>
#include <iostream>
#include <mutex>

class ModuleData {

};

class ShareModuleData {
  public: 
    ShareModuleData();
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
    void Loop(ShareModuleData* data);
  private:
    virtual void Poll(ShareModuleData* data);
    void CreateTimer(std::string timer_name);
    
    std::string _module_name;
};

#endif
