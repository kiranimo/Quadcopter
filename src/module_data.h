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

// Container for module specific data. This gets is meant to get filled in
// when the modules are initializing.
class ModuleDataCollection {
  public:
    std::mutex mut;

    // setter based on module name
    // TODO: kirencaldwell - investigate if it's worth auto assigning by module data type
    // instead of by name
    void SetModuleData(std::any module_data, std::string module_name) {
      // std::scoped_lock(data_mutex);
      std::lock_guard<std::mutex> g(mut);
      _all_data.data[module_name] = module_data;
    };

    // getter, user must match the template type with the type 
    // with that key
    template <class T>
    T GetModuleData(std::string module_name) {
      std::lock_guard<std::mutex> g(mut);
      T out = std::any_cast<T>(_all_data.data[module_name]);
      return out;
    };

    // add new module data to container
    void AddModuleData(std::any module_data, std::string module_name) {
      // std::scoped_lock(data_mutex);
      _all_data.data[module_name] = module_data;
    };

  private:
    // container for module data
    struct ModuleDataContainer {
      std::map<std::string, std::any> data;    
    } _all_data;
};



#endif
