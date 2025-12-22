#include <iostream>
#include <fstream>
#include <string>

static void replace_and_write(std::string line,
							  const std::string& s1,
							  const std::string& s2,
							  std::ofstream& out)
{
	size_t pos = 0;
	size_t found;

	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		out << line.substr(pos, found - pos);
		out << s2;
		pos = found + s1.length();
	}
	out << line.substr(pos);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed_is_for_losers <file> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: cannot open input file" << std::endl;
		return 1;
	}

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: cannot create output file" << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		replace_and_write(line, s1, s2, outfile);
		if (!infile.eof())
			outfile << std::endl;
	}

	infile.close();
	outfile.close();
	return 0;
}
