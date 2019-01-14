str::str()//СДЕЛАНО.РАБОТАЕТ. нулевой конструктор
{
	std::cout << "введите выражение" << std::endl;
	std::string s1;
	getline(std::cin, s1);
	strok = new char[s1.length() + 1];
	size = strlen(strok);
	/*const char *copyC;
	copyC = s1.c_str();
	strcpy(strok, copyC); */
	for (int i = 0; i < size; i++)
	{
		strok[i] = s1[i];
	};
};