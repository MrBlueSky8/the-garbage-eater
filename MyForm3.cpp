#include "MyForm3.h"
using namespace System;
using namespace System::Windows::Forms; [STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);  Application::Run(gcnew
		Tfalphav05::MyForm3()); //Project 1 es el nombre del proyecto
}
