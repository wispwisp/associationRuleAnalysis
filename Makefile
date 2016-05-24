NAME:=associationRuleAnalysis
TEST:=tests

CPP:=g++
INCLUDE_DIR:=-I.
CFLAGS:=$(INCLUDE_DIR) -std=c++11 -Wall -Wextra -Wshadow -pedantic -O3
LIBS:=-lboost_system

SOURCE:=Options/Options.cpp Data/Data.cpp Rules/Rules.cpp
TEST_SOURCE=Options/tests.cpp Data/tests.cpp Rules/tests.cpp

.PHONY: all clean

all: $(NAME) $(TEST)

$(NAME): main.cpp $(SOURCE)
	$(CPP) $(CFLAGS) -o $@ $^ $(LIBS)

$(TEST): test.cpp $(TEST_SOURCE) $(SOURCE)
	$(CPP) $(CFLAGS) -o $@ $^ $(LIBS) -lboost_unit_test_framework

clean:
	rm -f $(NAME) $(TEST) *.o *~
