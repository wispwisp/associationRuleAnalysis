#include "Data.hpp"

#include <stdexcept>
#include <string>

namespace Tools {
  Data::BitsType getBitsFromString(const std::string& buf) {

    Data::BitsType bits(buf.size());
    for (size_t i = 0; i < buf.size(); ++i) {
      if (buf[i] == '0')
	bits[i] = 0;
      else if (buf[i] == '1')
	bits[i] = 1;
      else
	throw std::logic_error("Wrong data");
    }

    return bits;
  }
}

Data Data::parseUniqueDataFromStream(std::istream& stream) {

  std::string buf;
  Data data;

  // I. get first line
  if (not (stream >> buf))
    throw std::logic_error("Error reading stream");

  data.sizeOfDimension = buf.size();
  data.numOfTransactions = 0;

  // increment occurrence of transaction`s elements
  data.data[Tools::getBitsFromString(buf)]++;
  data.numOfTransactions++;

  // II. process rest of the file content:
  while (stream >> buf) {
    if (data.sizeOfDimension != buf.size())
      throw std::logic_error("Data inconsistent");

    data.data[Tools::getBitsFromString(buf)]++;
    data.numOfTransactions++;
  }

  return data;
}
