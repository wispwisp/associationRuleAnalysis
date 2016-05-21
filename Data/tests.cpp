#include "Data.hpp"

#include <sstream>
#include <stdexcept>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TestDataClass)

BOOST_AUTO_TEST_CASE(inconsistentDataLenghPerLine)
{
  std::string s = 
    "010101\n"
    "0101001"; // <-- one more element

  std::stringstream bitsString{ s };
  BOOST_CHECK_THROW(Data::parseDataFromStream(bitsString), std::logic_error);
}

BOOST_AUTO_TEST_CASE(emptyData)
{
  std::string s = "";
  std::stringstream bitsString{ s };

  BOOST_CHECK_THROW(Data::parseDataFromStream(bitsString), std::logic_error);
}

BOOST_AUTO_TEST_CASE(wrongData)
{
  std::string s =
    "010101\n"
    "0l0101\n"// <-- 'l' instead of '1'
    "110100\n";

  std::stringstream bitsString{ s };
  BOOST_CHECK_THROW(Data::parseDataFromStream(bitsString), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END()

