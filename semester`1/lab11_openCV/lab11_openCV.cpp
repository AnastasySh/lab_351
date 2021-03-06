﻿// 1. Библиотеки, подключаемые в виде исходных кодов (header-only) 
// Как правило, файл с расширением *.h или *.hpp, либо пара файлов 
// *.h и *.cpp с одинаковым названием. Содержат объявления и определения 
// переменных, констант, функций и классов. Подключаются в приложение 
// через #include заголовочного файла 
// В *.h как правило приводится объявление сущностей, а в *.cpp раскрывается 
// определение (реализация). Такой подход повышает читаемость структурированность 
// кода, однако ничто не мешает реализацию (определение) также поместить в *.h файл 
// Преимущества: 
// 1) Исходный код открыть 
// 2) его всегда можно модифицировать и исправить 
// 3) простота подключения
// Недостатки: 
// 1) пересборка всей библиотеки при каждой пересборке приложения, замедление сборки
//2. СТАТИЧЕСКИЕ БИБЛИОТЕКИ 
// 2.1 
// *.lib (англ. library) - файлы статически подключаемых библиотек 
// Недостаток прошлого подхода компенсируется, если библиотечный код предварительно 
// скомпилировать и построить, и уже скомпилированный бинарный файл 
// подключать в приложение 
// Преимущества: 
// 1) более быстрая пересборка проекта 
// 2) так как код из библиотеки встраивается в *.exe, он не потеряется 
// Недостатки: 
// 1) бинарники *.lib надо сначала найти или построить самим из исходников 
// 2) бинарная несовместимость: *.lib должны подходить под 
// -платформу (ОС и окружение) 
// -аппаратура (тип процессора и разрядность) 
// -компилятор и т.д. 
// 3) затруднительность аудита безопасности бинарных файлов 
// по данной причине библиотеки, связанные с ИБ, шифрованием, защитой 
// распространяются ТОЛЬКО в виде исходников, из которых разработчик 
// на месте должен сначала построить *.lib 
// в *.nix системах аналог *.lib файла имеет расширение *.a 
// 4) размер EXE файла увеличивается, так как код функций из *.lib 
// дописывается к EXE

// 2.2 ПОДКЛЮЧЕНИЕ СТАТИЧЕСКОЙ БИБЛИОТЕКИ 
// 1. При отсутствии бинарников исходники библиотеки собирать в 
// *.lib(настройки -> "Тип конфигурации") 
// 2. В настройках проекта VS "Компоновщик" -> "Ввод" 
// добавить название файла библиотеки *.lib 
// 3. В "Каталоги VC++" добавить путь к библиотеке 
// 4. В исходниках вашего проекта объявить функцию со спецификатором extern 
// или добавить *.h файл библиотеки
// Сведение приложения и подключенной статической библиотеки 
// производится уже после компиляции, на следующем этапе - этапе сборки (linking) 
// Линкер ищет функцию по имени в *.lib-файле. Если находит - берёт машинный код 
// функции и дописывает к *.exe. Если нет - возникает ошибка LNK2019 или 
// схожие
// 3. ДИНАМИЧЕСКИЕ БИБЛИОТЕКИ 
// *.dll (Dynamic Link Library) - файлы динамически подключаемых библиотек 
// *.so (англ. source object) - динамические библиотеки в Linux 

// Библиотека *.lib или *.dll - файл, содержащий готовый машинный код для 
// многократного повторного использования
// Код из статических библиотек помещается в *.exe в момент его сборки (после компиляции) 
// и далее является частью самого *.exe 

// если несколько *.exe используют один и тот же *.lib код дублируется в каждом *.exe 

// Код из динамической библиотеки может использоваться одновременно многими приложенинями 
// из одного и того же *.dll файла, загруженного в ОП
// если нескольког *.exe используют один и тот же *.dll, *.dll может быть единственным на машине 
// и использоваться всеми 

// по сути ОС представляет собой набор типовых наиболее часто используемых программами функций, 
// собранных в динамические библиотеки: функции для работы с файлами, с сетью, с устройствами, 
// функции безопасности, менеджмент процессов и т.д. 
// прикладные приложения, работая на ОС, не нуждаются в собственном коде для таких тривиальных операций 
// преимущества 1) снижение размера приложений 2) унификация 3) безопасность (варианты взаимодействия 
// приложений с системными ресурсами: файлами, аппаратурой ограничены типовым и безопасным набором 
// системных функций)
// огромное количество сторонних, в т.ч. и открытых бесплатных библиотек собирается и подключается 
// именно в виде lib или dll (PoDoFo - для работы и криптографической подписи PDF, множество эталонных 
// библиотек libjpeg, libpng для работы со сжатием изображений, криптографические библиотеки OpenSSL, OpenSSH)

#include <stdio.h>
#include <iostream>
#include <vector>

#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\objdetect.hpp>
//#include <opencv2\highgui\highgui_winrt.hpp>

int main()
{
	/* Инициализация */
	cv::CascadeClassifier face_cascade;
	cv::Mat image = cv::imread("group1.jpg");
	cv::Mat groupFaces = cv::Mat(image.rows, image.cols, CV_8UC4);
	cv::cvtColor(image, groupFaces, cv::COLOR_BGR2BGRA);
	//cv::winrt_initContainer(cvContainer);
	cv::imshow(std::string("Window 1"), groupFaces);

	if (!face_cascade.load("haarcascade_frontalface_alt.xml")) {
		std::cout << "Couldn't load face detector" << std::endl;
	}

	/* Обнаружение */
	if (!groupFaces.empty()) {
		std::vector<cv::Rect> facesColl;
		cv::Mat frame_gray;

		cvtColor(groupFaces, frame_gray, cv::COLOR_BGR2GRAY);
		cv::equalizeHist(frame_gray, frame_gray);

		// Detect faces
		face_cascade.detectMultiScale(frame_gray,
			facesColl,
			1.1, 2,
			0 | cv::CASCADE_SCALE_IMAGE,
			cv::Size(1, 1));
		for (unsigned int i = 0; i < facesColl.size(); i++)
		{
			auto face = facesColl[i];
			cv::rectangle(groupFaces, face, cv::Scalar(0, 255, 255), 5);
		}

		cv::imshow(std::string("Window 2"), groupFaces);
	}
	else {
		std::cout << "Initialize image before processing" << std::endl;
	}

	cv::waitKey();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
