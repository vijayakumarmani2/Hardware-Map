#include <iostream>

void cpu();
void webcam();
void ram();
void memory();
void display();
void webcam();
//void d();
void battery();
void disk();
void wifi();
void ethernet();
void bluetooth();
void keyboard();
void mouse();
void touchpad();
void audio();
void mic();
void gpu();
void sys_info();

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: hardware_map <cpu/webcam/memory/ram/display/wifi/ethernet/bluetooth/keyboard/mouse/touchpad/audio/gpu/sys_info/all>" << std::endl;
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
    }else if (command == "battery") {
        battery();
    }else if (command == "disk") {
        disk();
    }else if (command == "wifi") {
        wifi();
    }else if (command == "ethernet") {
        ethernet();
    }else if (command == "bluetooth") {
        bluetooth();
    }else if (command == "keyboard") {
        keyboard();
    }else if (command == "mouse") {
        mouse();
    }else if (command == "touchpad") {
        touchpad();
    }else if (command == "audio") {
        audio();
    }else if (command == "mic") {
        mic();
    }else if (command == "gpu") {
        gpu();
    }else if (command == "sys_info") {
        sys_info();
    }else if (command == "all") {
        std::cout << "\n***System Information***\n" << std::endl;
        sys_info();
        std::cout << "\n\n-------CPU Details\n" << std::endl;
        cpu();
        std::cout << "\n\n-------Webcam Details\n" << std::endl;
        webcam();
        std::cout << "\n\n-------Memory Details\n" << std::endl;
        memory();
        std::cout << "\n\n-------RAM Details\n" << std::endl;
        ram();
        std::cout << "\n\n-------Display Details\n" << std::endl;
        display();
        std::cout << "\n\n-------Battery Details\n" << std::endl;
       // battery();
        std::cout << "\n\n-------Disk Details\n" << std::endl;
        disk();
        std::cout << "\n\n-------Wifi Details\n" << std::endl;
        wifi();
        std::cout << "\n\n-------Ethernet Details\n" << std::endl;
        ethernet();
        std::cout << "\n\n-------Bluetooth Details\n" << std::endl;
        bluetooth();
        std::cout << "\n\n-------Keyboard Details\n" << std::endl;
        keyboard();
        std::cout << "\n\n-------Mouse Details\n" << std::endl;
        mouse();
        std::cout << "\n\n-------Touchpad Details\n" << std::endl;
        touchpad();
        std::cout << "\n\n-------Audio Details\n" << std::endl;
        audio();
        std::cout << "\n\n-------GPU Details\n" << std::endl;
        gpu();
    } else {
        std::cout << "Unknown command!" << std::endl;
    }

    return 0;
}
