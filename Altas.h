#ifndef ALTAS_H
#define ALTAS_H

//(*Headers(Altas)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Altas: public wxFrame
{
	public:

		Altas(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Altas();

		//(*Declarations(Altas)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* st1;
		wxStaticText* st2;
		wxStaticText* st3;
		wxStaticText* st4;
		wxStaticText* st5;
		wxStaticText* st6;
		wxTextCtrl* tc1;
		wxTextCtrl* tc2;
		wxTextCtrl* tc3;
		wxTextCtrl* tc4;
		wxTextCtrl* tc5;
		wxTextCtrl* tc6;
		//*)

	protected:

		//(*Identifiers(Altas)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL6;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT8;
		//*)

	private:

		//(*Handlers(Altas)
		void OnButton1Click(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
