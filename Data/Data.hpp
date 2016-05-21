#ifndef MY_DATA
#define MY_DATA

#include <vector>
#include <istream>
#include <unordered_map>

using BitsType = std::vector<bool>;
using DataType = std::unordered_map<BitsType, size_t>;

class Data {
  DataType data;
public:
  const DataType& get() const noexcept { return data; }
  static Data parseUniqueDataFromStream(std::istream&);
};

#endif // MY_DATA
