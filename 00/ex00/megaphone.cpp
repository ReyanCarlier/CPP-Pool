#include <iostream>
#include <cstring>

/**
 * @brief Convert every strings sent in parameter to upper case and print them
 * on the standard output.
 * 
 * @param argc 
 * @param argv 
 */
int    main(int argc, char **argv)
{
	std::string tmp;

    for (int i = 1; i < argc; i++)
		for (int j = 0; argv[i][j]; j++)
			std::cout << (char)toupper(argv[i][j]);
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}
