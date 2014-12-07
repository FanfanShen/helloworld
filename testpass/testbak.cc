#include <stdio.h>
#include <map>
#include <set>

using namespace std;

int calDrd(int addr);

int main() {
  printf("the reuse distance is: %d, \n", calDrd(2));
}

int calDrd(int addr) {
  int drd = 0;
  
  //first: search the same block before and counts it. If find, delete it and insert block in the end,
  //else mark it as 100 eg:{2,3,4,5,6,7}, 4 comes then {2,3,5,6,7,4}  drd is 4

    std::multimap<int, int> blocks;
    std::multimap<int, int>::iterator pIter;
    typedef std::multimap<int, int>::iterator pI;
    std::set<int> setKey;
    std::set<int>::iterator p;

    blocks.insert(pair<int, int>(1, 5));
    blocks.insert(pair<int, int>(1, 6));
    blocks.insert(pair<int, int>(1, 9));
    for(pIter=blocks.begin(); pIter !=blocks.end(); pIter++) {
      setKey.insert(pIter->first);
      printf("first %d, secend %d, setkey size %d \n", pIter->first, pIter->second, setKey.size());
    }

    pair<pI, pI> pos = blocks.equal_range(1);
    while(pos.first != pos.second) {
      printf("pfirst %d,value %d \n", pos.second->first, pos.first->second);
      ++pos.first;
    }
    return 0;


  return drd;
}
