#pragma once
#include <__config>
#include <bitset>
#include <iostream>
#include <fstream>
#include <ctime>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// common algorithms I use. Updated regularly
class algo {
public:
 void swap(char *a, char *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
  }
  void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
  } 

  int binarysearch(vector<int> list, int target) {
    int first = 0;
    int last = list.size() - 1;
    while (first <= last) {
      int mid = (first + last) / 2;
      if (list[mid] == target) {
        return mid;
      } else if (list[mid] < target) {
        first = mid + 1;
      } else if (list[mid] > target) {
        last = mid - 1;
      }
    }
    return 0;
  }

  string lowercase(string input) {
    for (int x = 0; x < input.size(); x++) {
      if (input[x] >= 65 && input[x] <= 90) {
        input[x] += 32;
      } else {
        continue;
      }
    }
    // end of loop
    return input;
  }


  char findchar(string &test, char target) {
    // binary search not detecting first element
    int first = 0;
    int last = test.size() - 1;
    if (test[first] == target) {
      return first;
    } else if (test[last] == target) {
      return last;
    }
    while (first <= last) {
      int mid = (first + last) / 2;
      if (test[mid] == target) {
        return mid;
      } else if (test[mid] < target) {
        first = mid + 1;
      } else if (test[mid] > target) {
        last = mid - 1;
      }
    }
    return -1;
  }

  string bubsort(string &unsorted) {
    for (int i = 0; i < unsorted.size(); i++) {
      bool swap = false;
      for (int k = 0; k < unsorted.size() - 1; k++) {
        if (unsorted[k] > unsorted[k + 1]) {
          swap = true;
          char n = unsorted[k];
          unsorted[k] = unsorted[k + 1];
          unsorted[k + 1] = n;
        } else {
          continue;
        }
      }
      if (swap == false) {
        return unsorted;
      }
    }
    return unsorted;
  };
 
  void helper(vector<int> nums, vector<vector<int> > &sol, int start, int end,
              vector<int> &subset) {
    // Given an integer array nums of unique elements, return all possible
    // subsets
    //  power set represented by putting an element in at each step or leaving
    //  it out of new set needs to use stack and recursion, with a helper
    if (start > end) {
      // if vector is empty,
      // add the empty set and end recursion
      sol.push_back(subset);
      return;
    }
    subset.push_back(nums[start]);
    helper(nums, sol, start + 1, end, subset);
    subset.pop_back();
    helper(nums, sol, start + 1, end, subset);
  }
  // main function that recursively calls helper
  vector<vector<int> > pset(vector<int> &nums_) {
    vector<vector<int> > sol;
    vector<int> subset;
    helper(nums_, sol, 0, nums_.size() - 1, subset);
    return sol;
  }

  bool check(char c1, char c2) { return c1 == c2; }

  int strStr(string haystack, string needle) {
    std::stack<char> stack;
#pragma omp parallel for
    for (int k = needle.size() - 1; k >= 0; k--) {
      // normal order check
      stack.push(needle[k]);
    }
    std::stack<char> temp = stack;
    int ch = 0;
    int size = haystack.size();
    int i = 0;
    while (stack.empty() != true && ch < size) {
      if (check(haystack[ch], stack.top())) {
        i++;
        ch++;
        stack.pop();
      } else {
        ch++;
        i = 0;
        // reset stack, match not found yet
        stack = temp;
      }
    }
    if (stack.empty()) {
      return ch - i;
    } else {
      return -1;
    }
  }

 
  vector<int> sortArray(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int k = 0; k < nums.size() - 1; k++) {
        if (nums[k] > nums[k + 1]) {
          swap(&nums[k], &nums[k + 1]);
        }
      }
    }
    return nums;
  }

  void sortStr(string &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int k = 0; k < nums.size() - 1; k++) {
        if (nums[k] > nums[k + 1]) {
          swap(&nums[k], &nums[k + 1]);
        }
      }
    }
  }



  void reversecARR(vector<char> &s) {
    // ptr swap at beginning and end;
    char *beg = &s[0];
    char *last = &s[s.size() - 1];
    for (; beg != last && last != &s[0]; beg++ && last--) {
      swap(beg, last);
    }
  }

 void reverseString(string & s) {
        // ptr swap at beginning and end;
        char *beg=&s[0];
        char *last=&s[s.size()-1];
    for (; beg < last && last != &s[0] ; beg++ && last-- ) {
            swap(beg, last);
    }
 }

  vector<bitset<8> > strbit(string &myString,  uint &max) {
      max = myString.size();
    vector<bitset<8> > ret;
    for (std::size_t i = 0; i < myString.size(); ++i) {
      ret.push_back(bitset<8>(myString[i]));
    }
    return ret;
  }

uint b2hx(vector<bitset<8> > input, uint &size){
 long int binaryval, hexadecimalval = 0, i = 1, remainder;
 int k=0;
   while (k<size){
      remainder = binaryval % 10;
      hexadecimalval = hexadecimalval + remainder * i;
      i = i * 2;
      binaryval = binaryval / 10;
      k++;
   }
   return hexadecimalval;
}


  vector<bitset<8> > encrypt(string &input, unsigned int &hx) {
    // cypher algorithm
    reverseString(input);
    char c;
    std::bitset<8> mask(INT_MAX);
    unsigned long i;
     uint max ;
    vector<bitset<8> > vect = strbit(input, max);
    for (int i = 0; i < vect.size(); i++) {
      // take one's complement
      // XOR is bijective mapping, allowing reverse-engineer of decryption string
      vect[i] = ~vect[i] ^ mask;
      vect[i] = vect[i]  << 2 | vect[i]  >> (6);

    }
    hx=b2hx(vect,max);
    return vect;
  }
  
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
 
int nearest_prime(int n) {
    int prime = 0;
    for (int i = n-1; i >= 2; i--) {
        if (is_prime(i)) {
            prime = i;
            break;
        }
    }
    return prime;
}

vector<bitset<8> > load(){
ifstream in;
in.open("./txt/in.txt");
string line;
string file;
uint hx;
while(getline(in,line)){
  file+=line+ ' ';
}
return  encrypt(file, hx);
}


void print(vector<bitset<8> > vect){
ofstream fout;
fout.open("./txt/out.txt");
for(int i=0;i<vect.size();i++){
  fout << vect[i] << endl;
}
fout.close();
}

  string decrypt(vector<bitset<8> > vect) {
    char c;
    string output;
    int x;
    std::bitset<8> mask(INT_MAX);
    #pragma omp parallel for
    for (int i = 0; i < vect.size(); i++) {
      vect[i] = ~vect[i] ^ mask;
      vect[i] = vect[i]  >> 2 | vect[i]  << (6);
      x = vect[i].to_ulong();
      if (x <= CHAR_MAX) {
        c = static_cast<char>(x);
        output += c;
      } else {
        output += ' ';
      }
    }
    reverseString(output);
    return output;
  }
  
};