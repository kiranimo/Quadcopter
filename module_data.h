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

    // setter based on module name
    // TODO: kirencaldwell - investigate if it's worth auto assigning by module data type
    // instead of by name
    void SetModuleData(std::any module_data, std::string module_name) {
      _all_data[module_name] = module_data;
    };

    // getter, user must match the template type with the type 
    // with that key
    template <class T>
    T GetModuleData(std::string module_name) {
      T out;
      // for some reason this was erroring, so wrapped it in a try-catch
      try {
        out = std::any_cast<T>(_all_data[module_name]);
      }
      catch(const std::bad_any_cast &e) {
        std::cout << e.what() << "\n" << std::endl;
      }
      // return whatever we have
      // TODO: kirencaldwell - inform the user that their data is bad
      return out;
    };

    // add new module data to container
    void AddModuleData(std::any module_data, std::string module_name) {
      _all_data[module_name] = module_data;
    };

  private:
    // container for module data
    std::map<std::string, std::any> _all_data;    
};


#endif
