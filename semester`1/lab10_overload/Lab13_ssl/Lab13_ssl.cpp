// Шифрование.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include <iostream>
#include <openssl/conf.h> //функции,
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/aes.h>
#include <fstream>
#pragma comment (lib, "libcrypto.lib")

using namespace std;


int main()
{
	
	struct name_of_my_struct
	{
		//как правило, в литературе, структуры используются для хранения только данных
	//ни слова не говорится о методах и конструкторах/деструкторах
		name_of_my_struct()
		{

		}
		int a;
		double b;
		int fnc1()
		{
			return a;
		}
	};

	unsigned char *plaintext = (unsigned char *)"Some text Some text Some text Some text"; //исходный текст
	int plaintext_len = strlen((char *)plaintext); //длина текста
	unsigned char *key = (unsigned char *)"0123456789"; //пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; //инициализирующий вектор
	unsigned char cryptedtext[256]; //зашифрованный результат
	unsigned char decryptedtext[256]; //расшифрованный результат

	//1. Создается указатель на структуру. то есть это не указатель на несуществующую структуру, как написанно в конспекте, а блин указатель с типом данных этой структуры. ну ты понел.
	//залог того что этот указатель будет корректно указывать на эту структуру. 
	EVP_CIPHER_CTX *ctx;
	
	//2. Для указателя создается пустая структура настроек(метод, ключ, вектор инициализации и т.д.) вызывается деструктор. мы не лезем и не выясняем что и как он там создает, но на
	//досуге можно будет почитать. ну вот короче вызываем мы деструктор от указателя, а значит что структура создастся и ссылка на нее запишется в этот указатель который мы создали
	ctx = EVP_CIPHER_CTX_new();  
	//3. Структура EVP_CIPHER_CTX заполняется настройками
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);//инициализация методом AES, ключом и вектором
	//4. Сам процесс шифрования - функция EVP_EncryptUpdate
	int len; //это - длина уже зашифроманного текста походу. 
	EVP_EncryptUpdate(ctx, cryptedtext, &len, plaintext, plaintext_len);//собственно, шифрование
	int cryptedtext_len = len;

	//5.Финализация процесса шифрования
	EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;

	//6.Удаление структуры
	EVP_CIPHER_CTX_free(ctx); 
		for (int i = 0; i < cryptedtext_len; i++)
		{
			cout << hex << cryptedtext[i];
			if ((i + 1) % 32 == 0) cout << endl;
		}
	cout << endl;
	//BIO_dump_fp(stdout, (char*)cryptedtext, cryptedtext_len-1);


	//1.
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	//2.

	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);//инициализация методом AES, ключом и вектором

	//3. 
	EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);//собственно, дешифрование

	//4.
	int decrypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

	//5.
	decrypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[decrypted_len] = '\0';
	cout << decryptedtext << endl;
	

	//шифрование файла производится точно так же, но порциями, в цикле
	//а теперь представьте что шифрование - перегонный аппарат. шифрование как первая ступень очистки.
	ifstream filenorm;
	ofstream filecry;// файлы для шифра и дешифра
	filenorm.open("test.txt", std::fstream::in | std::fstream::binary); // открытие в бинарном виде для последующего шифра
	filecry.open("filecry.txt", std::fstream::out | std::fstream::binary); // открытие файла для последующей записи тож бинарка
	if (!filenorm) {
		std::cout << "ошибка открытия норм файла"<< std::endl;//Обработка ошибки открытия файла
	}
	if (!filecry) {
		std::cout << "ошибка открытия cry файла" << std::endl;//Обработка ошибки открытия файла
	}
	//unsigned char *key = (unsigned char *)"019283745"; //пароль (ключ)
	//unsigned char *iv = (unsigned char *)"987654321054321"; //инициализирующий вектор
	char buffer[256] = { 0 }; // буфер для перегонки.
	char * out_buf[256] = { 0 }; // второй буфер для перегонки на выход. 
    //unsigned int number_of_bytes = 0; // это то, сколько он уже перегнал. итого у нас уже две перегонные колбы со счетчиком 
	len = 0; //это длинна шифра
	ctx = EVP_CIPHER_CTX_new(); // опять юзаем ту ссылочку
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); //забиваем нашу структуру настроечками
	filenorm.read(buffer, 256); // оно считывает в буфер
	
	while (filenorm.gcount() > 0)//бесконечный цикл считывания порций файла, шифрования и
		//записи в другой файл или пока из файла что-то считывается пока размер считанной порции > 0 
	{
		//шифруем
		EVP_EncryptUpdate(ctx, (unsigned char *)out_buf, &len, (unsigned char *)buffer, filenorm.gcount()); //последний входной параметр: длина входных данных
		//запись порцайки в фаил
		filecry.write((const char *)out_buf, len); //записываем все это счастье в фаил /// jib,rf d pdtpljxrf[
		filenorm.read(buffer, 256); // оно считывает опять в буфер
	}																				   																								   
	EVP_EncryptFinal_ex(ctx, (unsigned char *)out_buf, &len); // шлифанули сверху пивком. 
	filecry.write((const char*)out_buf, len);// записали это в фаил
	filecry.close();
	filenorm.close();
	memset(buffer, 0, sizeof(char) * 256); // моем наши перегонные колбочки от остатков и готовим их к второй ступени перегонки: из шифра в человеческие буквы
	memset(out_buf, 0, sizeof(char) * 256);
																										  
		
	fstream filecryingmore, whitebearcoming;// файлы для шифра и дешифра

	filecryingmore.open("filecry.txt", std::fstream::in | std::fstream::binary); // открываем их опять бинарными
	whitebearcoming.open("whitebearcoming.txt",	std::fstream::out | std::fstream::binary); 
	

		ctx = EVP_CIPHER_CTX_new(); 

		EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

		filecryingmore.read(buffer, 256);
		while (filecryingmore.gcount() > 0) // пошла вторая перегоночка из шифра и буквы
		{
			// расшифровка 
			EVP_DecryptUpdate(ctx,(unsigned char *)out_buf,	&len,(unsigned char *)buffer, filecryingmore.gcount());

			// запись расшифровки в файл 
			whitebearcoming.write((const char *)out_buf, len);

			// чтение следующей порции 
			filecryingmore.read(buffer, 256); 
		}

		EVP_DecryptFinal_ex(ctx, (unsigned char *)out_buf, &len); //если в первый раз у нас была шлифовка пивком, то тут получается зачистка пивком? надо подумать
		whitebearcoming.write((const char *)out_buf, len);

		whitebearcoming.close();
		filecryingmore.close();

		system("pause");
		return 0;
};