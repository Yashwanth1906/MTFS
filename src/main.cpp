#include <iostream>
#include "file_traverser.h"
#include "search_worker.h"
#include <queue>
#include <string>
#include <vector>
#include <mutex>
#include <thread>
using namespace std;

int main() {
   string pattern_str , directory;
   cout<<"Enter the pattern you need to search for: ";
   cin>>pattern_str;
   cout<<"Enter the directory that you need to search in: ";
   cin>>directory;
   regex pattern;
   try {
      pattern = regex(pattern_str);
   } catch(regex_error &e) {
      cerr<<"Invalid regex pattern "<<e.what()<<endl;
      return 1;
   }

   queue<string> q;
   mutex mtx;
   thread traverser(traverse_directory, directory, ref(q), ref(mtx));
   traverser.join();
   int no_of_threads = 4;
   vector<thread> workers;
   for(int i = 0; i < no_of_threads;i++) {
      workers.emplace_back(search_worker, ref(q), ref(mtx), ref(pattern));
   }
   for(auto& it : workers) {
      it.join();
   }
   return 0;
}

