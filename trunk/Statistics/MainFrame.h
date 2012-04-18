/* 
 * File:   MainFrame.h
 * Author: igormq
 *
 * Created on April 17, 2012, 3:56 PM
 */

#ifndef MAINFRAME_H
#define	MAINFRAME_H

#include "wx/wx.h"


class MainFrame: public wxFrame
{
public:

    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnClear(wxCommandEvent& event);
    enum
    {
        ID_Quit = 1,
        ID_Open,
        ID_Clear,
        ID_About,
    };
 private:
     wxMenu *menuFile;
     wxMenu *menuHelp;
     wxMenuBar *menuBar;
     wxTextCtrl *textCtrl;
     wxToolBar *toolBar;
     
    
    DECLARE_EVENT_TABLE()
};

#endif	/* MAINFRAME_H */

