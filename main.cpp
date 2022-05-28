//#include "hdr.hpp"

#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>

// QoL //
template <typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& v) {
    for(auto e: v){
        os<<e;
        if (v.back() != e) {os<<", ";}
    }
    return os;
}
// END QoL //

std::map<char, std::string> argm {
  {'d', "set home directory"},
  {'h', "print this message"},
  {'m', "set max message count"},
  {'f', "provide regex filter for incoming messages"}
};

int main(int argc_, char* argv_[]) {
  int argc = argc_-1;
  std::vector<std::string> argv; // TODO: this should be an array w/ size of argc_-1
  argv.resize(argc);
  for (int i=1; i<argc+1; i++) {
    argv.at(i-1) = std::string(argv_[i]);
  }
  // create iop //

  try {
    // arg parse //
    if (argc < 1) {
      std::cout << "[?] defaulting to " << std::filesystem::current_path() << " as home directory [Y/n] ";
      std::string c/**onsent*/; std::getline(std::cin, c);
      if (!((c == "y" || c == "Y") || c.empty())) {throw "No home directory specified";}  
    } else {
      for (int i=0; i < argc; i++) {
        auto j = argv.at(i);
        bool flag = !((i)%2); 
        if (j[0] == '-' && !flag) {throw "Out of place flag on arg # "+i;}
        if (flag) {
          int idx = (j[1] == '-') ? 2 : 1;
          char f = std::string(j).substr(idx, idx+1).c_str()[0];
          if (!argm.contains(f)) {throw std::string("Unknown flag: "+std::string(1, f)).c_str();}
          switch(f) {
            case 'h':
              for (auto& [k, v]: argm) {
                std::cout << "-"<< k << " | " << v << '\n';
              }
              break;
            default:
              /** what */
              break;
          }
        } else {continue;}      
      }
    }
    // run iop //

  } catch (const char* intentional) {
    std::cout << "[!] " << intentional << '\n';
    return -1;
  } catch (const std::exception& unintentional) {
    std::cout << "[!!!] " << unintentional.what() << '\n';
    return -1;
  }
  return 0;
}
