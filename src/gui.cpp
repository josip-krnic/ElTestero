#include "gui.h"

MainFrame::MainFrame(
	wxWindow* parent, 
	wxWindowID id, 
	const wxString& title, 
	const wxPoint& pos, 
	const wxSize& size, 
	long style
	) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	menuBar = new wxMenuBar(0);
	/* File Menu */
	fileMenu = new wxMenu();

	wxMenuItem* newFileItem;
	newFileItem = new wxMenuItem(fileMenu, wxID_ANY, wxString(_("New FIle")) , wxEmptyString, wxITEM_NORMAL);
	fileMenu->Append(newFileItem);

	wxMenuItem* newFolderItem;
	newFolderItem = new wxMenuItem(fileMenu, wxID_ANY, wxString(_("New Foder")) , wxEmptyString, wxITEM_NORMAL);
	fileMenu->Append(newFolderItem);

	fileMenu->AppendSeparator();

	wxMenuItem* openItem;
	openItem = new wxMenuItem(fileMenu, wxID_ANY, wxString(_("Open")) , wxEmptyString, wxITEM_NORMAL);
	fileMenu->Append(openItem);

	menuBar->Append(fileMenu, _("File"));

	serverMenu = new wxMenu();
	wxMenuItem* newServerItem;
	newServerItem = new wxMenuItem(serverMenu, wxID_ANY, wxString(_("New Server")) , wxEmptyString, wxITEM_NORMAL);
	serverMenu->Append(newServerItem);

	serverMenu->AppendSeparator();

	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem(serverMenu, wxID_ANY, wxString(_("Send and run ")) , wxEmptyString, wxITEM_NORMAL);
	serverMenu->Append(m_menuItem5);

	wxMenuItem* runItem;
	runItem = new wxMenuItem(serverMenu, wxID_ANY, wxString(_("Run")) , wxEmptyString, wxITEM_NORMAL);
	serverMenu->Append(runItem);

	wxMenuItem* endAndRunItem;
	endAndRunItem = new wxMenuItem(serverMenu, wxID_ANY, wxString(_("Send")) , wxEmptyString, wxITEM_NORMAL);
	serverMenu->Append(endAndRunItem);

	serverMenu->AppendSeparator();

	wxMenuItem* runLocalItem;
	runLocalItem = new wxMenuItem(serverMenu, wxID_ANY, wxString(_("Run locally")) , wxEmptyString, wxITEM_NORMAL);
	serverMenu->Append(runLocalItem);

	menuBar->Append(serverMenu, _("Server"));

	this->SetMenuBar(menuBar);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	wxFlexGridSizer* workspaceGrid = new wxFlexGridSizer(0, 2, 0, 0);
	workspaceGrid->AddGrowableCol(0, 1);
	workspaceGrid->AddGrowableCol(1, 4);
	workspaceGrid->AddGrowableRow(0);

	m_genericDirCtrl1 = new wxGenericDirCtrl(
		this, wxID_ANY, 
		wxEmptyString, 
		wxDefaultPosition, 
		wxDefaultSize, 
		wxDIRCTRL_3D_INTERNAL | wxSUNKEN_BORDER, 
		wxEmptyString, 
		0
		);

	m_genericDirCtrl1->ShowHidden(false);
	workspaceGrid->Add(m_genericDirCtrl1, 1, wxEXPAND | wxALL, 5);

	textEditor = new wxStyledTextCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL, wxEmptyString);
	textEditor->SetUseTabs(true);
	textEditor->SetTabWidth(4);
	textEditor->SetIndent(4);
	textEditor->SetTabIndents(true);
	textEditor->SetBackSpaceUnIndents(true);
	textEditor->SetViewEOL(false);
	textEditor->SetViewWhiteSpace(false);
	textEditor->SetMarginWidth(2, 0);
	textEditor->SetIndentationGuides(true);
	textEditor->SetReadOnly(false);
	textEditor->SetMarginType(1, wxSTC_MARGIN_SYMBOL);
	textEditor->SetMarginMask(1, wxSTC_MASK_FOLDERS);
	textEditor->SetMarginWidth(1, 16);
	textEditor->SetMarginSensitive(1, true);
	textEditor->SetProperty(wxT("fold"), wxT("1"));
	textEditor->SetFoldFlags(wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED);
	textEditor->SetMarginType(0, wxSTC_MARGIN_NUMBER);
	textEditor->SetMarginWidth(0, textEditor->TextWidth(wxSTC_STYLE_LINENUMBER, wxT("_99999")));
	textEditor->MarkerDefine(wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS);
	textEditor->MarkerSetBackground(wxSTC_MARKNUM_FOLDER, wxColour(wxT("BLACK")));
	textEditor->MarkerSetForeground(wxSTC_MARKNUM_FOLDER, wxColour(wxT("WHITE")));
	textEditor->MarkerDefine(wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS);
	textEditor->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPEN, wxColour(wxT("BLACK")));
	textEditor->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPEN, wxColour(wxT("WHITE")));
	textEditor->MarkerDefine(wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY);
	textEditor->MarkerDefine(wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS);
	textEditor->MarkerSetBackground(wxSTC_MARKNUM_FOLDEREND, wxColour(wxT("BLACK")));
	textEditor->MarkerSetForeground(wxSTC_MARKNUM_FOLDEREND, wxColour(wxT("WHITE")));
	textEditor->MarkerDefine(wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS);
	textEditor->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPENMID, wxColour(wxT("BLACK")));
	textEditor->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPENMID, wxColour(wxT("PINK")));
	textEditor->MarkerDefine(wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY);
	textEditor->MarkerDefine(wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY);
	textEditor->SetSelBackground(true, wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	textEditor->SetSelForeground(true, wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));

	workspaceGrid->Add(textEditor, 1, wxALL | wxEXPAND, 5);

	bSizer1->Add(workspaceGrid, 1, wxEXPAND | wxALL, 5);

	this->SetSizer(bSizer1);
	this->Layout();
	statusBar = this->CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);

	this->Centre(wxBOTH);
}

MainFrame::~MainFrame()
{
}
