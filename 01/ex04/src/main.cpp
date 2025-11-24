#include <iostream>
#include <fstream>

std::string replace_extension(std::string input)
{
	for (int i = input.size(); i >= 0; i--)
	{
		if (input[i] == '.')
		{
			input = input.substr(0, i);
			input.append(".replace");
			return (input);
		}
	}
	return (input.append(".replace"));
}

//int dupe_inputs(std::ofstream &out, std::ifstream &in)
//{
//	std::string str;
//	while (std::getline(in, str)) {
//		out << str << std::endl;
//	}
//	return (1);
//}

int main(int argc, char **argv) {
	if (argc != 4 || !argv[1] || !argv[2] || !argv[3])
		return (1);
	std::ifstream in(argv[1]);
	std::string repl_file = replace_extension(argv[1]);
	std::ofstream out(repl_file);
	std::string to_replace(argv[2]);
	std::string replace_with(argv[3]);
	//if (!to_replace.compare(replace_with))
	//	return (dupe_inputs(out, in));
	std::string str;
	while (std::getline(in, str)) {
		size_t pos = 0;
		while (str.find(&to_replace[pos]) != std::string::npos)
		{
			pos = str.find(&to_replace[pos]);
			std::string tmp = str.substr(0, pos);
			tmp.append(replace_with);
			size_t tmp_pos = tmp.size();
			tmp.append(str.substr(pos + to_replace.size(), str.size() - tmp.size()));
			str = tmp;
			//std::cout << str << tmp_pos << std::endl;
			pos = tmp_pos;
		}
		out << str << std::endl;
	}
}