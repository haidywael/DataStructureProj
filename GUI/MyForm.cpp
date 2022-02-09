#include "MyForm.h"
#include <iostream>
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;

using namespace std;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyProject::MyForm form;
	Application::Run(% form);
	system("dot -Tpng -O graph.dot");

	return 0;
}



