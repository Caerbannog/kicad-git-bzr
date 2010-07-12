/////////////////////////////////////////////////////////////////////////////
// Name:        plothpgl.cpp
// Purpose:
// Author:      jean-pierre Charras
// Modified by:
// Created:     04/02/2006 16:54:19
// RCS-ID:
// Copyright:   License GNU
// License:
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 04/02/2006 16:54:19

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "plothpgl.h"
#endif

////@begin includes
////@end includes

#include "fctsys.h"
#include "gr_basic.h"
#include "common.h"
#include "confirm.h"
#include "plot_common.h"
#include "worksheet.h"

#include "program.h"
#include "general.h"
#include "protos.h"
#include "plothpgl.h"


////@begin XPM images
////@end XPM images

FILE* PlotOutput;
int   HPGL_SizeSelect;

enum PageFormatReq
{
    PAGE_DEFAULT = 0,
    PAGE_SIZE_A4,
    PAGE_SIZE_A3,
    PAGE_SIZE_A2,
    PAGE_SIZE_A1,
    PAGE_SIZE_A0,
    PAGE_SIZE_A,
    PAGE_SIZE_B,
    PAGE_SIZE_C,
    PAGE_SIZE_D,
    PAGE_SIZE_E
};

static Ki_PageDescr* Plot_sheet_list[] =
{
    NULL,
    &g_Sheet_A4,
    &g_Sheet_A3,
    &g_Sheet_A2,
    &g_Sheet_A1,
    &g_Sheet_A0,
    &g_Sheet_A,
    &g_Sheet_B,
    &g_Sheet_C,
    &g_Sheet_D,
    &g_Sheet_E,
    &g_Sheet_GERBER,
    &g_Sheet_user
};


void WinEDA_SchematicFrame::ToPlot_HPGL( wxCommandEvent& event )
{
    WinEDA_PlotHPGLFrame* HPGL_frame = new WinEDA_PlotHPGLFrame( this );

    HPGL_frame->ShowModal();
    HPGL_frame->Destroy();
}


/*!
 * WinEDA_PlotHPGLFrame type definition
 */

IMPLEMENT_DYNAMIC_CLASS( WinEDA_PlotHPGLFrame, wxDialog )

/*!
 * WinEDA_PlotHPGLFrame event table definition
 */

BEGIN_EVENT_TABLE( WinEDA_PlotHPGLFrame, wxDialog )

////@begin WinEDA_PlotHPGLFrame event table entries
    EVT_RADIOBOX( ID_RADIOBOX, WinEDA_PlotHPGLFrame::OnRadioboxSelected )

    EVT_SPINCTRL( ID_PEN_WIDTH_UPDATED,
                  WinEDA_PlotHPGLFrame::OnPenWidthUpdatedUpdated )

    EVT_SPINCTRL( ID_PEN_SPEED_UPDATED,
                  WinEDA_PlotHPGLFrame::OnPenSpeedUpdatedUpdated )

    EVT_SPINCTRL( ID_PEN_NUMBER_UPDATED,
                  WinEDA_PlotHPGLFrame::OnPenNumberUpdatedUpdated )

    EVT_BUTTON( ID_PLOT_HPGL_CURRENT_EXECUTE,
                WinEDA_PlotHPGLFrame::OnPlotHpglCurrentExecuteClick )

    EVT_BUTTON( ID_PLOT_HPGL_ALL_EXECUTE,
                WinEDA_PlotHPGLFrame::OnPlotHpglAllExecuteClick )

    EVT_BUTTON( wxID_CANCEL, WinEDA_PlotHPGLFrame::OnCancelClick )

    EVT_BUTTON( ID_PLOT_ACCEPT_OFFSET,
                WinEDA_PlotHPGLFrame::OnPlotAcceptOffsetClick )

////@end WinEDA_PlotHPGLFrame event table entries

END_EVENT_TABLE()
/*!
 * WinEDA_PlotHPGLFrame constructors
 */

WinEDA_PlotHPGLFrame::WinEDA_PlotHPGLFrame()
{
}


WinEDA_PlotHPGLFrame::WinEDA_PlotHPGLFrame( WinEDA_DrawFrame* parent,
                                            wxWindowID        id,
                                            const wxString&   caption,
                                            const wxPoint&    pos,
                                            const wxSize&     size,
                                            long              style )
{
    m_Parent = parent;
    Create( parent, id, caption, pos, size, style );
    SetPageOffsetValue();
}


/*!
 * WinEDA_PlotHPGLFrame creator
 */

bool WinEDA_PlotHPGLFrame::Create( wxWindow*       parent,
                                   wxWindowID      id,
                                   const wxString& caption,
                                   const wxPoint&  pos,
                                   const wxSize&   size,
                                   long            style )
{
////@begin WinEDA_PlotHPGLFrame member initialization
    m_SizeOption   = NULL;
    m_ButtPenWidth = NULL;
    m_ButtPenSpeed = NULL;
    m_ButtPenNum   = NULL;
    m_PlotOrgPosition_X = NULL;
    m_PlotOrgPosition_Y = NULL;
    m_btClose = NULL;
    m_MsgBox  = NULL;

////@end WinEDA_PlotHPGLFrame member initialization

////@begin WinEDA_PlotHPGLFrame creation
    SetExtraStyle( wxWS_EX_BLOCK_EVENTS );
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if( GetSizer() )
    {
        GetSizer()->SetSizeHints( this );
    }
    Centre();

////@end WinEDA_PlotHPGLFrame creation
    return true;
}


/*!
 * Control creation for WinEDA_PlotHPGLFrame
 */

void WinEDA_PlotHPGLFrame::CreateControls()
{
////@begin WinEDA_PlotHPGLFrame content construction
    // Generated by DialogBlocks, 24/04/2009 14:24:58 (unregistered)

    WinEDA_PlotHPGLFrame* itemDialog1 = this;

    wxBoxSizer*           itemBoxSizer2 = new wxBoxSizer( wxVERTICAL );

    itemDialog1->SetSizer( itemBoxSizer2 );

    wxBoxSizer*   itemBoxSizer3 = new wxBoxSizer( wxHORIZONTAL );
    itemBoxSizer2->Add( itemBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5 );

    wxBoxSizer*   itemBoxSizer4 = new wxBoxSizer( wxVERTICAL );
    itemBoxSizer3->Add( itemBoxSizer4, 0, wxGROW | wxALL, 5 );

    wxArrayString m_SizeOptionStrings;
    m_SizeOptionStrings.Add( _( "Sheet Size" ) );
    m_SizeOptionStrings.Add( _( "Page Size A4" ) );
    m_SizeOptionStrings.Add( _( "Page Size A3" ) );
    m_SizeOptionStrings.Add( _( "Page Size A2" ) );
    m_SizeOptionStrings.Add( _( "Page Size A1" ) );
    m_SizeOptionStrings.Add( _( "Page Size A0" ) );
    m_SizeOptionStrings.Add( _( "Page Size A" ) );
    m_SizeOptionStrings.Add( _( "Page Size B" ) );
    m_SizeOptionStrings.Add( _( "Page Size C" ) );
    m_SizeOptionStrings.Add( _( "Page Size D" ) );
    m_SizeOptionStrings.Add( _( "Page Size E" ) );
    m_SizeOption =
        new wxRadioBox( itemDialog1, ID_RADIOBOX, _( "Plot page size:" ),
                        wxDefaultPosition, wxDefaultSize, m_SizeOptionStrings,
                        1, wxRA_SPECIFY_COLS );
    m_SizeOption->SetSelection( 0 );
    itemBoxSizer4->Add( m_SizeOption, 0, wxALIGN_LEFT | wxALL, 5 );

    wxBoxSizer*       itemBoxSizer6 = new wxBoxSizer( wxVERTICAL );
    itemBoxSizer3->Add( itemBoxSizer6, 0, wxALIGN_TOP | wxALL, 5 );

    wxStaticBox*      itemStaticBoxSizer7Static =
        new wxStaticBox( itemDialog1, wxID_ANY, _( "Pen control:" ) );
    wxStaticBoxSizer* itemStaticBoxSizer7 =
        new wxStaticBoxSizer( itemStaticBoxSizer7Static, wxVERTICAL );
    itemBoxSizer6->Add( itemStaticBoxSizer7,
                        0,
                        wxALIGN_CENTER_HORIZONTAL | wxALL,
                        5 );

    wxStaticText* itemStaticText8 = new wxStaticText( itemDialog1,
                                                      wxID_STATIC,
                                                      _( "Pen Width ( mils )" ),
                                                      wxDefaultPosition,
                                                      wxDefaultSize,
                                                      0 );
    itemStaticBoxSizer7->Add(
        itemStaticText8,
        0,
        wxALIGN_LEFT | wxLEFT | wxRIGHT | wxTOP |
        wxADJUST_MINSIZE,
        5 );

    m_ButtPenWidth =
        new wxSpinCtrl( itemDialog1, ID_PEN_WIDTH_UPDATED, _T( "1" ),
                        wxDefaultPosition, wxDefaultSize,
                        wxSP_ARROW_KEYS | wxSP_WRAP, 1, 100, 1 );
    itemStaticBoxSizer7->Add( m_ButtPenWidth,
                              0,
                              wxALIGN_LEFT | wxLEFT | wxRIGHT | wxBOTTOM,
                              5 );

    wxStaticText* itemStaticText10 = new wxStaticText( itemDialog1,
                                                       wxID_STATIC,
                                                       _( "Pen Speed ( cm/s )" ),
                                                       wxDefaultPosition,
                                                       wxDefaultSize,
                                                       0 );
    itemStaticBoxSizer7->Add( itemStaticText10,
                              0,
                              wxALIGN_LEFT | wxLEFT | wxRIGHT | wxTOP |
                              wxADJUST_MINSIZE,
                              5 );

    m_ButtPenSpeed =
        new wxSpinCtrl( itemDialog1, ID_PEN_SPEED_UPDATED, _T( "1" ),
                        wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS,
                        1, 100, 1 );
    itemStaticBoxSizer7->Add( m_ButtPenSpeed,
                              0,
                              wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT |
                              wxBOTTOM,
                              5 );

    wxStaticText* itemStaticText12 = new wxStaticText( itemDialog1,
                                                       wxID_STATIC,
                                                       _( "Pen Number" ),
                                                       wxDefaultPosition,
                                                       wxDefaultSize,
                                                       0 );
    itemStaticBoxSizer7->Add( itemStaticText12,
                              0,
                              wxALIGN_LEFT | wxLEFT | wxRIGHT | wxTOP |
                              wxADJUST_MINSIZE,
                              5 );

    m_ButtPenNum = new wxSpinCtrl( itemDialog1, ID_PEN_NUMBER_UPDATED,
                                   _T( "1" ), wxDefaultPosition, wxDefaultSize,
                                   wxSP_ARROW_KEYS, 1, 8, 1 );
    itemStaticBoxSizer7->Add( m_ButtPenNum,
                              0,
                              wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT |
                              wxBOTTOM,
                              5 );

    wxStaticBox*      itemStaticBoxSizer14Static =
        new wxStaticBox( itemDialog1, wxID_ANY, _( "Page offset:" ) );
    wxStaticBoxSizer* itemStaticBoxSizer14 =
        new wxStaticBoxSizer( itemStaticBoxSizer14Static, wxVERTICAL );
    itemBoxSizer6->Add( itemStaticBoxSizer14, 0, wxALIGN_LEFT | wxALL, 5 );

    wxStaticText* itemStaticText15 = new wxStaticText( itemDialog1,
                                                       wxID_STATIC,
                                                       _( "Plot Offset X" ),
                                                       wxDefaultPosition,
                                                       wxDefaultSize,
                                                       0 );
    itemStaticBoxSizer14->Add( itemStaticText15,
                               0,
                               wxALIGN_LEFT | wxLEFT | wxRIGHT | wxTOP |
                               wxADJUST_MINSIZE,
                               5 );

    m_PlotOrgPosition_X = new wxTextCtrl( itemDialog1, ID_TEXTCTRL1,
                                          _T( "" ), wxDefaultPosition,
                                          wxDefaultSize, 0 );
    itemStaticBoxSizer14->Add( m_PlotOrgPosition_X,
                               0,
                               wxALIGN_LEFT | wxLEFT | wxRIGHT | wxBOTTOM,
                               5 );

    wxStaticText* itemStaticText17 = new wxStaticText( itemDialog1,
                                                       wxID_STATIC,
                                                       _( "Plot Offset Y" ),
                                                       wxDefaultPosition,
                                                       wxDefaultSize,
                                                       0 );
    itemStaticBoxSizer14->Add( itemStaticText17,
                               0,
                               wxALIGN_LEFT | wxLEFT | wxRIGHT | wxTOP |
                               wxADJUST_MINSIZE,
                               5 );

    m_PlotOrgPosition_Y = new wxTextCtrl( itemDialog1, ID_TEXTCTRL2, _T( "" ),
                                          wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer14->Add( m_PlotOrgPosition_Y,
                               0,
                               wxALIGN_LEFT | wxLEFT | wxRIGHT | wxBOTTOM,
                               5 );

    itemBoxSizer3->Add( 5, 5, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );

    wxBoxSizer* itemBoxSizer20 = new wxBoxSizer( wxVERTICAL );
    itemBoxSizer3->Add( itemBoxSizer20,
                        0,
                        wxALIGN_TOP | wxLEFT | wxTOP | wxBOTTOM,
                        5 );

    wxButton* itemButton21 = new wxButton( itemDialog1,
                                           ID_PLOT_HPGL_CURRENT_EXECUTE,
                                           _( "&Plot Page" ),
                                           wxDefaultPosition,
                                           wxDefaultSize,
                                           0 );
    itemButton21->SetDefault();
    itemBoxSizer20->Add( itemButton21, 0, wxGROW | wxALL, 5 );

    wxButton* itemButton22 = new wxButton( itemDialog1,
                                           ID_PLOT_HPGL_ALL_EXECUTE,
                                           _( "Plot A&LL" ),
                                           wxDefaultPosition,
                                           wxDefaultSize,
                                           0 );
    itemBoxSizer20->Add( itemButton22, 0, wxGROW | wxALL, 5 );

    m_btClose = new wxButton( itemDialog1, wxID_CANCEL, _( "&Close" ),
                              wxDefaultPosition, wxDefaultSize,
                              0 );
    itemBoxSizer20->Add( m_btClose, 0, wxGROW | wxALL, 5 );

    itemBoxSizer20->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5 );

    wxButton* itemButton25 = new wxButton( itemDialog1,
                                           ID_PLOT_ACCEPT_OFFSET,
                                           _( "&Accept Offset" ),
                                           wxDefaultPosition,
                                           wxDefaultSize,
                                           0 );
    itemBoxSizer20->Add( itemButton25, 0, wxGROW | wxALL, 5 );

    m_MsgBox = new wxTextCtrl( itemDialog1, ID_TEXTCTRL, _T( "" ),
                               wxDefaultPosition, wxSize( -1, 110 ),
                               wxTE_MULTILINE );
    itemBoxSizer2->Add( m_MsgBox, 0, wxGROW | wxALL, 5 );

    // Set validators
    m_SizeOption->SetValidator( wxGenericValidator( &HPGL_SizeSelect ) );
    m_ButtPenWidth->SetValidator( wxGenericValidator( &g_HPGL_Pen_Descr.
                                                      m_Pen_Diam ) );
    m_ButtPenSpeed->SetValidator( wxGenericValidator( &g_HPGL_Pen_Descr.
                                                      m_Pen_Speed ) );
    m_ButtPenNum->SetValidator( wxGenericValidator( &g_HPGL_Pen_Descr.
                                                    m_Pen_Num ) );

////@end WinEDA_PlotHPGLFrame content construction
    SetFocus(); // Make ESC key working
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PLOT_HPGL_CURRENT_EXECUTE
 */

void WinEDA_PlotHPGLFrame::OnPlotHpglCurrentExecuteClick(
    wxCommandEvent& event )
{
    HPGL_Plot( event );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PLOT_HPGL_ALL_EXECUTE
 */

void WinEDA_PlotHPGLFrame::OnPlotHpglAllExecuteClick( wxCommandEvent& event )
{
    HPGL_Plot( event );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void WinEDA_PlotHPGLFrame::OnCancelClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in
// WinEDA_PlotHPGLFrame.
    // Before editing this code, remove the block markers.
    event.Skip();

////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in
// WinEDA_PlotHPGLFrame.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PLOT_ACCEPT_OFFSET
 */

void WinEDA_PlotHPGLFrame::OnPlotAcceptOffsetClick( wxCommandEvent& event )
{
    AcceptPlotOffset( event );
}


/*!
 * Should we show tooltips?
 */

bool WinEDA_PlotHPGLFrame::ShowToolTips()
{
    return true;
}


/*!
 * Get bitmap resources
 */

wxBitmap WinEDA_PlotHPGLFrame::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin WinEDA_PlotHPGLFrame bitmap retrieval
    wxUnusedVar( name );
    return wxNullBitmap;

////@end WinEDA_PlotHPGLFrame bitmap retrieval
}


/*!
 * Get icon resources
 */

wxIcon WinEDA_PlotHPGLFrame::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin WinEDA_PlotHPGLFrame icon retrieval
    wxUnusedVar( name );
    return wxNullIcon;

////@end WinEDA_PlotHPGLFrame icon retrieval
}


void WinEDA_PlotHPGLFrame::SetPageOffsetValue()
{
    wxString msg;

    if( HPGL_SizeSelect != PAGE_DEFAULT )
    {
        msg = ReturnStringFromValue( g_UserUnit,
                                     Plot_sheet_list[HPGL_SizeSelect]->m_Offset.x,
                                     EESCHEMA_INTERNAL_UNIT );
        m_PlotOrgPosition_X->SetValue( msg );
        msg = ReturnStringFromValue( g_UserUnit,
                                     Plot_sheet_list[HPGL_SizeSelect]-> m_Offset.y,
                                     EESCHEMA_INTERNAL_UNIT );
        m_PlotOrgPosition_Y->SetValue( msg );

        m_PlotOrgPosition_X->Enable( TRUE );
        m_PlotOrgPosition_Y->Enable( TRUE );
    }
    else
    {
        m_PlotOrgPosition_X->Enable( FALSE );
        m_PlotOrgPosition_Y->Enable( FALSE );
    }
}


void WinEDA_PlotHPGLFrame::AcceptPlotOffset( wxCommandEvent& event )
{
    int ii = m_SizeOption->GetSelection();

    if( ii <= 0 )
        HPGL_SizeSelect = 0;
    else
        HPGL_SizeSelect = ii;

    if( HPGL_SizeSelect != PAGE_DEFAULT )
    {
        wxString msg = m_PlotOrgPosition_X->GetValue();
        Plot_sheet_list[HPGL_SizeSelect]->m_Offset.x =
            ReturnValueFromString( g_UserUnit, msg, EESCHEMA_INTERNAL_UNIT );
        msg = m_PlotOrgPosition_Y->GetValue();
        Plot_sheet_list[HPGL_SizeSelect]->m_Offset.y =
            ReturnValueFromString( g_UserUnit, msg, EESCHEMA_INTERNAL_UNIT );
    }
}


void WinEDA_PlotHPGLFrame::SetPenWidth( wxSpinEvent& event )
{
    g_HPGL_Pen_Descr.m_Pen_Diam = m_ButtPenWidth->GetValue();
    if( g_HPGL_Pen_Descr.m_Pen_Diam > 100 )
        g_HPGL_Pen_Descr.m_Pen_Diam = 100;
    if( g_HPGL_Pen_Descr.m_Pen_Diam < 1 )
        g_HPGL_Pen_Descr.m_Pen_Diam = 1;
}


void WinEDA_PlotHPGLFrame::SetPenSpeed( wxSpinEvent& event )
{
    g_HPGL_Pen_Descr.m_Pen_Speed = m_ButtPenSpeed->GetValue();
    if( g_HPGL_Pen_Descr.m_Pen_Speed > 40 )
        g_HPGL_Pen_Descr.m_Pen_Speed = 40;
    if( g_HPGL_Pen_Descr.m_Pen_Speed < 1 )
        g_HPGL_Pen_Descr.m_Pen_Speed = 1;
}


void WinEDA_PlotHPGLFrame::SetPenNum( wxSpinEvent& event )
{
    g_HPGL_Pen_Descr.m_Pen_Num = m_ButtPenNum->GetValue();
    if( g_HPGL_Pen_Descr.m_Pen_Num > 8 )
        g_HPGL_Pen_Descr.m_Pen_Num = 8;
    if( g_HPGL_Pen_Descr.m_Pen_Num < 1 )
        g_HPGL_Pen_Descr.m_Pen_Num = 1;
}


void WinEDA_PlotHPGLFrame::HPGL_Plot( wxCommandEvent& event )
{
    int Select_PlotAll = FALSE;

    if( event.GetId() == ID_PLOT_HPGL_ALL_EXECUTE )
        Select_PlotAll = TRUE;

    if( HPGL_SizeSelect )
    {
        wxString msg = m_PlotOrgPosition_X->GetValue();
        Plot_sheet_list[HPGL_SizeSelect]->m_Offset.x =
            ReturnValueFromString( g_UserUnit, msg, EESCHEMA_INTERNAL_UNIT );
        msg = m_PlotOrgPosition_Y->GetValue();
        Plot_sheet_list[HPGL_SizeSelect]->m_Offset.y =
            ReturnValueFromString( g_UserUnit, msg, EESCHEMA_INTERNAL_UNIT );
    }

    Plot_Schematic_HPGL( Select_PlotAll, HPGL_SizeSelect );
}


/* Function calculates the offsets and dimensions of any trace of the
 * selected sheet
 */
void WinEDA_PlotHPGLFrame::ReturnSheetDims( BASE_SCREEN* screen,
                                            wxSize&      SheetSize,
                                            wxPoint&     SheetOffset )
{
    Ki_PageDescr* PlotSheet;

    if( screen == NULL )
        screen = m_Parent->GetBaseScreen();

    PlotSheet = screen->m_CurrentSheetDesc;

    SheetSize   = PlotSheet->m_Size;
    SheetOffset = PlotSheet->m_Offset;
}


void WinEDA_PlotHPGLFrame::Plot_Schematic_HPGL( int Select_PlotAll,
                                                int HPGL_SheetSize )
{
    WinEDA_SchematicFrame* schframe = (WinEDA_SchematicFrame*) m_Parent;
    wxString               PlotFileName;
    SCH_SCREEN*            screen    = schframe->GetScreen();
    SCH_SCREEN*            oldscreen = screen;
    SCH_SHEET_PATH*        sheetpath, * oldsheetpath = schframe->GetSheet();
    Ki_PageDescr*          PlotSheet;
    wxSize                 SheetSize;
    wxPoint                SheetOffset, PlotOffset;

    /* When printing all pages, the printed page is not the current page.
     *  In complex hierarchies, we must setup references and others parameters
     *  in the printed SCH_SCREEN
     *  because in complex hierarchies a SCH_SCREEN (a schematic drawings)
     *  is shared between many sheets
     */
    SCH_SHEET_LIST SheetList( NULL );

    sheetpath = SheetList.GetFirst();
    SCH_SHEET_PATH list;

    while( true )
    {
        if( Select_PlotAll )
        {
            if( sheetpath == NULL )
                break;
            list.Clear();
            if( list.BuildSheetPathInfoFromSheetPathValue( sheetpath->Path() ) )
            {
                schframe->m_CurrentSheet = &list;
                schframe->m_CurrentSheet->UpdateAllScreenReferences();
                schframe->SetSheetNumberAndCount();
                screen = schframe->m_CurrentSheet->LastScreen();
                ActiveScreen = screen;
            }
            else  // Should not happen
                return;
            sheetpath = SheetList.GetNext();
        }
        ReturnSheetDims( screen, SheetSize, SheetOffset );
        /* Calculation of conversion scales. */
        if( HPGL_SheetSize )
            PlotSheet = Plot_sheet_list[HPGL_SheetSize];
        else
            PlotSheet = screen->m_CurrentSheetDesc;
        /* 10x because eeschema works in mils, not decimals */
        double plot_scale = 10 * (double) PlotSheet->m_Size.x /
                            (double) SheetSize.x;

        /* Calculate offsets */
        PlotOffset.x = -SheetOffset.x;
        PlotOffset.y = -SheetOffset.y;

        PlotFileName = schframe->GetUniqueFilenameForCurrentSheet() +
            wxT( ".plt" );

        SetLocaleTo_C_standard();
        Plot_1_Page_HPGL( PlotFileName, screen, PlotSheet, PlotOffset,
                          plot_scale );
        SetLocaleTo_Default();

        if( !Select_PlotAll )
            break;
    }

    ActiveScreen = oldscreen;
    schframe->m_CurrentSheet = oldsheetpath;
    schframe->m_CurrentSheet->UpdateAllScreenReferences();
    schframe->SetSheetNumberAndCount();
}


void WinEDA_PlotHPGLFrame::Plot_1_Page_HPGL( const wxString& FileName,
                                             SCH_SCREEN*     screen,
                                             Ki_PageDescr*   sheet,
                                             wxPoint&        offset,
                                             double          plot_scale )
{
    wxString msg;

    FILE*    output_file = wxFopen( FileName, wxT( "wt" ) );

    if( output_file == NULL )
    {
        msg  = wxT( "\n** " );
        msg += _( "Unable to create " ) + FileName + wxT( " **\n\n" );
        m_MsgBox->AppendText( msg );
        wxBell();
        return;
    }

    SetLocaleTo_C_standard();
    msg.Printf( _( "Plot: %s\n" ), FileName.GetData() );
    m_MsgBox->AppendText( msg );

    HPGL_PLOTTER* plotter = new HPGL_PLOTTER();
    plotter->set_paper_size( sheet );
    plotter->set_viewport( offset, plot_scale, 0 );
    plotter->set_default_line_width( g_DrawDefaultLineThickness );
    /* Init : */
    plotter->set_creator( wxT( "EESchema-HPGL" ) );
    plotter->set_filename( FileName );
    plotter->set_pen_speed( g_HPGL_Pen_Descr.m_Pen_Speed );
    plotter->set_pen_number( g_HPGL_Pen_Descr.m_Pen_Num );
    plotter->set_pen_diameter( g_HPGL_Pen_Descr.m_Pen_Diam );
    plotter->set_pen_overlap( g_HPGL_Pen_Descr.m_Pen_Diam / 2 );
    plotter->start_plot( output_file );

    plotter->set_color( BLACK );
    m_Parent->PlotWorkSheet( plotter, screen );

    PlotDrawlist( plotter, screen->EEDrawList );

    plotter->end_plot();
    delete plotter;
    SetLocaleTo_Default();

    m_MsgBox->AppendText( wxT( "Ok\n" ) );
}


/*!
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_RADIOBOX
 */

void WinEDA_PlotHPGLFrame::OnRadioboxSelected( wxCommandEvent& event )
{
    HPGL_SizeSelect = m_SizeOption->GetSelection();
    SetPageOffsetValue();
}


/*!
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_PEN_WIDTH_UPDATED
 */

void WinEDA_PlotHPGLFrame::OnPenWidthUpdatedUpdated( wxSpinEvent& event )
{
    SetPenWidth( event );
}


/*!
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_PEN_SPEED_UPDATED
 */

void WinEDA_PlotHPGLFrame::OnPenSpeedUpdatedUpdated( wxSpinEvent& event )
{
    SetPenSpeed( event );
}


/*!
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_PEN_NUMBER_UPDATED
 */

void WinEDA_PlotHPGLFrame::OnPenNumberUpdatedUpdated( wxSpinEvent& event )
{
    SetPenNum( event );
}
