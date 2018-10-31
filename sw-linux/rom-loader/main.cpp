#include <iostream>
#include <string>
#include <vector>

#include <cstdio>
#include <cstdlib>

#include "serial.hpp"

struct args_t
{
    std::string file_name;
    bool file_name_set;
    std::string port_name;
    bool port_name_set;
    long baudrate;
    bool baudrate_set;
};

void usage(void)
{
    std::cout << "rom-loader -p [PORT] -f [FILE]" << std::endl
              << std::endl
              << "Nao Pross <naopross@thearcway.org>" << std::endl;
}

bool parse_arguments(const int argc, const char * const argv[], args_t& args)
{
    if (argc < 2) {
        usage();
        return false;
    }

    args.file_name_set = false;
    args.port_name_set = false;
    args.baudrate_set = false;

    for (int i = 1; i < argc; i++) {
        const std::string arg(argv[i]);

        bool next = false;
        std::string next_arg = "";

        // check that is an option
        if (arg.front() != '-') {
            usage();
            return false;
        }

        // help option
        if (arg[1] == 'h') {
            usage();
            return false;
        }

        // check that threre is an argument
        if (i+1 < argc) {
            next_arg = std::string(argv[i+1]);
            i++;
        } else {
            std::cerr << "Missing option argument" << std::endl;
            return false;
        }

        switch (arg[1]) {
        case 'p':
            args.port_name = next_arg;
            args.port_name_set = true;
            break;

        case 'f':
            args.file_name = next_arg;
            args.file_name_set = true;
            break;

        case 'b':
            args.baudrate = std::stol(next_arg);
            args.baudrate_set = true;
            break;

        default:
            std::cerr << "Invalid option " << arg << std::endl;
            return false;
        }
    }

    if (!args.file_name_set || !args.port_name_set) {
        std::cerr << "Missing required options: ";
        
        if (!args.file_name_set)
            std::cerr << "-f [FILE] ";

        if (!args.port_name_set)
            std::cerr << "-p [PORT] ";

        std::cerr << std::endl;

        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    args_t args;

    if (!parse_arguments(argc, argv, args)) {
        return -1;
    }

    FILE *fileptr = std::fopen(args.file_name.c_str(), "rb");

    if (!fileptr) {
        std::cerr << "Failed to open file " << args.file_name << std::endl;
        return -2;
    }

    serial s_dev(args.port_name, B9600);

    int chr;
    while ((chr = std::fgetc(fileptr)) != EOF) {
        const char byte = static_cast<char>(chr);

        // std::cout << std::hex << byte << std::endl;
        s_dev.write(&byte, 1);
    }

    if (std::ferror(fileptr))
        std::cerr << "I/O error when reading file " 
                  << args.file_name << std::endl;

    if (!std::feof(fileptr))
        std::cerr << "The reading ended before reaching EOF" << std::endl;

    std::fclose(fileptr);

    return 0;
}
