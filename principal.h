#ifndef PRINCIPAL_H
#define PRINCIPAL_H

//(*Headers(principal)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class principal: public wxFrame
{
	public:

		principal(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~principal();

		//(*Declarations(principal)
		wxMenu* Menu1;
		wxMenu* Menu2;
		wxMenuBar* MenuBar1;
		wxMenuItem* MenuItem1;
		wxMenuItem* MenuItem2;
		wxStaticText* st;
		//*)

	protected:

		//(*Identifiers(principal)
		static const long ID_STATICTEXT1;
		static const long ID_MENUITEM1;
		static const long ID_MENUITEM2;
		//*)

	private:

		//(*Handlers(principal)
		void OnMenualtasSelected(wxCommandEvent& event);
		void OnMenulistadoSelected(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
