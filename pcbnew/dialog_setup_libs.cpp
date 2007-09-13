/////////////////////////////////////////////////////////////////////////////
// Name:        dialog_pcbnew_config.cpp
// Purpose:     
// Author:      jean-pierre Charras
// Modified by: 
// Created:     18/02/2006 16:41:57
// RCS-ID:      
// Copyright:   License GNU
// Licence:     
/////////////////////////////////////////////////////////////////////////////

/* Handle the pcbnew libary config (library list, and default lib path)
*/
// Generated by DialogBlocks (unregistered), 18/02/2006 16:41:57

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "dialog_pcbnew_config.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "fctsys.h"
#include "gr_basic.h"

#include "common.h"
#include "pcbnew.h"

////@begin includes
////@end includes

#include "dialog_setup_libs.h"

////@begin XPM images
////@end XPM images

/*****************************************************************/
void WinEDA_PcbFrame::InstallConfigFrame(const wxPoint & pos)
/*****************************************************************/
{
KiConfigPcbnewFrame * CfgFrame = new KiConfigPcbnewFrame(this);
	CfgFrame->ShowModal(); CfgFrame->Destroy();
}


/*!
 * KiConfigPcbnewFrame type definition
 */

IMPLEMENT_DYNAMIC_CLASS( KiConfigPcbnewFrame, wxDialog )

/*!
 * KiConfigPcbnewFrame event table definition
 */

BEGIN_EVENT_TABLE( KiConfigPcbnewFrame, wxDialog )

////@begin KiConfigPcbnewFrame event table entries
    EVT_CLOSE( KiConfigPcbnewFrame::OnCloseWindow )

    EVT_BUTTON( SAVE_CFG, KiConfigPcbnewFrame::OnSaveCfgClick )

    EVT_BUTTON( DEL_LIB, KiConfigPcbnewFrame::OnDelLibClick )

    EVT_BUTTON( ADD_LIB, KiConfigPcbnewFrame::OnAddLibClick )

    EVT_BUTTON( INSERT_LIB, KiConfigPcbnewFrame::OnInsertLibClick )

////@end KiConfigPcbnewFrame event table entries

END_EVENT_TABLE()

/*!
 * KiConfigPcbnewFrame constructors
 */

KiConfigPcbnewFrame::KiConfigPcbnewFrame( )
{
}

KiConfigPcbnewFrame::KiConfigPcbnewFrame( WinEDA_PcbFrame* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
wxString title;

	m_Parent = parent;
	m_LibModified = FALSE;

    Create(parent, id, caption, pos, size, style);

	title = _("from ") + EDA_Appl->m_CurrentOptionFile;
	SetTitle(title);
	m_ListLibr->InsertItems(g_LibName_List, 0);
	wxString DocModuleFileName =
		EDA_Appl->m_EDA_CommonConfig->Read( wxT("module_doc_file"),
				wxT("pcbnew/footprints.pdf"));
	m_TextHelpModulesFileName->SetValue(DocModuleFileName);
}

/*!
 * KiConfigPcbnewFrame creator
 */

bool KiConfigPcbnewFrame::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin KiConfigPcbnewFrame member initialisation
    m_FileExtList = NULL;
    m_ListLibr = NULL;
    m_TextLibDir = NULL;
    m_TextHelpModulesFileName = NULL;
////@end KiConfigPcbnewFrame member initialisation

////@begin KiConfigPcbnewFrame creation
    SetExtraStyle(GetExtraStyle()|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end KiConfigPcbnewFrame creation
    return true;
}

/*!
 * Control creation for KiConfigPcbnewFrame
 */

void KiConfigPcbnewFrame::CreateControls()
{    
	SetFont(*g_DialogFont);
    
////@begin KiConfigPcbnewFrame content construction
    // Generated by DialogBlocks, 18/02/2006 17:19:54 (unregistered)

    KiConfigPcbnewFrame* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer3->Add(itemBoxSizer4, 0, wxGROW|wxALL, 5);

    wxButton* itemButton5 = new wxButton( itemDialog1, SAVE_CFG, _("Save Cfg"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton5->SetForegroundColour(wxColour(204, 0, 0));
    itemBoxSizer4->Add(itemButton5, 0, wxGROW|wxALL, 5);

    itemBoxSizer4->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer7Static = new wxStaticBox(itemDialog1, wxID_ANY, _("Files ext:"));
    m_FileExtList = new wxStaticBoxSizer(itemStaticBoxSizer7Static, wxVERTICAL);
    itemBoxSizer4->Add(m_FileExtList, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer3->Add(itemBoxSizer8, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer8->Add(itemBoxSizer9, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxBoxSizer* itemBoxSizer10 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer9->Add(itemBoxSizer10, 0, wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer* itemBoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer10->Add(itemBoxSizer11, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton12 = new wxButton( itemDialog1, DEL_LIB, _("Del"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton12->SetForegroundColour(wxColour(204, 0, 0));
    itemBoxSizer11->Add(itemButton12, 0, wxGROW|wxALL, 5);

    wxButton* itemButton13 = new wxButton( itemDialog1, ADD_LIB, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton13->SetForegroundColour(wxColour(0, 128, 0));
    itemBoxSizer11->Add(itemButton13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton14 = new wxButton( itemDialog1, INSERT_LIB, _("Ins"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton14->SetDefault();
    itemButton14->SetForegroundColour(wxColour(0, 0, 255));
    itemBoxSizer11->Add(itemButton14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer15 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer10->Add(itemBoxSizer15, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText16 = new wxStaticText( itemDialog1, wxID_STATIC, _("Libraries"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText16->SetForegroundColour(wxColour(204, 0, 0));
    itemBoxSizer15->Add(itemStaticText16, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxADJUST_MINSIZE, 5);

    wxString* m_ListLibrStrings = NULL;
    m_ListLibr = new wxListBox( itemDialog1, ID_LIST_LIBS, wxDefaultPosition, wxSize(-1, 200), 0, m_ListLibrStrings, wxLB_SINGLE|wxSUNKEN_BORDER );
    itemBoxSizer15->Add(m_ListLibr, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxStaticText* itemStaticText18 = new wxStaticText( itemDialog1, wxID_STATIC, _("Lib Modules Dir:"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
    itemStaticText18->SetForegroundColour(wxColour(204, 0, 0));
    itemBoxSizer2->Add(itemStaticText18, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxADJUST_MINSIZE, 5);

    m_TextLibDir = new wxTextCtrl( itemDialog1, ID_TEXTCTRL, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(m_TextLibDir, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxStaticText* itemStaticText20 = new wxStaticText( itemDialog1, wxID_STATIC, _("Module Doc File:"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
    itemStaticText20->SetForegroundColour(wxColour(204, 0, 0));
    itemBoxSizer2->Add(itemStaticText20, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxADJUST_MINSIZE, 5);

    m_TextHelpModulesFileName = new wxTextCtrl( itemDialog1, ID_TEXTCTRL1, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(m_TextHelpModulesFileName, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    // Set validators
    m_TextLibDir->SetValidator( wxTextValidator(wxFILTER_NONE, & g_UserLibDirBuffer) );
////@end KiConfigPcbnewFrame content construction
wxString msg = _("Board ext: ") + PcbExtBuffer;
    wxStaticText * text = new wxStaticText( itemDialog1, -1, msg, wxDefaultPosition, wxDefaultSize, 0 );
    m_FileExtList->Add(text, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxADJUST_MINSIZE, 5);
	
	msg = _("Cmp ext: ") + NetCmpExtBuffer;
    text = new wxStaticText( itemDialog1, -1, msg, wxDefaultPosition, wxDefaultSize, 0 );
    m_FileExtList->Add(text, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxADJUST_MINSIZE, 5);
	
	msg = _("Lib ext: ") + LibExtBuffer;
    text = new wxStaticText( itemDialog1, -1, msg, wxDefaultPosition, wxDefaultSize, 0 );
    m_FileExtList->Add(text, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxADJUST_MINSIZE, 5);
	
	msg = _("Net ext: ") + NetExtBuffer;
    text = new wxStaticText( itemDialog1, -1, msg, wxDefaultPosition, wxDefaultSize, 0 );
    m_FileExtList->Add(text, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxADJUST_MINSIZE, 5);
}

/*!
 * wxEVT_CLOSE_WINDOW event handler for ID_DIALOG
 */

void KiConfigPcbnewFrame::OnCloseWindow( wxCloseEvent& event )
{
	SetNewOptions();
	EndModal(0);
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for SAVE_CFG
 */

void KiConfigPcbnewFrame::OnSaveCfgClick( wxCommandEvent& event )
{
	SetNewOptions();
	m_Parent->Update_config(this);
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for DEL_LIB
 */

void KiConfigPcbnewFrame::OnDelLibClick( wxCommandEvent& event )
{
    LibDelFct(event);
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ADD_LIB
 */

void KiConfigPcbnewFrame::OnAddLibClick( wxCommandEvent& event )
{
    LibInsertFct(event);
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for INSERT_LIB
 */

void KiConfigPcbnewFrame::OnInsertLibClick( wxCommandEvent& event )
{
    LibInsertFct(event);
}

/*!
 * Should we show tooltips?
 */

bool KiConfigPcbnewFrame::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap KiConfigPcbnewFrame::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin KiConfigPcbnewFrame bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end KiConfigPcbnewFrame bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon KiConfigPcbnewFrame::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin KiConfigPcbnewFrame icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end KiConfigPcbnewFrame icon retrieval
}

/********************************************/
void KiConfigPcbnewFrame::SetNewOptions()
/********************************************/
{
	g_UserLibDirBuffer = m_TextLibDir->GetValue();
	EDA_Appl->m_EDA_CommonConfig->Write( wxT("module_doc_file"),
			m_TextHelpModulesFileName->GetValue());
	SetRealLibraryPath( wxT("modules") );
}


/********************************************************/
void KiConfigPcbnewFrame::LibDelFct(wxCommandEvent& event)
/********************************************************/
{
int ii;

	ii = m_ListLibr->GetSelection();
	if ( ii < 0 ) return;

	g_LibName_List.RemoveAt(ii);

	m_ListLibr->Clear();
	m_ListLibr->InsertItems(g_LibName_List, 0);
	m_LibModified = TRUE;
}


/*************************************************************/
void KiConfigPcbnewFrame::LibInsertFct(wxCommandEvent& event)
/*************************************************************/
/* Insert or add a library to the existing library list:
	New library is put in list before (insert) or after (add)
	the selection
*/
{
int ii;
wxString fullfilename, ShortLibName;
wxString mask = wxT("*");

	ii = m_ListLibr->GetSelection();
	if ( ii < 0 ) ii = 0;
	if( event.GetId() == ADD_LIB)
	{
		if( g_LibName_List.GetCount() != 0 ) ii ++;	/* Add after selection */
	}

	SetNewOptions();
	mask += LibExtBuffer;
	g_RealLibDirBuffer.Replace( wxT("\\"), wxT("/"));

	fullfilename = EDA_FileSelector( _("library files:"),
				g_RealLibDirBuffer,			/* Chemin par defaut */
				wxEmptyString,					/* nom fichier par defaut */
				LibExtBuffer,		/* extension par defaut */
				mask,				/* Masque d'affichage */
				this,
				0,
				TRUE
				);

	if ( fullfilename.IsEmpty() ) return;

	ShortLibName =
		MakeReducedFileName(fullfilename, g_RealLibDirBuffer, LibExtBuffer);

	//Add or insert new library name
	if ( g_LibName_List.Index(ShortLibName) == wxNOT_FOUND)
	{
		m_LibModified = TRUE;
		g_LibName_List.Insert(ShortLibName, ii);
		m_ListLibr->Clear();
		m_ListLibr->InsertItems(g_LibName_List, 0);
	}
	else DisplayError(this, _("Library exists! No Change"));
}

