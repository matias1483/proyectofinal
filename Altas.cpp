#include "Altas.h"

//(*InternalHeaders(Altas)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Altas)
const long Altas::ID_STATICTEXT1 = wxNewId();
const long Altas::ID_TEXTCTRL1 = wxNewId();
const long Altas::ID_STATICTEXT2 = wxNewId();
const long Altas::ID_STATICTEXT3 = wxNewId();
const long Altas::ID_TEXTCTRL2 = wxNewId();
const long Altas::ID_STATICTEXT4 = wxNewId();
const long Altas::ID_TEXTCTRL3 = wxNewId();
const long Altas::ID_STATICTEXT5 = wxNewId();
const long Altas::ID_TEXTCTRL4 = wxNewId();
const long Altas::ID_STATICTEXT6 = wxNewId();
const long Altas::ID_TEXTCTRL5 = wxNewId();
const long Altas::ID_STATICTEXT7 = wxNewId();
const long Altas::ID_TEXTCTRL6 = wxNewId();
const long Altas::ID_BUTTON1 = wxNewId();
const long Altas::ID_BUTTON2 = wxNewId();
const long Altas::ID_BUTTON3 = wxNewId();
const long Altas::ID_STATICTEXT8 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Altas,wxFrame)
	//(*EventTable(Altas)
	//*)
END_EVENT_TABLE()

Altas::Altas(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Altas)
	Create(parent, wxID_ANY, _("Altas"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetBackgroundColour(wxColour(255,255,128));
	st1 = new wxStaticText(this, ID_STATICTEXT1, _("Cod de Producto"), wxPoint(72,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	tc1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(200,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT2, _("Altas de Productos"), wxPoint(48,16), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText1->SetForegroundColour(wxColour(0,0,255));
	wxFont StaticText1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Blackoak Std"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	st2 = new wxStaticText(this, ID_STATICTEXT3, _("Descripcion"), wxPoint(72,88), wxSize(64,21), 0, _T("ID_STATICTEXT3"));
	tc2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(200,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	st3 = new wxStaticText(this, ID_STATICTEXT4, _("Existencia"), wxPoint(72,128), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	tc3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(200,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT5, _("Stock Minimo"), wxPoint(72,168), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	tc4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(200,168), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	st4 = new wxStaticText(this, ID_STATICTEXT6, _("Stock Maximo"), wxPoint(72,208), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	tc5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(200,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	st5 = new wxStaticText(this, ID_STATICTEXT7, _("Precio de Reposicion"), wxPoint(72,248), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	tc6 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(200,248), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Aceptar"), wxPoint(56,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Nuevo"), wxPoint(168,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button3 = new wxButton(this, ID_BUTTON3, _("Cerrar"), wxPoint(288,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	st6 = new wxStaticText(this, ID_STATICTEXT8, _("Estado:"), wxPoint(64,288), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	st6->SetForegroundColour(wxColour(0,128,0));
	wxFont st6Font(11,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("@Adobe Gothic Std B"),wxFONTENCODING_DEFAULT);
	st6->SetFont(st6Font);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Altas::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Altas::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Altas::OnButton3Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Altas::OnClose);
	//*)
}

Altas::~Altas()
{
	//(*Destroy(Altas)
	//*)
}
#include<fstream>
#include "Producto.h"
#include <wx/string.h>

void Altas::OnButton1Click(wxCommandEvent& event)
{
Producto reg,pro;
    fstream arch;
    int c;
    int ex;
    int sM;
    int sm;
    double pr ;
    wxString d;

    arch.open("producto.dat",ios::app|ios::binary);
    if(!arch)
    {
        st6->SetLabel("Error de apertura de archivo");
        Close();
    }
    arch.close();
    arch.open("producto.dat",ios::in|ios::out |ios::binary);
    if(!arch)
    {
        st6->SetLabel("Error de apertura de archivo");
        Close();
    }

    wxString str = tc1->GetValue();
    c=wxAtoi(str);
    d = tc2->GetValue();
    str = tc6->GetValue();
    str.ToDouble(&pr);
    pro.setCodP(c);
    pro.buscar(arch);
    if(!arch.eof())
            st6->SetLabel("Alta existente");
    else
        {
            arch.clear();
            reg.setCodP(c);
            reg.setDescripcion(d.ToStdString());
            reg.setExistencia(ex);
            reg.setStockMax(sM);
            reg.setStockMin(sm);
            reg.setPrecioR(pr);
            reg.setBorrado(0);
            arch.seekp(0,ios::end);
            arch.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));
            st6->SetLabel("Alta exitosa!!!!");
        }
    arch.close();
}

void Altas::OnClose(wxCloseEvent& event)
{
    Close();
}

void Altas::OnButton2Click(wxCommandEvent& event)
{
    st6->SetLabel("Estado:");
    tc1->Clear();
    tc2->Clear();
    tc3->Clear();
    tc4->Clear();
    tc5->Clear();
    tc6->Clear();
}

void Altas::OnButton3Click(wxCommandEvent& event)
{
    Close();
}
