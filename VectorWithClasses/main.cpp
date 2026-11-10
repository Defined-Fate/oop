#include <cstdint>
#include <iostream>
class MyVector {
public:
  MyVector(uint64_t size = 0, int value = 0){
    v_size = size;
    v_capacity = ((calc_capacity(size) > 8) ? : v_capacity);
    array = new int[v_capacity];

    for(int i = 0; i < v_capacity; i++){
      array[i] = value;
    }
  }

  void pushBack(int n){
    if(v_size + 1 > v_capacity) {
      v_capacity *= 2;
      int *temparray;
      temparray = array;
      array = new int[v_capacity];
      for(int i = 0; i < v_size; i++){
        array[i] = temparray[i];
      }
      delete[] temparray;
    }
    array[v_size] = n;
    v_size++;
  }
  
  void popBack(){
    std::cout << array[v_size-1] << '\n';
    v_size--;
  }

  void at(uint64_t n){
    if(n < v_size){
      std::cout << "Out of scope" << '\n'; 
    }
  }

  void print(){
    std::cout << "C: " << v_capacity << ", " << "S: " << v_size << '\n' << "[";
    for(int i = 0; i < v_size; i++){
      std::cout << " " << array[i];
    }
    std::cout << " ]" << '\n';
  }
private:
  int calc_capacity(uint64_t size) {
    uint64_t myC = 2;
    while(size > myC) myC <<= 1;

    return myC;
  }
  uint64_t v_size;
  uint64_t v_capacity;
  int *array;
};

int main (int argc, char *argv[]) {
  return 0;
}
