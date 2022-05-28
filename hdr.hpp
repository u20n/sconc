#include <core/tree.hpp>
#include <core/node.hpp>


#include <vector>
#include <string>

struct iopress {
private:
  std::string home_dir;
  std::vector<Node> nodes;


public:

  void run() {
    
  }
  iopress(std::string home_dir_) : home_dir(home_dir_) {

  }

  struct _p : public Protocol {
  
  } proto;
};
