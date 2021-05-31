#ifndef MODULE_DATA_WRAPPER_H 
#define MODULE_DATA_WRAPPER_H 

#include <vector>
#include <iostream>
#include <mutex>
#include <memory>
#include <eigen3/Eigen/Dense>
#include <variant>

using Eigen::VectorXd;
using Eigen::MatrixXd;

class ModuleData{
    struct data_base {};
 
    template <class K> 
    struct data: data_base {
        data(const K& v): value_(v) {}
        K value_;
    };
 
    typedef std::vector<data_base*> container_type;
 
public:
    ModuleData(std::string module_name) {
      name = module_name;
    }
    ~ModuleData() {
        while(!this->VData.empty()) {
            delete this->VData.back();
            this->VData.pop_back();
        }
    }
    template <class P>
    inline void push(P v) {
        this->VData.push_back(new data<P>(v));
    }
    template <class P>
    P &get() { 
      return static_cast<data<P>*>(this->VData[0])->value_; 
    }

    std::string name;
private:
    container_type VData;
    std::vector<std::string> value_names;
};

class ModuleDataWrapper{
  public: 
    
    void AddModuleData(std::shared_ptr<ModuleData> module_data);
    ModuleData* GetModuleData(std::string module_name);
    void SetModuleData(std::shared_ptr<ModuleData> module_data, std::string module_name); 
  private:
    std::vector<std::shared_ptr<ModuleData>> _module_data;
    std::mutex _m;
};

#endif
