// GameConfigPanel.cpp : 实现文件
//

#include "stdafx.h"
#include "PlaneGame.h"
#include "GameConfigPanel.h"
#include "afxdialogex.h"


// CGameConfigPanel 对话框

IMPLEMENT_DYNAMIC(CGameConfigPanel, CDialogEx)

CGameConfigPanel::CGameConfigPanel(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CGameConfigPanel::~CGameConfigPanel()
{
}

void CGameConfigPanel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGameConfigPanel, CDialogEx)
END_MESSAGE_MAP()


// CGameConfigPanel 消息处理程序


BOOL CGameConfigPanel::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
