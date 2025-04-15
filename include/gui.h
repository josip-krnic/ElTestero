#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/dirctrl.h>
#include <wx/stc/stc.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

class MainFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* menuBar;
		wxMenu* fileMenu;
		wxMenu* serverMenu;
		wxGenericDirCtrl* m_genericDirCtrl1;
		wxStyledTextCtrl* textEditor;
		wxStatusBar* statusBar;

	public:

		MainFrame(
			wxWindow* parent, 
			wxWindowID id = wxID_ANY, 
			const wxString& title = wxEmptyString, 
			const wxPoint& pos = wxDefaultPosition, 
			const wxSize& size = wxSize(610,351), 
			long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

		~MainFrame();

};