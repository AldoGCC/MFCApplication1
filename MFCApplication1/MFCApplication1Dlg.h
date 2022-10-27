
// MFCApplication1Dlg.h: archivo de encabezado
//

#pragma once
#include "USB.h"
#include "usb2550.h"

// Cuadro de diálogo de CMFCApplication1Dlg
class CMFCApplication1Dlg : public CDialogEx
{
// Construcción
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// Constructor estándar
	///aqui
	USB PACO;

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExitButton1();
	afx_msg void OnMenu();
	afx_msg void OnProgramaspredefinidoNotas();
	afx_msg void OnProgramaspredefinidoPaint();
	afx_msg void OnProgramaspredefinidoComando();
	afx_msg void OnProgramaspredefinidoCalculadora();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnCbnSelchangeCombo1();
	CString M_PGR;
	afx_msg void OnBnClickedPgrButton();
	afx_msg void OnBnClickedCheck1();
	BOOL M_SHOW;
	afx_msg void OnBnClickedShowCheck();
	afx_msg void OnBnClickedEnableCheck();
	BOOL M_ENABLE;
	afx_msg void OnBnClickedEnableCheck3();
	BOOL m_enable;
	afx_msg void OnBnClickedenableCheck3();
	afx_msg void OnBnClickedHabilitarCheck();
	BOOL m_hab;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedHabilitarC();
	BOOL M_INHABILITAR;
	afx_msg void OnBnClickedInhabilitarCheck();
	afx_msg void OnProgramafluidsim();
	afx_msg void OnProgramaPseint();
	afx_msg void OnProgramavisualcode();
	CButton m_msg;
	afx_msg void OnBnClickedMsgButton();
	CString m_TITULO;
	CString M_MSG;
	afx_msg void OnEnChangeTituloEdit();
	afx_msg void OnBnClickedButton1();
};
