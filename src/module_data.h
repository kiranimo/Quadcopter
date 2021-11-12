#ifndef MODULE_DATA_H 
#define MODULE_DATA_H 

#include <vector>
#include <iostream>
#include <mutex>
#include <memory>
#include <variant>
#include <any>
#include <map>
#include <typeinfo>
#include "base_module_data.h"

// Container for module specific data. This gets is meant to get filled in
// when the modules are initializing.
class ModuleDataCollection {
  public:

    // setter based on module name
    // TODO: kirencaldwell - investigate if it's worth auto assigning by module data type
    // instead of by name
    void SetModuleData(BaseModuleData module_data, std::string module_name) {
      std::lock_guard<std::mutex> g(mut);
      _data[module_name] = module_data;
    };

    // getter, user must match the template type with the type 
    // with that key
    BaseModuleData GetModuleData(std::string module_name) {
      std::lock_guard<std::mutex> g(mut);
      return _data[module_name];
    };

    // add new module data to container
    void AddModuleData(BaseModuleData module_data, std::string module_name) {
      std::lock_guard<std::mutex> g(mut);
      _data[module_name] = module_data;
    };

  private:
    // mutex for locking data when reading/writing
    std::mutex mut;

    // container for module data
    std::map<std::string, BaseModuleData> _data;    
};



#endif
