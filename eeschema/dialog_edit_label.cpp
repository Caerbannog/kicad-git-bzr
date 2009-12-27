/////////////////////////////////////////////////////////////////////////////

// Name:        dialog_edit_label.cpp
// Author:      jean-pierre Charras
// Modified by:
// Created:     18/12/2008 15:46:26
// Licence: GPL
/////////////////////////////////////////////////////////////////////////////

#include "fctsys.h"
#include "wx/valgen.h"

#include "common.h"
#include "class_drawpanel.h"
#include "program.h"
#include "general.h"
#include "drawtxt.h"
#include "confirm.h"
#include "dialog_edit_label.h"


/*************************************************************************/
void WinEDA_SchematicFrame::EditSchematicText( SCH_TEXT* TextStruct )
{
/*************************************************************************/
/* Edit the properties of the text (Label, Global label, graphic text).. )
 *  pointed by "TextStruct"
 */
    if( TextStruct == NULL )
        return;

    DialogLabelEditor dialog( this, TextStruct );
    dialog.ShowModal();

}



DialogLabelEditor::DialogLabelEditor( WinEDA_SchematicFrame* parent, SCH_TEXT* CurrentText ) :
    DialogLabelEditor_Base( parent )
{
    m_Parent = parent;
    m_CurrentText = CurrentText;
    InitDialog();

    GetSizer()->SetSizeHints(this);
    Centre();
}


void DialogLabelEditor::InitDialog()
{
    wxString msg;
    bool multine = false;

    if( m_CurrentText->m_MultilineAllowed )
    {
        m_TextLabel = m_textCtrlMultiline;
        m_TextLabelSingleline->Show(false);
        multine = true;
    }
    else
    {
        m_TextLabel = m_TextLabelSingleline;
       m_textCtrlMultiline->Show(false);
    }

    m_TextLabel->SetValue( m_CurrentText->m_Text );
    m_TextLabel->SetFocus();

    switch( m_CurrentText->Type() )
    {
    case TYPE_SCH_GLOBALLABEL:
        SetTitle( _( "Global Label Properties" ) );
        break;

    case TYPE_SCH_HIERLABEL:
        SetTitle( _( "Hierarchal Label Properties" ) );
        m_TextShape->SetLabel( _("Hlabel Shape") );
        break;

    case TYPE_SCH_LABEL:
        SetTitle( _( "Label Properties" ) );
        break;

    default:
        SetTitle( _( "Text Properties" ) );
      	m_TextLabel->Disconnect(wxEVT_COMMAND_TEXT_ENTER , wxCommandEventHandler ( DialogLabelEditor::onEnterKey ), NULL, this);
        break;
    }

    unsigned MINTEXTWIDTH  = 30;    // M's are big characters, a few establish a lot of width

    if( m_CurrentText->m_Text.Length() < MINTEXTWIDTH )
    {
        wxString textWidth;
        textWidth.Append( 'M', MINTEXTWIDTH );
        EnsureTextCtrlWidth( m_TextLabel, &textWidth );
    }
    else if ( ! multine )
        EnsureTextCtrlWidth( m_TextLabel );
    else
    {
        // calculate the lenght of the biggest line
        // we cannot use the lenght of the entire text that has no meaning
        int max_len = 0;
        int curr_len = 0;
        int imax = m_CurrentText->m_Text.Len();
        for( int count = 0; count < imax; count++ )
        {
            if( m_CurrentText->m_Text[count] == '\n' ||
                 m_CurrentText->m_Text[count] == '\r' ) // new line
                {
                    curr_len = 0;
                }
            else
            {
                curr_len++;
                if ( max_len < curr_len )
                    max_len = curr_len;
            }
        }
        wxString textWidth;
        textWidth.Append( 'M', max_len );
        EnsureTextCtrlWidth( m_TextLabel, &textWidth );
    }

    // Set validators
    m_TextOrient->SetSelection( m_CurrentText->GetSchematicTextOrientation() );
    m_TextShape->SetSelection( m_CurrentText->m_Shape );

    int style = 0;
    if( m_CurrentText->m_Italic )
        style = 1;
    if( m_CurrentText->m_Bold )
        style += 2;

    m_TextStyle->SetSelection( style );

    msg = m_SizeTitle->GetLabel() + ReturnUnitSymbol();
    m_SizeTitle->SetLabel( msg );

    msg = ReturnStringFromValue( g_UnitMetric, m_CurrentText->m_Size.x, m_Parent->m_InternalUnits );
    m_TextSize->SetValue( msg );

    if( m_CurrentText->Type() != TYPE_SCH_GLOBALLABEL
     && m_CurrentText->Type() != TYPE_SCH_HIERLABEL )
    {
        m_TextShape->Show( false );
    }
}

/*!
 * wxTE_PROCESS_ENTER  event handler for m_TextLabel
 */

void DialogLabelEditor::onEnterKey( wxCommandEvent& event )
{
    TextPropertiesAccept( event );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void DialogLabelEditor::OnButtonOKClick( wxCommandEvent& event )
{
    TextPropertiesAccept( event );
    EndModal( wxID_OK );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void DialogLabelEditor::OnButtonCANCEL_Click( wxCommandEvent& event )
{
    m_Parent->DrawPanel->MouseToCursorSchema();
    EndModal( wxID_CANCEL );
}

/****************************************************************************/
void DialogLabelEditor::TextPropertiesAccept( wxCommandEvent& event )
{
/****************************************************************************/
    wxString text;
    int      value;

    /* save old text in undo list if not already in edit */
    if( m_CurrentText->m_Flags == 0 )
        m_Parent->SaveCopyInUndoList( m_CurrentText, UR_CHANGED );

    m_Parent->DrawPanel->PostDirtyRect( m_CurrentText->GetBoundingBox() );

    text = m_TextLabel->GetValue();
    if( !text.IsEmpty() )
        m_CurrentText->m_Text = text;
    else if( (m_CurrentText->m_Flags & IS_NEW) == 0 )
        DisplayError( this, _( "Empty Text!" ) );

    m_CurrentText->SetSchematicTextOrientation( m_TextOrient->GetSelection() );
    text  = m_TextSize->GetValue();
    value = ReturnValueFromString( g_UnitMetric, text,
                                   m_Parent->m_InternalUnits );
    m_CurrentText->m_Size.x = m_CurrentText->m_Size.y = value;
    if( m_TextShape )
        m_CurrentText->m_Shape = m_TextShape->GetSelection();

    int style = m_TextStyle->GetSelection();
    if( ( style & 1 ) )
        m_CurrentText->m_Italic = 1;
    else
        m_CurrentText->m_Italic = 0;

    if( ( style & 2 ) )
    {
        m_CurrentText->m_Bold  = true;
        m_CurrentText->m_Width = GetPenSizeForBold( m_CurrentText->m_Size.x );
    }
    else
    {
        m_CurrentText->m_Bold  = false;
        m_CurrentText->m_Width = 0;
    }

    m_Parent->GetScreen()->SetModify();

    /* Make the text size as new default size if it is a new text */
    if( (m_CurrentText->m_Flags & IS_NEW) != 0 )
        g_DefaultTextLabelSize = m_CurrentText->m_Size.x;

    m_Parent->DrawPanel->PostDirtyRect( m_CurrentText->GetBoundingBox() );
    m_Parent->DrawPanel->MouseToCursorSchema();
    EndModal( 0 );
}


