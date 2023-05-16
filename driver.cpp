#include <iostream>
#include "components/testers.cpp"
using namespace std;
int main() {
  tester *test = new tester();
  algo *alg = new algo();
  uint hx;
  vector<bitset<8> > output;
  string buf;
  bool ex = true;
  cin.ignore();
  while (ex) {
    cout << "---> ENTER INPUT <---" << endl;
    getline(cin, buf);
    output = alg->encrypt(buf, hx);
    cout << "------ENCRYPTION----- " << endl;
    for (int i = 0; i < output.size(); i++) {
      cout << output[i] << endl;
    }
    cout << " ------DECRYPTION-----" << endl;
    cout << alg->decrypt(output) << endl;
    cout << " ------HEX-----" << endl;
    cout << "0x" << hx << endl;
    cout << "Again? y (yes) /n (no) /f (file encrypt/decrypt)" << endl;
    getline(cin, buf);
    // lowercase character converter
    alg->lowercase(buf);
    switch (buf[0]) {
    case 121: {
      break;
    }
    case 102: {
      test->fio();
      break;
    }
    default: {
      ex = false;
      break;
    }
    }
  }

  return 0x0;
}