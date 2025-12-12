#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	if (argc != 4 || !argv[1] || !argv[2] || !argv[3] || argv[2][0] == '\0')
		return (1);
	printf("%s %s\n", argv[2], argv[3]);
	std::ifstream in(argv[1]);
	std::string repl_file(argv[1]);
	repl_file.append(".replace");
	std::ofstream out(repl_file);
	std::string to_replace(argv[2]);
	std::string replace_with(argv[3]);
	std::string str;
	while (std::getline(in, str)) {
		size_t pos = 0;
		while (str.find(to_replace, pos) != std::string::npos)
		{
			pos = str.find(to_replace, pos);
			std::string tmp = str.substr(0, pos);
			tmp.append(replace_with);
			size_t tmp_pos = tmp.size();
			tmp.append(str.substr(pos + to_replace.size()));
			str = tmp;
			pos = tmp_pos;
		}
		out << str << std::endl;
	}
}