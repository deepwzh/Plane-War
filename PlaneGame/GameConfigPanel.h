#pragma once
#include "resource.h"

// CGameConfigPanel 对话框

class CGameConfigPanel : public CDialogEx
{
	DECLARE_DYNAMIC(CGameConfigPanel)

public:
	CGameConfigPanel(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGameConfigPanel();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
