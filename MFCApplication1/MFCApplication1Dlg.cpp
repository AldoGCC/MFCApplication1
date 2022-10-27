
// MFCApplication1Dlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"


#include "USB.h"
#include "usb2550.h"

#include "windows.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CMFCApplication1Dlg



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, M_PGR(_T(""))
	, M_SHOW(FALSE)
	, M_ENABLE(FALSE)
	, m_enable(FALSE)
	, m_hab(FALSE)
	, M_INHABILITAR(FALSE)
	, m_TITULO(_T(""))
	, M_MSG(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_PGR_COMBO2, M_PGR);
	DDX_Check(pDX, IDC_SHOW_CHECK, M_SHOW);
	//DDX_Check(pDX, IDC_Habilitar_C, m_hab);
	DDX_Check(pDX, IDC_INHABILITAR_CHECK, M_INHABILITAR);
	DDX_Control(pDX, IDC_MSG_BUTTON, m_msg);
	DDX_Text(pDX, IDC_TITULO_EDIT, m_TITULO);
	DDX_Text(pDX, IDC_MSG_EDIT, M_MSG);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT_BUTTON1, &CMFCApplication1Dlg::OnBnClickedExitButton1)
	ON_COMMAND(ID_Menu, &CMFCApplication1Dlg::OnMenu)
	ON_COMMAND(ID_PROGRAMASPREDEFINIDO_NOTAS, &CMFCApplication1Dlg::OnProgramaspredefinidoNotas)
	ON_COMMAND(ID_PROGRAMASPREDEFINIDO_PAINT, &CMFCApplication1Dlg::OnProgramaspredefinidoPaint)
	ON_COMMAND(ID_PROGRAMASPREDEFINIDO_COMANDO, &CMFCApplication1Dlg::OnProgramaspredefinidoComando)
	ON_COMMAND(ID_PROGRAMASPREDEFINIDO_CALCULADORA, &CMFCApplication1Dlg::OnProgramaspredefinidoCalculadora)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	
	ON_BN_CLICKED(IDC_PGR_BUTTON, &CMFCApplication1Dlg::OnBnClickedPgrButton)
	ON_BN_CLICKED(IDC_SHOW_CHECK, &CMFCApplication1Dlg::OnBnClickedShowCheck)
	//ON_BN_CLICKED(IDC_Habilitar, &CMFCApplication1Dlg::OnBnClickedHabilitarCheck)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	//ON_BN_CLICKED(IDC_Habilitar_C, &CMFCApplication1Dlg::OnBnClickedHabilitarC)
	ON_BN_CLICKED(IDC_INHABILITAR_CHECK, &CMFCApplication1Dlg::OnBnClickedInhabilitarCheck)
	ON_COMMAND(ID_PROGRAMA_SOLIDWORKS, &CMFCApplication1Dlg::OnProgramafluidsim)
	ON_COMMAND(ID_PROGRAMA_PSEINT, &CMFCApplication1Dlg::OnProgramaPseint)
	ON_COMMAND(ID_PROGRAMA_PROTEUS, &CMFCApplication1Dlg::OnProgramavisualcode)
	ON_BN_CLICKED(IDC_MSG_BUTTON, &CMFCApplication1Dlg::OnBnClickedMsgButton)
	ON_EN_CHANGE(IDC_TITULO_EDIT, &CMFCApplication1Dlg::OnEnChangeTituloEdit)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Controladores de mensajes de CMFCApplication1Dlg

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional
		M_SHOW = TRUE; 
	    m_hab = TRUE;
		M_INHABILITAR = TRUE;
	UpdateData(FALSE);

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedExitButton1()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	OnOK();

}


void CMFCApplication1Dlg::OnMenu()
{
	// TODO: Agregue aquí su código de controlador de comandos
	OnOK();

}


void CMFCApplication1Dlg::OnProgramaspredefinidoNotas()
{
	// TODO: Agregue aquí su código de controlador de comandos
	WinExec("notepad.exe", SW_NORMAL);

}

void CMFCApplication1Dlg::OnProgramaspredefinidoPaint()
{
	// TODO: Agregue aquí su código de controlador de comandos
	WinExec("mspaint.exe", SW_NORMAL);

}


void CMFCApplication1Dlg::OnProgramaspredefinidoComando()
{
	// TODO: Agregue aquí su código de controlador de comandos
	WinExec("cmd.exe", SW_NORMAL);

}


void CMFCApplication1Dlg::OnProgramaspredefinidoCalculadora()
{
	// TODO: Agregue aquí su código de controlador de comandos
	WinExec("calc.exe", SW_NORMAL);

}

/* ----Prototypes of Inp and Outp--- */

short _stdcall Inp32(short PortAddress); 
void _stdcall Out32(short PortAddress, short data);

/*--------------------------------*/
void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	BYTE dato[1];
	dato[0] = 1;
	//Obje.SendPacket(dato, 1);
	PACO.SendPacket(dato, 1);

	for (int i = 0; i <= 50; i++) { 
		//00000001(0x378, 0x01); //00000001
		Sleep(50);
		Out32(0x378, 0x02);//00000010
		Sleep(50);
		Out32(0x378, 0x04);//00000100
		Sleep(50);
		Out32(0x378, 0x08);//00001000
		Sleep(50);
	}
	MessageBeep(254);

}




void CMFCApplication1Dlg::OnBnClickedPgrButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	//paint;comando;calculadora;notas;PSeint;Proteus;fluidsim;visual code;
	UpdateData(TRUE);
	if (M_PGR == "calculadora") {
		WinExec ("calc.exe", SW_NORMAL);
	}
	else if (M_PGR == "comando") {
		WinExec ("cmd.exe", SW_NORMAL);
	}
	else if (M_PGR == "paint") {
		WinExec ("mspaint.exe", SW_NORMAL);
	}
	else if (M_PGR == "notas") {
		WinExec ("notepad.exe", SW_NORMAL);
		//WinExec("\"C:\\Program Files (x86)\\PSeInt\\wxPSeInt.exe\" -L -S", SW_SHOW);
	}
	else if (M_PGR == "PSeint") {
		WinExec("\"C:\\Program Files (x86)\\PSeInt\\wxPSeInt.exe\" -L -S", SW_NORMAL);
	}
	else if (M_PGR == "fluidsim") {
		WinExec("\"C:\\Program Files (x86)\\Didactic\\fl_sim_p4.es\\bin\\fl_sim_p.exe\" -L -S", SW_NORMAL);
			//C:\Program Files (x86)\Didactic\fl_sim_p4.es\bin\fl_sim_p.exe
	}
	else if (M_PGR == "visual code") {
		WinExec("\"C:\\Users\\a\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe\" -L -S", SW_NORMAL);
			//"C:\Users\a\AppData\Local\Programs\Microsoft VS Code\Code.exe"
	}
	
	
}



void CMFCApplication1Dlg::OnBnClickedShowCheck()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (M_SHOW == TRUE) {
		GetDlgItem(IDC_PGR_BUTTON)-> ShowWindow(TRUE);
		GetDlgItem(IDC_PGR_COMBO2) -> ShowWindow(TRUE);
		GetDlgItem(IDC_MSG_BUTTON)->ShowWindow(TRUE);
		GetDlgItem(IDC_MSG_EDIT)->ShowWindow(TRUE);
		GetDlgItem(IDC_TITULO_EDIT)->ShowWindow(TRUE);
	}
	else {
		GetDlgItem(IDC_PGR_BUTTON) ->ShowWindow(FALSE);
		GetDlgItem(IDC_PGR_COMBO2) ->ShowWindow(FALSE);
		GetDlgItem(IDC_MSG_BUTTON)->ShowWindow(FALSE);
		GetDlgItem(IDC_MSG_EDIT)->ShowWindow(0);
		GetDlgItem(IDC_TITULO_EDIT)->ShowWindow(0);
	}
}








//void CMFCApplication1Dlg::OnBnClickedHabilitarCheck()
//{
	// TODO: Agregue aquí su código de controlador de notificación de control
	//UpdateData(TRUE);
	//if (m_hab == TRUE) {
		//GetDlgItem(IDC_PGR_BUTTON)->EnableWindow(TRUE);
		//GetDlgItem(IDC_PGR_COMBO2)->EnableWindow(TRUE);

	//}
	//else {
		//GetDlgItem(IDC_PGR_BUTTON)->EnableWindow(FALSE);
		//GetDlgItem(IDC_PGR_COMBO2)->EnableWindow(0);

	//}
//}



void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	BYTE dato[1];
	dato[0] = 0;
	//Obje.SendPacket(dato, 1);
	PACO.SendPacket(dato, 1);
	for (int i = 0; i <= 150; i++) {
		//00000001(0x378, 0x01); //00000001
		Sleep(50);
		Out32(0x378, 0x08);//00000010
		Sleep(50);
		Out32(0x378, 0x04);//00000100
		Sleep(50);
		Out32(0x378, 0x02);//00001000
		Sleep(50);
	}
}




void CMFCApplication1Dlg::OnBnClickedInhabilitarCheck()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (M_INHABILITAR == TRUE) {
		GetDlgItem(IDC_PGR_BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_PGR_COMBO2)->EnableWindow(TRUE);


	}
	else {
		GetDlgItem(IDC_PGR_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_PGR_COMBO2)->EnableWindow(FALSE);
	}
	

}


void CMFCApplication1Dlg::OnProgramafluidsim()
{
	// TODO: Agregue aquí su código de controlador de comandos
	WinExec("\"C:\\Program Files (x86)\\Didactic\\fl_sim_p4.es\\bin\\fl_sim_p.exe\" -L -S", SW_NORMAL);
}


void CMFCApplication1Dlg::OnProgramaPseint()
{
	// TODO: Agregue aquí su código de controlador de comandos
	WinExec("\"C:\\Program Files (x86)\\PSeInt\\wxPSeInt.exe\" -L -S", SW_NORMAL);
}


void CMFCApplication1Dlg::OnProgramavisualcode()
{
	// TODO: Agregue aquí su código de controlador de comandos
	WinExec("\"C:\\Users\\a\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe\" -L -S", SW_NORMAL);
}


void CMFCApplication1Dlg::OnBnClickedMsgButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	MessageBox(__T("PASEME POFAVO")_T(" :c"));
}


void CMFCApplication1Dlg::OnEnChangeTituloEdit()
{
	// TODO:  Si éste es un control RICHEDIT, el control no
	// enviará esta notificación a menos que se invalide CDialogEx::OnInitDialog()
	// función y llamada CRichEditCtrl().SetEventMask()
	// con la marca ENM_CHANGE ORed en la máscara.

	// TODO:  Agregue aquí el controlador de notificación de controles

}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	MessageBeep(255);
	MessageBox(m_TITULO, M_MSG);

}
