#include "pch.h"
#include <iostream>
#include <string>
#include <list>

struct leave
{

	leave() //создание первого листа
	{		
		std::cout << "Введите значение" << std::endl;
		getline(std::cin, body);
		son = NULL;
		brother = NULL;
		previous = NULL;
	};
	leave(leave *&parent, int q /*std::string s1*/) //на случай, если захочу задавать параметр изначально. создание нового листа. будет добавляться в конец дерева bool является показателем, какой лист это будет, брат или потомок. потомок - 1; брат - 0;
	{
		//этот вариант для меня, если нужно осуществлять ввод с клавиатуры.
		/*std::cout << "Введите значение" << std::endl;
		getline(std::cin, body);*/
		// тестовое добавление значений. 
		 std::string s1 = "son";
		std::string s2 = "brother";
		if (q==false)
		{
					body = s1;
					son = NULL;
					brother = NULL;
					previous = parent;
					parent->son = this; // меняет ссылку на сына у родителя 
					level++;
					parent = this;
		}
		if (q==true)
		{
					body = s2;/*s1;*/
					son = NULL;
					brother = NULL;
					previous = parent;
					parent->brother = this;
					parent = this;
		};
		
	};
	leave(int q, leave *&parent /*std::string s1*/) //создание нового листа. будет добавляться в конец дерева bool является показателем, какой лист это будет, брат или потомок. потомок - 1; брат - 0;
	{
		//std::cout << "Введите значение" << std::endl;
		//getline(std::cin, body);
		std::string s1 = "son";
		std::string s2 = "brother";
		if (q == false)
		{
			body = s1;
			son = NULL;
			brother = NULL;
			previous = parent;
			if (parent->son == NULL)
			{
				parent->son = this; // меняет ссылку на сына у родителя 
				
			}
			else
			{
				son = parent->son;
				parent->son = this;
			}
		}
		if (q == true)
		{
			body = s2;/*s1*/
			son = NULL;
			brother = NULL;
			previous = parent;
			if (parent->brother == NULL)
			{
				parent->brother = this; // меняет ссылку на сына у родителя 

			}
			else
			{
				brother = parent->brother;
				parent->brother = this;
			}
		};

	};
	~leave() 
	{
		son = NULL;
		brother = NULL;
		previous = NULL;
		body.clear ();
		//динамически созданные объекты удаляются при применении к указателю на объект оператора delete
		
	};
	std::string getbody()
	{
		return body;
	};
	leave * getme() {
		leave *me = this;
		return me;
	};
	leave * getprevious() {
		leave *previous = this->previous;
		return previous;
	};
	std::string body; // у узла должно быть тело с инфой, ссылка на брата, ссылка на потомка. 
	leave *son;
	leave *brother;
	leave *previous;
	int level;
};

class tree
{
public:
	void add(bool q) // добавление в конец
	{	
		now = new leave (now, q);
	};
	void add(leave *&parent,  bool q) // добавление в определенное место
	{
		new leave(q, parent);
	};
	void find(std::string s1, leave *root, int lvl, int b, leave **a) //поиск значения в этом дереве
	{
		if (s1 == root->body)
		{
			std::cout << "элемент находится на уровне " << lvl << "\n порядковый номер " << b << std::endl;
		
			for (int i = 0; i < 20; i++)
			{
				if (a[i] == NULL)
				{
					a[i] = root;
					break;
				}
			}
		}
			if (root->son != NULL)
			{
				find(s1, root->son, lvl+1, b, a);
			}
			if (root->brother != NULL)
			{
				find (s1, root->brother, lvl, b+1, a);
			}
	};
	// тут надо доделать счетчик порядкового номера, он лагает. 
	void print(leave * root, int level)
	{
		for (int i = 0; i < level; i++)
		{
			std::cout << "   ";
		};
		std::cout << root->body << std::endl;
		if (root->son != NULL)
		{
			print(root->son, level + 1);
		}
		if (root->brother != NULL)
		{
			print(root->brother, level);
		}
	};
	leave * getroot()
	{
		return root;
	}
	leave * getnow()
	{
		return now;
	};
	tree() //создание первого элемента дерева. 
	{
		root = new leave();
		now = root;
		
	};
	/*void del(leave *&me) //в идеале должна быть ссылка на родителя, чтобы братьев перецеплять
	{
		leave* previous = (*me).getprevious();
		previous->brother = me->brother; //???
		delete (*me).~leave;
		
	}
	/*void deletetree(leave *&root)
	{
		if (root->son != NULL)
		{
			deletetree(root->son);
		}
		if (root->brother != NULL)
		{
			deletetree(root->brother);
		};
		
		delete (*root).~leave;	

	};*/
private:
	leave *root;
	leave *now;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	tree now;
	now.add(false);
	now.add(true);
	now.add(true);
	now.add(true);
	now.add(false);
	now.add(false);
	now.add(true);
	now.add(false);
	now.add(true);
	now.add(false);
	now.add(true);
	now.add(true);
	now.add(true);
	now.add(true);
	now.add(true);
	now.add(true);
	now.print(now.getroot(), 0);
	leave *a[20] = { 0 };
	now.find("brother", now.getroot(),0,0,a);
	now.add(a[1], false);
	now.add(a[1], true);
	now.add(a[1], true);
	now.add(a[7], false);
	now.add(a[2], true);
	now.add(a[2], false);
	now.add(a[8], false);
	now.add(a[3], true);
	now.add(a[7], true);
	now.add(a[10], false);
	now.add(a[9], true);
	now.add(a[10], false);
	now.print(now.getroot(), 0);

};

