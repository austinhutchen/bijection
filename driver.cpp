#include "./components/editor.hpp"
#include "./components/testers.cpp"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  string buf;
  if (argc < 2) {
    while (1) {

      cout << "READ/ENCRYPT or WRITE to file in.txt?" << endl;
      getline(cin, buf);

      if (buf == "read" || buf == "encrypt") {
        tester *help = new tester();
        help->encryptalgo();
        delete help;
        help = nullptr;
        return 0x0;
      }

      else if (buf == "write") {
        // use testers.cpp
        std::string choice;
        std::string input;
        int line;
        bool f;
        int curtime = time(NULL);
        std::string filename = "./txt/in.txt";
        send output(filename);
        // file is now open for all read/write operations
            std::cout
                << "Begin typing below. Type ENTER to type on a new line, or "
                   "EXIT to quit."
                << std::endl;
            std::cin.ignore();
            while (getline(std::cin, input)) {
              if (input != "EXIT") {
                f = output.print(input);
              } else {
                break;
              }

            };
 output.closefile();
            // splitstring here to check for new line
            //  getline automatically starts newline
            if (f == true) {
              std::cout << "Text succesfully written." << std::endl;
            } else {
              std::cout << "ERROR: Text failed to write." << std::endl;
              return main(argc, argv);
            }


        } else {
          std::cout
              << "Please enter the phrase write or read for your choice. No "
                 "spaces allowed."
              << std::endl;
          return main(argc, argv);
        }

       
      }
    }
  }

