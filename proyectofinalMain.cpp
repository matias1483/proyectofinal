/***************************************************************
 * Name:      proyectofinalMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2021-11-18
 * Copyright:  ()
 * License:
 **************************************************************/

#include "proyectofinalMain.h"
#include <wx/msgdlg.h>
#include"principal.h"

//(*InternalHeaders(proyectofinalFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(proyectofinalFrame)
const long proyectofinalFrame::ID_BUTTON1 = wxNewId();
const long proyectofinalFrame::ID_TEXTCTRL1 = wxNewId();
const long proyectofinalFrame::ID_STATICTEXT1 = wxNewId();
const long proyectofinalFrame::idMenuQuit = wxNewId();
const long proyectofinalFrame::idMenuAbout = wxNewId();
const long proyectofinalFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(proyectofinalFrame,wxFrame)
    //(*EventTable(proyectofinalFrame)
    //*)
END_EVENT_TABLE()

proyectofinalFrame::proyectofinalFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(proyectofinalFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("Inicio"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetForegroundColour(wxColour(0,0,0));
    SetBackgroundColour(wxColour(255,128,0));
    Button1 = new wxButton(this, ID_BUTTON1, _("Aceptar"), wxPoint(152,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetForegroundColour(wxColour(255,255,255));
    Button1->SetBackgroundColour(wxColour(0,0,255));
    wxFont Button1Font(11,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Century Schoolbook"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    tc = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(224,64), wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    st = new wxStaticText(this, ID_STATICTEXT1, _("Ingrese la contrasena"), wxPoint(24,64), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    st->SetForegroundColour(wxColour(0,0,255));
    wxFont stFont(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("@Adobe Gothic Std B"),wxFONTENCODING_DEFAULT);
    st->SetFont(stFont);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Salir\tAlt-F4"), _("Salir de la aplicación"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Archivo"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Acerca de \tF1"), _("Muestra informacion acerca de esta información"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Ayuda"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&proyectofinalFrame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&proyectofinalFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&proyectofinalFrame::OnAbout);
    //*)
}

proyectofinalFrame::~proyectofinalFrame()
{
    //(*Destroy(proyectofinalFrame)
    //*)
}

void proyectofinalFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void proyectofinalFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = "Muestra informacion ";
    wxMessageBox(msg, _("Bienvenidos"));
}

void proyectofinalFrame::OnButton1Click(wxCommandEvent& event)
{
    wxString entrada;
    entrada=tc->GetValue();
    if(entrada=="ingreso")
    {
        principal * frm=new principal(this);
        frm->Show();
    }
    else
    {
        st->SetLabel("Error. Clave incorrecta");
    }
}

