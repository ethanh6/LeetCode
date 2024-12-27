#pragma once

#include <string>
#include <iostream>

namespace utility {
  void prelog(std::string& message) {
    std::cout << std::endl;
    std::cout << "===== " << message << " =====";
    std::cout << std::endl << std::endl;
  }
}

