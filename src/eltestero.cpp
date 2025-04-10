#include "gui.h"

#include <wx/wx.h>
#include <iostream>

int main(int argc, char *argv[])
{
    wxInitialize();
    wxApp::SetInstance(new wxApp());
    wxEntryStart(argc, argv);
    wxTheApp->CallOnInit();

    MainFrame *frame = new MainFrame(nullptr);
    frame->SetTitle("El Testero");
    frame->Show(true);

    return wxTheApp->OnRun();
}