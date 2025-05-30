#pragma once

#include <string>
#include <queue>
#include <mutex>
#include <regex>
#include <thread>
using namespace std;

void search_worker(queue<string>& files, mutex& mtx, regex& pattern);
