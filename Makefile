CXX = g++
CXXFLAGS = -std=c++17 -pthread -Wall -Wextra -Iinclude
SRCS = src/main.cpp src/file_traverser.cpp src/search_worker.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = grep_mt
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
