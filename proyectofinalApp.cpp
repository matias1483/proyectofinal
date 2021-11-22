/***************************************************************
 * Name:      proyectofinalApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2021-11-18
 * Copyright:  ()
 * License:
 **************************************************************/

#include "proyectofinalApp.h"

//(*AppHeaders
#include "proyectofinalMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(proyectofinalApp);

bool proyectofinalApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	proyectofinalFrame* Frame = new proyectofinalFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
