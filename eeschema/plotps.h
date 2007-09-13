/////////////////////////////////////////////////////////////////////////////
// Name:        plotps.h
// Purpose:     
// Author:      jean-pierre Charras
// Modified by: 
// Created:     01/02/2006 08:37:24
// RCS-ID:      
// Copyright:   GNU License
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 01/02/2006 08:37:24

#ifndef _PLOTPS_H_
#define _PLOTPS_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "plotps.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/valgen.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxBoxSizer;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG 10000
#define ID_RADIOBOX1 10002
#define ID_RADIOBOX 10001
#define ID_CHECKBOX 10005
#define ID_PLOT_PS_CURRENT_EXECUTE 10003
#define ID_PLOT_PS_ALL_EXECUTE 10004
#define ID_TEXTCTRL 10006
// #define SYMBOL_WINEDA_PLOTPSFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxSTAY_ON_TOP|wxCLOSE_BOX
#define SYMBOL_WINEDA_PLOTPSFRAME_STYLE wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_WINEDA_PLOTPSFRAME_TITLE _("EESchema Plot PS")
#define SYMBOL_WINEDA_PLOTPSFRAME_IDNAME ID_DIALOG
#define SYMBOL_WINEDA_PLOTPSFRAME_SIZE wxSize(400, 300)
#define SYMBOL_WINEDA_PLOTPSFRAME_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * WinEDA_PlotPSFrame class declaration
 */

class WinEDA_PlotPSFrame: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( WinEDA_PlotPSFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    WinEDA_PlotPSFrame( );
    WinEDA_PlotPSFrame( wxWindow* parent, wxWindowID id = SYMBOL_WINEDA_PLOTPSFRAME_IDNAME, const wxString& caption = SYMBOL_WINEDA_PLOTPSFRAME_TITLE, const wxPoint& pos = SYMBOL_WINEDA_PLOTPSFRAME_POSITION, const wxSize& size = SYMBOL_WINEDA_PLOTPSFRAME_SIZE, long style = SYMBOL_WINEDA_PLOTPSFRAME_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_WINEDA_PLOTPSFRAME_IDNAME, const wxString& caption = SYMBOL_WINEDA_PLOTPSFRAME_TITLE, const wxPoint& pos = SYMBOL_WINEDA_PLOTPSFRAME_POSITION, const wxSize& size = SYMBOL_WINEDA_PLOTPSFRAME_SIZE, long style = SYMBOL_WINEDA_PLOTPSFRAME_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin WinEDA_PlotPSFrame event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PLOT_PS_CURRENT_EXECUTE
    void OnPlotPsCurrentExecuteClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PLOT_PS_ALL_EXECUTE
    void OnPlotPsAllExecuteClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CLOSE
    void OnCloseClick( wxCommandEvent& event );

////@end WinEDA_PlotPSFrame event handler declarations

////@begin WinEDA_PlotPSFrame member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end WinEDA_PlotPSFrame member function declarations

	void InitOptVars();
    void CreatePSFile(int AllPages, int pagesize);
    void PlotOneSheetPS(const wxString & FileName,
			BASE_SCREEN * screen, Ki_PageDescr * sheet, int BBox[4], wxPoint plot_offset);

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin WinEDA_PlotPSFrame member variables
    wxRadioBox* m_SizeOption;
    wxRadioBox* m_PlotPSColorOption;
    wxCheckBox* m_Plot_Sheet_Ref;
    wxBoxSizer* m_DefaultLineSizeCtrlSizer;
    wxTextCtrl* m_MsgBox;
////@end WinEDA_PlotPSFrame member variables
	WinEDA_ValueCtrl * m_DefaultLineSizeCtrl;
};

#endif
    // _PLOTPS_H_
