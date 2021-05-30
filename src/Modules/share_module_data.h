#ifndef SHARE_MODULE_DATA_H 
#define SHARE_MODULE_DATA_H 

#include <vector>
#include <iostream>
#include <mutex>

class ModuleData {
  public:
    std::string name;
    int ctr;
};

class ShareModuleData {
  public: 
    ShareModuleData();
    int GetCtr();
    void SetCtr(int val);
    
    void AddModuleData(std::vector<ModuleData*> module_data);
    ModuleData GetModuleData(std::string module_name);
    void SetModuleData(ModuleData* module_data, std::string module_name); 
  private:
    int _ctr;
    std::vector<ModuleData*> _module_data;
    std::mutex _m;
};

#endif
