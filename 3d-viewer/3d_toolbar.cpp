/*******************************************************************/
/*	3d_toolbar.cpp: construction des tool bars de la frame visu 3d */
/*******************************************************************/

#include "fctsys.h"
#include "macros.h"

#include "bitmaps3d.h"
#include "bitmaps.h"

#include "id.h"

#define BITMAP wxBitmap
#include "3d_viewer.h"


/*********************************************/
void WinEDA3D_DrawFrame::ReCreateHToolbar()
/*********************************************/
{
    if( m_HToolBar != NULL )
    {           // simple mise a jour de la liste des fichiers anciens
        SetToolbars();
        return;
    }


    m_HToolBar = new WinEDA_Toolbar( TOOLBAR_MAIN, this, ID_H_TOOLBAR, TRUE );

    SetToolBar( m_HToolBar );

    // Set up toolbar
    m_HToolBar->AddTool( ID_RELOAD3D_BOARD, wxEmptyString, BITMAP( import3d_xpm ),
                        _( "Reload board" ) );
#ifdef __WINDOWS__  // do not work properly under linux
    m_HToolBar-> AddSeparator();

    m_HToolBar->AddTool( ID_TOOL_SCREENCOPY_TOCLIBBOARD, wxEmptyString, BITMAP( copy_button ),
                        _( "Copy 3D Image to Clipboard" ) );
#endif

    m_HToolBar->AddSeparator();
    m_HToolBar->AddTool( ID_ZOOM_IN_BUTT, wxEmptyString, BITMAP( zoom_in_xpm ),
                        _( "zoom + (F1)" ) );

    m_HToolBar->AddTool( ID_ZOOM_OUT_BUTT, wxEmptyString, BITMAP( zoom_out_xpm ),
                        _( "zoom - (F2)" ) );

    m_HToolBar->AddTool( ID_ZOOM_REDRAW_BUTT, wxEmptyString, BITMAP( repaint_xpm ),
                        _( "redraw (F3)" ) );

    m_HToolBar->AddTool( ID_ZOOM_PAGE_BUTT, wxEmptyString, BITMAP( zoom_optimal_xpm ),
                        _( "auto zoom" ) );

    m_HToolBar->AddSeparator();
    m_HToolBar->AddTool( ID_ROTATE3D_X_NEG, wxEmptyString, BITMAP( rotate_neg_X_xpm ),
                        _( "Rotate X <-" ) );

    m_HToolBar->AddTool( ID_ROTATE3D_X_POS, wxEmptyString, BITMAP( rotate_pos_X_xpm ),
                        _( "Rotate X ->" ) );

    m_HToolBar->AddSeparator();
    m_HToolBar->AddTool( ID_ROTATE3D_Y_NEG, wxEmptyString, BITMAP( rotate_neg_Y_xpm ),
                        _( "Rotate Y <-" ) );

    m_HToolBar->AddTool( ID_ROTATE3D_Y_POS, wxEmptyString, BITMAP( rotate_pos_Y_xpm ),
                        _( "Rotate Y ->" ) );

    m_HToolBar->AddSeparator();
    m_HToolBar->AddTool( ID_ROTATE3D_Z_NEG, wxEmptyString, BITMAP( rotate_neg_Z_xpm ),
                        _( "Rotate Z <-" ) );

    m_HToolBar->AddTool( ID_ROTATE3D_Z_POS, wxEmptyString, BITMAP( rotate_pos_Z_xpm ),
                        _( "Rotate Z ->" ) );

    m_HToolBar->AddSeparator();
    m_HToolBar->AddTool( ID_MOVE3D_LEFT, wxEmptyString, BITMAP( left_xpm ),
                        _( "Move left <-" ) );

    m_HToolBar->AddTool( ID_MOVE3D_RIGHT, wxEmptyString, BITMAP( right_xpm ),
                        _( "Move right ->" ) );

    m_HToolBar->AddTool( ID_MOVE3D_UP, wxEmptyString, BITMAP( up_xpm ),
                        _( "Move Up ^" ) );

    m_HToolBar->AddTool( ID_MOVE3D_DOWN, wxEmptyString, BITMAP( down_xpm ),
                        _( "Move Down" ) );


    m_HToolBar->Realize();

//	SetToolbars();
}


/*********************************************/
void WinEDA3D_DrawFrame::ReCreateVToolbar()
/*********************************************/
{
}


/**********************************************/
void WinEDA3D_DrawFrame::ReCreateMenuBar()
/**********************************************/
{
    wxMenuBar* menuBar = new wxMenuBar;

    wxMenu*    fileMenu = new wxMenu;

    menuBar->Append( fileMenu, _( "&File" ) );

    fileMenu->Append( ID_MENU_SCREENCOPY_PNG, _( "Create Image (png format)" ) );
    fileMenu->Append( ID_MENU_SCREENCOPY_JPEG, _( "Create Image (jpeg format)" ) );
    fileMenu->AppendSeparator();
    fileMenu->Append( wxID_EXIT, _( "&Exit" ) );

    wxMenu* referencesMenu = new wxMenu;
    menuBar->Append( referencesMenu, _( "&Preferences" ) );

    ADD_MENUITEM( referencesMenu, ID_MENU3D_BGCOLOR_SELECTION,
                  _( "Choose background color" ), palette_xpm );


    SetMenuBar( menuBar );
}


/*****************************************/
void WinEDA3D_DrawFrame::SetToolbars()
/*****************************************/
{
}
