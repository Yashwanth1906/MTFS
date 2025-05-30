#include "file_traverser.h"
#include <filesystem>
#include <iostream>
namespace fs = filesystem;

void traverse_directory(string &rootdir, queue<string>& files, mutex& mtx) {
  try{
    for(auto& entry : fs::recursive_directory_iterator(rootdir)) {
         if (entry.is_regular_file()) {
            lock_guard<mutex> lock(mtx);
            files.push(entry.path().string());
         }
      }
   } catch(exception& e) {
      cerr<<"Error traversing directory"<<e.what()<<endl;
   }  
}
