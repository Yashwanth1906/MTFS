CXX = g++
CXXFLAGS = -std=c++17 -pthread -Wall -Wextra

SRCS = src/main.cpp src/file_traverser.cpp src/search_worker.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = grep_mt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)

