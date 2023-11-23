#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdint>

#define DMI_TABLE_PATH "/sys/firmware/dmi/tables/DMI"

struct dmi_header {
    uint8_t type;
    uint8_t length;
    uint16_t handle;
};

const char* get_memory_type(uint8_t type) {
    switch (type) {
        case 0x1A: return "DDR4";
        default: return "Unknown";
    }
}

const char* get_form_factor(uint8_t factor) {
    switch (factor) {
        case 0x09: return "SODIMM";
        default: return "Other";
    }
}

const char* get_memory_technology(uint8_t type) {
    switch (type) {
        case 0x1A: return "DRAM";
        default: return "Unknown";
    }
}

void print_physical_memory_array(const uint8_t *data, const dmi_header *hdr) {
    uint16_t handle = hdr->handle;
    uint8_t location = *(data + 0x04);
    uint8_t use = *(data + 0x05);
    uint8_t error_correction = *(data + 0x06);
    uint32_t max_capacity = *(uint32_t *)(data + 0x07);
    uint16_t num_devices = *(uint16_t *)(data + 0x0D);

   // printf("--------RAM memeory info---------\n");
   // printf("Handle 0x%04X, DMI type 16, %d bytes\n", handle, hdr->length);
    printf("Memory: Physical Memory Array\n");
    printf("Location: %s\n", location == 0x03 ? "System Board Or Motherboard" : "Other");
    printf("Use: %s\n", use == 0x03 ? "System Memory" : "Other");
    printf("Error Correction Type: %s\n", error_correction == 0x00 ? "None" : "Other");
    printf("Maximum Capacity: %d GB\n", max_capacity / (1024 * 1024));
    printf("Error Information Handle: Not Provided\n"); // Simplified for brevity
    printf("Number Of Devices: %d\n", num_devices);
}

void print_memory_array_mapped_address(const uint8_t *data, const dmi_header *hdr) {
    uint16_t handle = hdr->handle;
    uint64_t starting_address = *(uint32_t *)(data + 0x04); // Simplified for brevity
    uint64_t ending_address = *(uint32_t *)(data + 0x08); // Simplified for brevity
    uint16_t array_handle = *(uint16_t *)(data + 0x0C);
    uint8_t partition_width = *(data + 0x0E);

   // printf("Handle 0x%04X, DMI type 19, %d bytes\n", handle, hdr->length);
    printf("Memory: Memory Array Mapped Address\n");
    printf("Starting Address: 0x%012lX\n", starting_address);
    printf("Ending Address: 0x%012lX\n", ending_address);
    printf("Range Size: %d GB\n", (int)((ending_address - starting_address + 1) / (1024 * 1024)));
    printf("Physical Array Handle: 0x%04X\n", array_handle);
    printf("Partition Width: %d\n", partition_width);
}

void print_memory_info(const uint8_t *data, const dmi_header *hdr) {
     uint16_t array_handle = *(uint16_t *)(data + 0x04);
    uint16_t error_info_handle = *(uint16_t *)(data + 0x06);
    uint16_t total_width = *(uint16_t *)(data + 0x08);
    uint16_t data_width = *(uint16_t *)(data + 0x0A);
    uint16_t size = *(uint16_t *)(data + 0x0C);
    uint8_t form_factor = *(data + 0x0E);
    uint8_t set = *(data + 0x0F);
    uint8_t type = *(data + 0x12);
    uint16_t speed = *(uint16_t *)(data + 0x15);
    uint8_t rank = *(data + 0x1B);
    uint16_t conf_speed = *(uint16_t *)(data + 0x28);
    uint16_t min_voltage = *(uint16_t *)(data + 0x1C);
    uint16_t max_voltage = *(uint16_t *)(data + 0x1E);
    uint16_t conf_voltage = *(uint16_t *)(data + 0x20);
    uint8_t memory_technology = *(data + 0x28); // Placeholder
    uint64_t volatile_size = *(uint64_t *)(data + 0x2C); // Placeholder

    char *locator = (char *)(data + hdr->length);
    char *bank_locator = (char *)(data + hdr->length + strlen(locator) + 1);
    char *manufacturer = (char *)(data + hdr->length + strlen(locator) + strlen(bank_locator) + 2);
    char *serial_number = (char *)(data + hdr->length + strlen(locator) + strlen(bank_locator) + strlen(manufacturer) + 3);
    char *asset_tag = (char *)(data + hdr->length + strlen(locator) + strlen(bank_locator) + strlen(manufacturer) + strlen(serial_number) + 4);
    char *part_number = (char *)(data + hdr->length + strlen(locator) + strlen(bank_locator) + strlen(manufacturer) + strlen(serial_number) + strlen(asset_tag) + 5);

    printf("Array Handle: 0x%04X\n", array_handle);
    printf("Error Information Handle: %s\n", error_info_handle == 0xFFFF ? "Not Provided" : "Provided");
    printf("Total Width: %d bits\n", total_width);
    printf("Data Width: %d bits\n", data_width);
    printf("Size: %d MB\n", size);
    printf("Form Factor: %s\n", get_form_factor(form_factor));
    printf("Set: %s\n", set == 0x00 ? "None" : "Other");
    printf("Locator: %s\n", locator);
    printf("Bank Locator: %s\n", bank_locator);
    printf("Type: %s\n", get_memory_type(type));
    printf("Type Detail: Synchronous\n");
    printf("Speed: %d MT/s\n", speed);
    printf("Manufacturer: %s\n", manufacturer);
    printf("Serial Number: %s\n", serial_number);
    printf("Asset Tag: %s\n", asset_tag);
    printf("Part Number: %s\n", part_number);
    printf("Rank: %d\n", rank);
    printf("Configured Memory Speed: %d MT/s\n", conf_speed);
    if (min_voltage == 0xFFFF) {
    printf("Minimum Voltage: Unknown V\n");
    } else {
    printf("Minimum Voltage: %.1f V\n", min_voltage / 10.0);
    }

    if (max_voltage == 0xFFFF) {
    printf("Maximum Voltage: Unknown V\n");
    } else {
    printf("Maximum Voltage: %.1f V\n", max_voltage / 10.0);
    }

printf("Configured Voltage: %.1f V\n", conf_voltage / 10.0);
    printf("Memory Technology: %s\n", get_memory_technology(memory_technology));
    printf("Memory Operating Mode Capability: Volatile memory\n");
    printf("Firmware Version: Not Specified\n");
    printf("Module Manufacturer ID: Bank 1, Hex 0xAD\n");
    printf("Module Product ID: Unknown\n");
    printf("Memory Subsystem Controller Manufacturer ID: Unknown\n");
    printf("Memory Subsystem Controller Product ID: Unknown\n");
    printf("Non-Volatile Size: None\n");
    printf("Volatile Size: %d MB\n", size);
    printf("Cache Size: None\n");
    printf("Logical Size: None\n");
    printf("\n");
}

void ram() {
    std::ifstream f(DMI_TABLE_PATH, std::ios::binary);
    if (!f) {
        std::cerr << "Failed to open DMI table" << std::endl;
        return;
    }

    f.seekg(0, std::ios::end);
    size_t length = f.tellg();
    f.seekg(0, std::ios::beg);

    std::vector<uint8_t> buffer(length);
    f.read(reinterpret_cast<char*>(buffer.data()), length);

    size_t offset = 0;
    while (offset < length - 1) {  
    dmi_header *hdr = reinterpret_cast<dmi_header*>(buffer.data() + offset);

    if (hdr->type == 16 && hdr->length >= 15) {
        print_physical_memory_array(buffer.data()+offset, hdr);
    } else if (hdr->type == 17 && hdr->length >= 27) {
        print_memory_info(buffer.data() + offset, hdr);
    } else if (hdr->type == 19 && hdr->length >= 15) {
        print_memory_array_mapped_address(buffer.data() + offset, hdr);
    }

    // Move past the header and formatted area
    offset += hdr->length;

    // Skip the unformatted area (strings) until we find the double null bytes
    while (offset < length - 1 && (buffer[offset] != 0 || buffer[offset + 1] != 0)) {
        offset++;
    }

    // Skip over the double null bytes to the start of the next structure
    offset += 2;
}

    
   
buffer.clear();
buffer.shrink_to_fit();
   // return 0;
}

