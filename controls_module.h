#ifndef CONTROLS_MODULE_H
#define CONTROLS_MODULE_H

#include <iostream>
#include <memory>
#include "src/base_module.h"

class ControlsModule : public BaseModule {
  public:
    ControlsModule();

  private:
    void Poll(std::shared_ptr<ModuleDataCollection> data) override;
    
};

#endif
