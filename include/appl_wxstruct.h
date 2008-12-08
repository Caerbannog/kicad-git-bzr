/************************************************************/
/*						appl_wxstruct.h:					*/
/* descriptions des principales classes derivees utilisees: */
/*    Class "EDA_Appl: classe de l'application generale		*/
/************************************************************/

/* Ce fichier doit etre inclus dans "wxstruct.h"
 */

#ifndef  APPL_WXSTRUCT_H
#define  APPL_WXSTRUCT_H

#ifndef eda_global
#define eda_global extern
#endif


/**********************************************/
/*  Class representing the entire Application */
/**********************************************/

class WinEDA_App : public wxApp
{
public:
    wxString                 m_Project;
    wxSingleInstanceChecker* m_Checker;

    wxPoint                  m_HelpPos;
    wxSize                   m_HelpSize;
    wxHtmlHelpController*    m_HtmlCtrl;
    wxConfig*                m_EDA_Config;        // Config courante (tailles et positions fenetres ...*/
    wxConfig*                m_EDA_CommonConfig;  // common setup (language ...) */
    wxString                 m_HelpFileName;
    wxString                 m_CurrentOptionFile; // dernier fichier .cnf utilis�
    wxString                 m_CurrentOptionFileDateAndTime;

    wxString                 m_BinDir; /* Chemin ou reside l'executable
                                        *  (utilis� si KICAD non d�fini)*/
    wxArrayString            m_LastProject;   /* liste des derniers projets charg�s */
    unsigned int             m_LastProjectMaxCount; /* Max histhory file length */
    wxString                 m_KicadEnv;  /* Chemin de kicad d�fini dans la
                                           * variable d'environnement KICAD,
                                           * typiquement /usr/local/kicad ou
                                           * c:\kicad */
    bool                     m_Env_Defined; // TRUE si variable d'environnement KICAD definie

    wxLocale*                m_Locale;      // Gestion de la localisation
    int                      m_LanguageId;  // indicateur de choix du langage ( 0 = defaut)
    wxMenu*                  m_Language_Menu;  // List menu for languages
    wxString                 m_PdfBrowser;     // Name of the selected browser, for browsing pdf datasheets
    bool                     m_PdfBrowserIsDefault;  // True if the pdf browser is the default (m_PdfBrowser not used)

public:
    WinEDA_App();
    ~WinEDA_App();
    bool    OnInit();
    int     OnRun();

    bool    SetBinDir();
    void    InitEDA_Appl( const wxString& name );
    bool    SetLanguage( bool first_time = FALSE );
    wxMenu* SetLanguageList( wxMenu* MasterMenu );
    void    SetLanguageIdentifier( int menu_id );
    void    InitOnLineHelp();

    // Sauvegarde de configurations et options:
    void    GetSettings();
    void    SaveSettings();
    void    SetLastProject( const wxString& FullFileName );
    void    WriteProjectConfig( const wxString& local_config_filename,
                                const wxString& GroupName,
                                PARAM_CFG_BASE** List );

    bool    ReadProjectConfig( const wxString& local_config_filename,
                               const wxString& GroupName, PARAM_CFG_BASE** List,
                               bool Load_Only_if_New );

    void    ReadPdfBrowserInfos();
    void    WritePdfBrowserInfos();
};

/*
 * Use wxGetApp() to access WinEDA_App.  It is not necessary to keep copies
 * of the application pointer all over the place or worse yet in a global
 * variable.
 */
DECLARE_APP(WinEDA_App);

#endif  /* APPL_WXSTRUCT_H */
