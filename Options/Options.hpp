#ifndef MY_OPTIONS
#define MY_OPTIONS

#include <string>

class Options {
  std::string fileName;
  double threshold;
public:
  Options(int argc, char** argv);

  const std::string& getFileName() const noexcept { return fileName; }
  double getThreshold() const noexcept { return threshold; }
};

#endif // MY_OPTIONS
