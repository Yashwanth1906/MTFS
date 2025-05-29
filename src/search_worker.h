#pragma once
#include <string>
#include <queue>
#include <mutex>
#include <regex>

void search_worker(queue<string>& files, mutex& mtx, regex& pattern);
