#include <iostream>
#include <fstream>

// ifstream : in
// ofstream : out
// fstream : in/out

/**
 * @brief Open a stream to filename on referenced std::fstream.
 * If bool create, it'll create the file if not existing.
 * @param filename 
 * @param stream 
 * @param create 
 * @return int 
 */
int	open_stream(const char* filename, std::fstream& stream, bool create)
{
	if (create)
		stream.open(filename, std::ios::out | std::ios::trunc);
	else
		stream.open(filename, std::ios::in);
	if (!stream.is_open())
	{
		std::cout << "Couldn't open file " << filename << std::endl;
		return (0);
	}
	return (1);
}

/**
 * @brief Close a stream only if it's open.
 * 
 * @param stream 
 */
void	secure_close_stream(std::fstream& stream)
{
	if (stream.is_open())
		stream.close();
}

/**
 * @brief Change current read position to the OEF, get the current position
 * as integer, change position to start and return length.
 * 
 * @param stream 
 * @return int 
 */
int	stream_length(std::fstream& stream)
{
	int	length = 0;

	stream.seekg(0, stream.end);
	length = stream.tellg();
	if (length > 0)
		stream.seekg(0, stream.beg);
	return (length);
}

/**
 * @brief Copy the content rode in stream1 in a string, replace every occurences
 * of s1 by s2 in said string and then send it to stream2.
 * 
 * @param stream1 
 * @param stream2 
 * @param s1 
 * @param s2 
 */
void	replace_sed(std::fstream& stream1, std::fstream& stream2, char *s1, char *s2)
{
	int			length = 0;
	length = stream_length(stream1);
	if (length < 1)
		return;

	char		*buffer = new char[length + 1];
	std::string buffer_string = "";
	std::string s1_string = s1;
	std::string	s2_string = s2;

	stream1.read(buffer, length);
	if (buffer)
	{
		buffer_string = buffer;	
		secure_close_stream(stream1);
		for (size_t pos = 0; ; pos += s2_string.length())
		{
			pos = buffer_string.find(s1_string, pos);
			if (pos == std::string::npos) break;
			buffer_string.erase(pos, s1_string.length());
			buffer_string.insert(pos, s2_string);
		}
		stream2.write(buffer_string.c_str(), buffer_string.length());
		secure_close_stream(stream2);
	}
	delete[] buffer;
}

/**
 * @brief Reproduce the behaviour of sed.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	std::fstream	stream1;
	std::fstream	stream2;
	std::string		firstPath;
	std::string 	newPath;

	if (argc != 4 || !argv[1][0] || !argv[2][0] || !argv[3][0])
	{
		std::cout << "Bad instructions. Parameters cannot be empty." << std::endl;
		return (1);
	}
	firstPath.append(argv[1]);
	if (!open_stream(firstPath.c_str(), stream1, false))
		return (1);
	newPath.append(firstPath);
	newPath.append(".replace");
	if (!open_stream(newPath.c_str(), stream2, true))
	{
		secure_close_stream(stream1);
		return (1);
	}
	replace_sed(stream1, stream2, argv[2], argv[3]);
	return (0);
}
