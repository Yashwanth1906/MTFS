#pragma once

#include <string>
#include <queue>
#include <mutex>
using namespace std;
void traverse_directory(string& rootdir, queue<string>& files, mutex &mtx);
