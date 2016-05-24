#ifndef MY_DATA
#define MY_DATA

#include <vector>
#include <istream>
#include <unordered_map>

class Data {
public:
  using BitsType = std::vector<bool>;
  using DataType = std::unordered_map<BitsType, size_t>;

  const DataType& get() const noexcept { return data; }
  size_t transactionSize() const noexcept { return sizeOfDimension; }

  static Data parseUniqueDataFromStream(std::istream&);

private:
  size_t sizeOfDimension;
  DataType data;
};

#endif // MY_DATA
