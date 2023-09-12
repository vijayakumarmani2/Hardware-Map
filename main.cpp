#include <iostream>

void cpu();
void webcam();
void ram();
void memory();
void display();

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: hardware_map <cpu/webcam/memory/ram/display/all>" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    if (command == "cpu") {
        cpu();
    } else if (command == "webcam") {
        webcam();
    }else if (command == "memory") {
        memory();
    }else if (command == "ram") {
        ram();
    }else if (command == "display") {
        display();
    }else if (command == "all") {
        std::cout << "\n\n-------CPU Details--------\n" << std::endl;
        cpu();
        std::cout << "\n\n-------Webcam Details-------\n" << std::endl;
        webcam();
        std::cout << "\n\n-------Memory Details-------\n" << std::endl;
        memory();
        std::cout << "\n\n-------RAM Details-------\n" << std::endl;
        ram();
        std::cout << "\n\n-------Display Details-------\n" << std::endl;
        display();
    } else {
        std::cout << "Unknown command!" << std::endl;
    }

    return 0;
}
