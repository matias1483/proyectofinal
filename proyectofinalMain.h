/***************************************************************
 * Name:      proyectofinalMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2021-11-18
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef PROYECTOFINALMAIN_H
#define PROYECTOFINALMAIN_H

//(*Headers(proyectofinalFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class proyectofinalFrame: public wxFrame
{
    public:

        proyectofinalFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~proyectofinalFrame();

    private:

        //(*Handlers(proyectofinalFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(proyectofinalFrame)
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(proyectofinalFrame)
        wxButton* Button1;
        wxStaticText* st;
        wxStatusBar* StatusBar1;
        wxTextCtrl* tc;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PROYECTOFINALMAIN_H
