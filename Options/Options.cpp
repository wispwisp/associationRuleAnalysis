#include "Options.hpp"

#include <stdexcept>

namespace { // constants
  std::string g_sortTypeKey = "-s";
  std::string g_numberOfRulesKey = "-n";
}

namespace Tools {
  std::string createUsageString(const char* executableName = "./programm") {
    std::string message{ "Usage: " };
    message += executableName;
    message += " <file name> <threshold> [sort-type] [number of rules to show]";
    return message;
  }
}

Options::Options(int argc, char** argv) {

  // argv[1]:file name, argv[2]: threshold.
  if (argc < 3) {
    throw std::logic_error(Tools::createUsageString(argv[0]).c_str());
  }

  // todo: check is correct file name
  fileName = argv[1];

  // todo: check is correct to be converted to double
  threshold = std::stod(argv[2]);

  for (int i=3; i < argc; ++i) {
    if (argv[i] == g_sortTypeKey)
      ;
    else if (argv[i] == g_numberOfRulesKey)
      ;
    else {
      std::string message{ "Unknown argument \"" };
      message += argv[i];
      message += "\". " + Tools::createUsageString(argv[0]);

      throw std::logic_error(message.c_str());
    }
  }
}
