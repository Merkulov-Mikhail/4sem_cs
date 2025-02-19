#include <string>


using color = const std::string;
namespace Colors {
    color Default = "\033[0m" ;
    color Black   = "\033[30m";
    color Red     = "\033[31m";
    color Green   = "\033[32m";
    color Brown   = "\033[33m";
    color Blue    = "\033[34m";
    color Violet  = "\033[35m";
    color Cyan    = "\033[36m";
    color Gray    = "\033[37m";
};
