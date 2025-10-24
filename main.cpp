#include <wx/wx.h>
#include <wx/fileconf.h>
#include <wx/event.h>
#include "iconpool.h"
#include "snippets.h"

class MyApp final : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

class MyFrame final : public wxFrame
{
public:
    MyFrame();
    void LoadPreferences();

private:
    void OnFileNew(wxCommandEvent& event);
    void OnFileOpen(wxCommandEvent& event);
    void OnFileSave(wxCommandEvent& event);
    void OnFileSaveAs(wxCommandEvent& event);
    void OnEditCopy(wxCommandEvent& event);
    void OnEditCut(wxCommandEvent& event);
    void OnEditPaste(wxCommandEvent& event);
    void OnEditSelectAll(wxCommandEvent& event);
    void OnEditUndo(wxCommandEvent& event);
    void OnEditRedo(wxCommandEvent& event);
    void OnEditPreferences(wxCommandEvent& event);
    void OnFileExit(wxCommandEvent& event);
    void OnHelpAbout(wxCommandEvent& event);

    void OnClose(wxCloseEvent& event);
    void SavePreferences();

    const int toolBarIconSize = 18;
};

bool MyApp::OnInit()
{
    // ReSharper disable once CppDFAMemoryLeak
    auto *frame = new MyFrame();
    frame->SetIcon(wxICON(sample));
    frame->Show(true);
    frame->LoadPreferences();
    return true;
}

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, wxString($APP_TITLE))
{
    // ReSharper disable once CppDFAMemoryLeak
    auto *menuFile = new wxMenu;
    menuFile->Append(wxID_NEW, $MENU_FILE_NEW, $TIP_FILE_NEW);
    menuFile->Append(wxID_OPEN, $MENU_FILE_OPEN, $TIP_FILE_OPEN);
    menuFile->Append(wxID_SAVE, $MENU_FILE_SAVE, $TIP_FILE_SAVE);
    menuFile->Append(wxID_SAVEAS, $MENU_FILE_SAVE_AS, $TIP_FILE_SAVE_AS);
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT, $MENU_FILE_EXIT, $TIP_FILE_EXIT);
    // ReSharper disable once CppDFAMemoryLeak
    auto *menuEdit = new wxMenu;
    menuEdit->Append(wxID_COPY, $MENU_EDIT_COPY, $TIP_EDIT_COPY);
    menuEdit->Append(wxID_CUT, $MENU_EDIT_CUT, $TIP_EDIT_CUT);
    menuEdit->Append(wxID_PASTE, $MENU_EDIT_PASTE, $TIP_EDIT_PASTE);
    menuEdit->AppendSeparator();
    menuEdit->Append(wxID_SELECTALL, $MENU_EDIT_SELECT_ALL, $TIP_EDIT_SELECT_ALL);
    menuEdit->AppendSeparator();
    menuEdit->Append(wxID_UNDO, $MENU_EDIT_UNDO, $TIP_EDIT_UNDO);
    menuEdit->Append(wxID_REDO, $MENU_EDIT_REDO, $TIP_EDIT_REDO);
    menuEdit->AppendSeparator();
    menuEdit->Append(wxID_PREFERENCES, $MENU_EDIT_PREFERENCES, $TIP_EDIT_PREFERENCES);
    // ReSharper disable once CppDFAMemoryLeak
    auto *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT, $MENU_HELP_ABOUT, $TIP_HELP_ABOUT);
    // ReSharper disable once CppDFAMemoryLeak
    auto *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, $MENU_FILE);
    menuBar->Append(menuEdit, $MENU_EDIT);
    menuBar->Append(menuHelp, $MENU_HELP);
    wxFrameBase::SetMenuBar(menuBar);
    wxFrameBase::CreateStatusBar();
    wxFrameBase::SetStatusText($WELCOME);
    Bind(wxEVT_MENU, &MyFrame::OnFileNew, this, wxID_NEW);
    Bind(wxEVT_MENU, &MyFrame::OnFileOpen, this, wxID_OPEN);
    Bind(wxEVT_MENU, &MyFrame::OnFileSave, this, wxID_SAVE);
    Bind(wxEVT_MENU, &MyFrame::OnFileSaveAs, this, wxID_SAVEAS);
    Bind(wxEVT_MENU, &MyFrame::OnEditCopy, this, wxID_COPY);
    Bind(wxEVT_MENU, &MyFrame::OnEditCut, this, wxID_CUT);
    Bind(wxEVT_MENU, &MyFrame::OnEditPaste, this, wxID_PASTE);
    Bind(wxEVT_MENU, &MyFrame::OnEditSelectAll, this, wxID_SELECTALL);
    Bind(wxEVT_MENU, &MyFrame::OnEditUndo, this, wxID_UNDO);
    Bind(wxEVT_MENU, &MyFrame::OnEditRedo, this, wxID_REDO);
    Bind(wxEVT_MENU, &MyFrame::OnEditPreferences, this, wxID_PREFERENCES);
    Bind(wxEVT_MENU, &MyFrame::OnHelpAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnFileExit, this, wxID_EXIT);
    // ReSharper disable once CppDFAMemoryLeak
    auto* sizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(sizer);
    // ReSharper disable once CppDFAMemoryLeak
    auto* toolBar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                       wxNO_BORDER|wxTB_FLAT|wxTB_NODIVIDER|wxTB_NOALIGN);
    sizer->Add(toolBar, 0, wxEXPAND);
    toolBar->AddTool(wxID_NEW, wxEmptyString,
        IconPool::getBitmapBundleByName("FILE_NEW", toolBarIconSize), $TIP_FILE_NEW);
    toolBar->AddTool(wxID_OPEN, wxEmptyString,
        IconPool::getBitmapBundleByName("FILE_OPEN", toolBarIconSize), $TIP_FILE_OPEN);
    toolBar->AddTool(wxID_SAVE, wxEmptyString,
        IconPool::getBitmapBundleByName("FILE_SAVE", toolBarIconSize), $TIP_FILE_SAVE);
    toolBar->AddTool(wxID_SAVEAS, wxEmptyString,
        IconPool::getBitmapBundleByName("FILE_SAVE_AS", toolBarIconSize), $TIP_FILE_SAVE_AS);
    toolBar->AddSeparator();
    toolBar->AddTool(wxID_COPY, wxEmptyString,
        IconPool::getBitmapBundleByName("EDIT_COPY", toolBarIconSize), $TIP_EDIT_COPY);
    toolBar->AddTool(wxID_CUT, wxEmptyString,
        IconPool::getBitmapBundleByName("EDIT_CUT", toolBarIconSize), $TIP_EDIT_CUT);
    toolBar->AddTool(wxID_PASTE, wxEmptyString,
        IconPool::getBitmapBundleByName("EDIT_PASTE", toolBarIconSize), $TIP_EDIT_PASTE);
    toolBar->AddTool(wxID_SELECTALL, wxEmptyString,
        IconPool::getBitmapBundleByName("EDIT_SELECT_ALL", toolBarIconSize), $TIP_EDIT_SELECT_ALL);
    toolBar->AddSeparator();
    toolBar->AddTool(wxID_UNDO, wxEmptyString,
        IconPool::getBitmapBundleByName("EDIT_UNDO", toolBarIconSize), $TIP_EDIT_UNDO);
    toolBar->AddTool(wxID_REDO, wxEmptyString,
        IconPool::getBitmapBundleByName("EDIT_REDO", toolBarIconSize), $TIP_EDIT_REDO);

    toolBar->AddStretchableSpace();
    toolBar->AddTool(wxID_ABOUT, wxEmptyString,
        IconPool::getBitmapBundleByName("HELP_INFO", toolBarIconSize), $TIP_HELP_ABOUT);
    toolBar->AddTool(wxID_EXIT, wxEmptyString,
        IconPool::getBitmapBundleByName("FILE_QUIT_2", toolBarIconSize), $TIP_FILE_EXIT);
    toolBar->Realize();
    Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);

}

void MyFrame::OnFileNew(wxCommandEvent& event)
{
    wxLogMessage("File New");
}
void MyFrame::OnFileOpen(wxCommandEvent& event)
{
    wxLogMessage("Open file");
}
void MyFrame::OnFileSave(wxCommandEvent& event)
{
    wxLogMessage("Save file");
}
void MyFrame::OnFileSaveAs(wxCommandEvent& event)
{
    wxLogMessage("Save file as");
}
void MyFrame::OnFileExit(wxCommandEvent& event)
{
    Close(false);
}
void MyFrame::OnEditCopy(wxCommandEvent& event)
{
    wxLogMessage("Edit copy");
}
void MyFrame::OnEditCut(wxCommandEvent& event)
{
    wxLogMessage("Edit cut");
}
void MyFrame::OnEditPaste(wxCommandEvent& event)
{
    wxLogMessage("Edit paste");
}
void MyFrame::OnEditSelectAll(wxCommandEvent& event)
{
    wxLogMessage("Select all");
}
void MyFrame::OnEditUndo(wxCommandEvent& event)
{
    wxLogMessage("Undo");
}
void MyFrame::OnEditRedo(wxCommandEvent& event)
{
    wxLogMessage("Redo");
}
void MyFrame::OnEditPreferences(wxCommandEvent& event)
{
    wxLogMessage("Preferences");
}
void MyFrame::OnHelpAbout(wxCommandEvent& event)
{
    wxMessageBox($TEXT_ABOUT, $TIP_HELP_ABOUT, wxOK | wxICON_INFORMATION);
}

void MyFrame::OnClose(wxCloseEvent& event)
{
    SavePreferences();
    Destroy();
}

void MyFrame::SavePreferences()
{
    const auto pos = this->GetPosition();
    const auto size = this->GetSize();
    auto *config = new wxFileConfig($APP_NAME,
        $APP_VENDOR, "", "", wxCONFIG_USE_LOCAL_FILE);
    config->Write(wxString($CONFIG_WINDOW_SIZE_X), size.x);
    config->Write(wxString($CONFIG_WINDOW_SIZE_Y), size.y);
    config->Write(wxString($CONFIG_WINDOW_POSITION_X), pos.x);
    config->Write(wxString($CONFIG_WINDOW_POSITION_Y), pos.y);
    config->Flush();
    delete config;
}
void MyFrame::LoadPreferences() {
    auto *config = new wxFileConfig($APP_NAME,
        $APP_VENDOR, "", "", wxCONFIG_USE_LOCAL_FILE);
    const long sx = config->ReadLong($CONFIG_WINDOW_SIZE_X, wxDefaultSize.GetX());
    const long sy = config->ReadLong($CONFIG_WINDOW_SIZE_Y, wxDefaultSize.GetY());
    const long px = config->ReadLong($CONFIG_WINDOW_POSITION_X, wxDefaultPosition.x);
    const long py = config->ReadLong($CONFIG_WINDOW_POSITION_Y, wxDefaultPosition.y);
    Move(wxPoint(px, py));
    SetSize(wxSize(sx, sy));
    delete config;
}
