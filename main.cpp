#include "GUI.h"
#include "structures/heap_monitor.h"
int main()
{
    initHeapMonitor();
    System::Windows::Forms::Application::EnableVisualStyles();
    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

    BalaziMatusAUS2::GUI ui;

    System::Windows::Forms::Application::Run(% ui);

	return 0;
}