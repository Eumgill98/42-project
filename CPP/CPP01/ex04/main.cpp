#include <fstream>
#include <iostream>

int replace(char *infile, char *s1, char *s2, std::string buffer)
{
    std::fstream    outfile;
    int             j;

    outfile.open((std::string(infile) + ".replace").c_str(),ios::out);
    // 
}

int main(int ac, char **av)
{
    char            c;
    std::fstream    infile;
    std::string     buffer;

    if (ac != 4)
    {
        std::cout << "argv must <file> <s1> <s2> !!" << std::endl;
        return (1); 
    }
    infile.open(av[1], ios::in);
    if (infile.fail())
    {
        std::cout << "Error: " << av[1] << ":" << "no such file or diretory" << std::endl;
        return (1);
    }
    while (!inflie.eof() && infile >> std::noskipws >> c)
        buffer += c;
    infile.close()
    return (replace(av[1], av[2], av[3], buffer));
}