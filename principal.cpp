#include "principal.h"
#include"Altas.h"
#include<wx/msgdlg.h>
//(*InternalHeaders(principal)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(principal)
const long principal::ID_STATICTEXT1 = wxNewId();
const long principal::ID_MENUITEM1 = wxNewId();
const long principal::ID_MENUITEM2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(principal,wxFrame)
	//(*EventTable(principal)
	//*)
END_EVENT_TABLE()

principal::principal(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(principal)
	wxGridSizer* GridSizer1;

	Create(parent, wxID_ANY, _("Registro"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetBackgroundColour(wxColour(0,255,0));
	GridSizer1 = new wxGridSizer(0, 3, 0, 0);
	GridSizer1->Add(64,232,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	st = new wxStaticText(this, ID_STATICTEXT1, _("Registro de Productos"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	st->SetForegroundColour(wxColour(255,255,255));
	wxFont stFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Algerian"),wxFONTENCODING_DEFAULT);
	st->SetFont(stFont);
	GridSizer1->Add(st, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(GridSizer1);
	MenuBar1 = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Altas"), _("Altas de Productos"), wxITEM_NORMAL);
	Menu1->Append(MenuItem1);
	MenuBar1->Append(Menu1, _("Operaciones"));
	Menu2 = new wxMenu();
	MenuItem2 = new wxMenuItem(Menu2, ID_MENUITEM2, _("Listado de producto"), _("Listado de productos existentes"), wxITEM_NORMAL);
	Menu2->Append(MenuItem2);
	MenuBar1->Append(Menu2, _("Listados"));
	SetMenuBar(MenuBar1);
	GridSizer1->Fit(this);
	GridSizer1->SetSizeHints(this);

	Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&principal::OnMenualtasSelected);
	Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&principal::OnMenulistadoSelected);
	//*)
}

principal::~principal()
{
	//(*Destroy(principal)
	//*)
}
#include<fstream>
#include"Producto.h"
#include<iomanip>

void principal::OnMenualtasSelected(wxCommandEvent& event)
{
    Altas *frm=new Altas(this);
    frm->Show();
}

void principal::OnMenulistadoSelected(wxCommandEvent& event)
{
    wxString msg = "Listado de Productos";
    wxMessageBox(msg, _("Procesando..."));
    fstream arch;
    arch.open("producto.dat",ios::app|ios::binary);
    if(!arch)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR DE APERTURA"));
        Close();
    }
    arch.close();
    arch.open("producto.dat",ios::in|ios::out |ios::binary);
    if(!arch)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
        Close();
    }

    ofstream archt;
    Producto reg;
    archt.open("producto.txt",ios::out);
    if(!archt)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR DE APERTURA"));
    }
    archt<<left<<setw(10)<<"CodProd"<<setw(20)<<"Descripcion"<<setw(10)<<"Existencia"<<setw(20)<<"Stock Max"<<setw(20)<<"Stock Min"<<setw(20)<<"Precio de Rep"<<endl;

    arch.seekg(0);
    arch.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    while(!arch.eof())
    {
        archt<<left<<setw(10)<<reg.getCodP()<<setw(20)<<reg.getDescripcion()<<setw(10)<<reg.getExistencia()<<setw(20)<<reg.getStockMax()<<setw(20)<<reg.getStockMin()<<setw(20)<<setprecision(2)<<fixed<<reg.getPrecioR()<<endl;
        arch.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    }
    archt.close();
    arch.close();
}
