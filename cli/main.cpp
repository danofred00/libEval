
#include <iostream>
#include "eval/eval.h"

#define DESCRIPTION PROJECT_DESCRIPTION 

const std::string description() 
{
    return std::string(DESCRIPTION);
}

const std::string version()
{
    return std::string("version ").append(LIBCALC_VERSION);
}

const std::string usage(const std::string & f = "evald")
{
    return
    "Description : \n"
    "\t" + description() + " \n"
    "Usage : " + f + " [option] [expression] \n"
    "\texpression - expression to evaluate \n\n"
    "Options : \n"
    "\t--interactive - run interactive mod \n"
    "\t--help        - print this message \n"
    "\t--version     - print the version of this tool \n";
}

// some utils

bool str_startWith(const std::string & s1, const std::string & s2)
{
    auto result = s1.compare(0, s2.length(), s2);
    if(result == 0)
        return true;
    
    return false;
}

/**
 * Cli function
*/
void cli()
{
    std::string cmd;
    bool handle = true;
    
    //
    std::cout << "Running in cli Mod : " << version() << std::endl;
    
    while (handle)
    {        
        // get cmdline
        std::getline(std::cin, cmd);
        // parse options
        if((cmd == "quit") || (cmd == "q"))
            handle = false;
        else
            try {
                std::cout << "Result : " << eval(cmd) << std::endl;
            } catch (std::exception & e) {
                std::cerr << "Bad arithmetic expression" << std::endl;
            }
    }

}

/**
 * MAIN FUNCTION
*/
int main(int argc, char const *argv[])
{
    /* code */
    std::string outname { argv[0] };
    std::string secondArg;

    // check args
    if(argc > 3) {
        std::cout << "Invalid args, please check the help (--help)" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    if (argc < 2) {
        std::cout << usage(outname) << std::endl; 
        exit(EXIT_FAILURE);
    } 

    // update value of secondArg
    secondArg.append(argv[1]);

    if(str_startWith(secondArg, "--"))
    {
        if(secondArg.compare("--help") == 0)
            std::cout << usage(outname) << std::endl; 

        else if(secondArg.compare("--version") == 0)
            std::cout << version() << std::endl;
        
        else if(secondArg.compare("--interactive") == 0)
            cli();
            
        else 
            std::cerr << "Unknow option : " << secondArg << std::endl;

    } else {
        try {
            
            std::cout << eval(secondArg) << std::endl;

        } catch (std::exception e) {
            std::cerr << "There is some error during evaluation" << std::endl;
            std::cerr << e.what() << std::endl;
        }
    }
    
    return EXIT_SUCCESS;
}
