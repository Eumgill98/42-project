#include <fstream>
#include <iostream>

int replace(char *infile, char *s1, char *s2, std::string buffer)
{
    std::fstream outfile;
    std::string s1_str(s1);
    std::string s2_str(s2);

    outfile.open((std::string(infile) + ".replace").c_str(), std::ios::out);
    if (outfile.fail())
    {
        std::cout << "Error:" << infile << ".replace" << "no make file or directory" << std::endl;
        return (1);
    }
    for (int i = 0; i < (int)buffer.size(); i++) 
    {
        int j = buffer.find(s1_str, i);
        if (j != -1 && j == i)
        {
            outfile << s2_str;
            i += s1_str.size() - 1;
        } 
        else
            outfile << buffer[i];
    }
    outfile.close();
    return (0);
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
    infile.open(av[1], std::ios::in);
    if (infile.fail())
    {
        std::cout << "Error: " << av[1] << ":" << "no such file or directory" << std::endl;
        return (1);
    }
    while (!infile.eof() && infile >> std::noskipws >> c)
        buffer += c;
    infile.close();
    return (replace(av[1], av[2], av[3], buffer));
}