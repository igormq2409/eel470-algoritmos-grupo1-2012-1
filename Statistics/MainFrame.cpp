/* 
 * File:   MainFrame.cpp
 * Author: igormq
 * 
 * Created on April 17, 2012, 3:56 PM
 */

#include "MainFrame.h"
#include "wx/wx.h"
#include "wx/toolbar.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame( NULL, -1, title, pos, size )
{
    this->menuFile = new wxMenu();

    this->menuFile->Append( ID_Open, _("&Open\tCtrl-O"));
    this->menuFile->Append( ID_Clear, _("Clea&r\tCtrl-R") );
    this->menuFile->AppendSeparator();
    this->menuFile->Append( ID_Quit, _("E&xit\tALT-F4") );
    
    this->menuHelp = new wxMenu;
    this->menuHelp->Append(ID_About, _("&About"));
    
    this->menuBar = new wxMenuBar();
    this->menuBar->Append( menuFile, _("&File") );
    this->menuBar->Append( menuHelp, _("&Help") );
    SetMenuBar( menuBar );
    
    this->textCtrl = new wxTextCtrl(this, wxID_ANY, wxT("Welcome to Statistics Calculator!\nTo start go to File->Open or just press Ctrl+O"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_MULTILINE | wxTE_READONLY);
    
    wxImage::AddHandler( new wxPNGHandler );
    
    wxBitmap openBitMap(_("./Images/open.png"), wxBITMAP_TYPE_PNG);
    wxBitmap clearBitMap(_("./Images/clear.png"), wxBITMAP_TYPE_PNG);
    wxBitmap exitBitMap(_("./Images/exit.png"), wxBITMAP_TYPE_PNG);
    wxBitmap aboutBitMap(_("./Images/about.png"), wxBITMAP_TYPE_PNG);
    
    this->toolBar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER|wxTB_TEXT);
    this->toolBar->AddTool(ID_Open, openBitMap, wxT("Open File (Ctrl+O"), _("Open Long String"));
    this->toolBar->AddTool(ID_Clear, clearBitMap, _("Clear (Ctrl+R)"), _("Clear Long String"));
    this->toolBar->AddSeparator();
    this->toolBar->AddTool(ID_About, aboutBitMap, _("About"), _("About Long String"));
    this->toolBar->AddSeparator();
    this->toolBar->AddTool(ID_Quit, exitBitMap, _("Exit(Ctrl+F4)"), _("Exit Long String"));
    this->toolBar->Realize(); 
   
    SetToolBar(toolBar);
    
    CreateStatusBar();
    SetStatusText( _("Welcome to Statistics!") );
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(TRUE);
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox( _("This is a wxWidgets Hello world sample"),
                  _("About Hello World"),
                  wxOK | wxICON_INFORMATION, this);
}

void MainFrame::OnOpen(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog * openFileDialog = new wxFileDialog(this);
    openFileDialog->SetWildcard(_("TXT files (*.txt)|*.txt"));
    openFileDialog->SetMessage(_("Choose a file"));
    
    if(openFileDialog->ShowModal() == wxID_OK)
    {
        wxString fileName = openFileDialog->GetPath();
    }
}

void MainFrame::OnClear(wxCommandEvent& WXUNUSED(event))
{
   
}


