#include <stdio.h>
#include <map>
#include <set>

using namespace std;

std::multimap<int, int> blocks;
int calDrd(int addr);
bool cmp(int a, int b);

int main() {
  printf("the reuse distance is: %d, \n", calDrd(3));
  printf("the reuse distance is: %d, \n", calDrd(2));
  printf("the reuse distance is: %d, \n", calDrd(4));
  printf("the reuse distance is: %d, \n", calDrd(5));
  printf("the reuse distance is: %d, \n", calDrd(2));
  printf("the reuse distance is: %d, \n", calDrd(8));
  printf("the reuse distance is: %d, \n", calDrd(5));
  printf("the reuse distance is: %d, \n", calDrd(4));
}

int calDrd(int addr) {
  int drd = 0;
  
  //first: search the same block before and counts it. If find, delete it and insert block in the end,
  //else mark it as 100 eg:{2,3,4,5,6,7}, 4 comes then {2,3,5,6,7,4}  drd is 4

    std::multimap<int, int>::iterator pIter;
    typedef std::multimap<int, int>::iterator pI;
    std::set<int> setKey;
    std::set<int>::iterator p;
    int counter = 0;   

    // search block according to specific set
    pair<pI, pI> pos = blocks.equal_range(1);
    while(pos.first != pos.second) {
      if(cmp(addr, pos.second->second)) {
//        counter++;
        blocks.erase(pos.second);
        break;
      } else {
        counter++;
      }
      printf("pfirst %d,value %d \n", pos.second->first, pos.second->second);
      --pos.second;
    }
    if(pos.first == pos.second) {counter = 100;}
    blocks.insert(pair<int, int>(1, addr));
    for(pIter=blocks.begin(); pIter !=blocks.end(); pIter++) {
      setKey.insert(pIter->first);
      printf("first %d, secend %d, setkey size %d \n", pIter->first, pIter->second, setKey.size());
    }
  drd = counter;
  return drd;
}

bool cmp(int a, int b) {
  if(a == b) {
    return true;
  }
  return false;
}
