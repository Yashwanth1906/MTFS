#include "search_worker.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <string>
#include <queue>
#include <mutex>
#include <regex>
#include <thread>

void search_worker(queue<string>& files, mutex& mtx, regex& pattern) {
   while(true) {
      string filename;
      {
         lock_guard<mutex> lock(mtx);
         if(files.empty()) return;
         filename = files.front();
         files.pop();
      }

      ifstream file(filename);
      if(!file.is_open()) {
         cerr<<"Failed to open file : "<<filename<<endl;
         continue;
      }

      string line;
      int line_num = 0;
      while(getline(file, line)) {
         line_num++;
         if(regex_search(line, pattern)) {
            lock_guard<mutex> lock(mtx);
            cout<<filename<<" : "<<line_num<<" : "<<line<<endl;
         }
      }
   }
}
