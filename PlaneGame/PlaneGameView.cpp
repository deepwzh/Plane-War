
// PlaneGameView.cpp : CPlaneGameView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "PlaneGame.h"
#endif

#include "PlaneGameDoc.h"
#include "PlaneGameView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlaneGameView

IMPLEMENT_DYNCREATE(CPlaneGameView, CView)

BEGIN_MESSAGE_MAP(CPlaneGameView, CView)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_MOVE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CPlaneGameView 构造/析构

CPlaneGameView::CPlaneGameView(): game_manager(NULL), m_pDC(NULL), m_pMemDC(NULL)
{
	// TODO: 在此处添加构造代码

}

CPlaneGameView::~CPlaneGameView()
{
}

BOOL CPlaneGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPlaneGameView 绘制

void CPlaneGameView::OnDraw(CDC* pDC)
{
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CPlaneGameView 诊断

#ifdef _DEBUG
void CPlaneGameView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneGameDoc* CPlaneGameView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneGameDoc)));
	return (CPlaneGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneGameView 消息处理程序


void CPlaneGameView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	InitGame();
	// TODO: 在此添加专用代码和/或调用基类
}


void CPlaneGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CPlaneGameView::InitGame()
{
	CView::OnInitialUpdate();
	CSockConnect();
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return FALSE;
	CRect rect;
	this->GetClientRect(&rect);
	game_manager = new CGameManager(rect.right - rect.left, rect.bottom - rect.top);
	//TRACE("%d %d\n", rect.right - rect.left, rect.bottom - rect.top);
	//建立设备DC
	m_pDC = new CClientDC(this);

	//建立内存DC
	m_pMemDC = new CDC;
	m_pMemDC->CreateCompatibleDC(m_pDC);

	//建立内存位图
	m_pMemBitmap = new CBitmap;
	m_pMemBitmap->CreateCompatibleBitmap(m_pDC, game_manager->getWidth(), game_manager->getHeight());

	//将位图选入内存DC
	m_pMemDC->SelectObject(m_pMemBitmap);

	//产生主角(战机)
	game_manager->StartGame(true);
	SetTimer(1, 20, NULL);
	
	return TRUE;
}

void CPlaneGameView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (game_manager->getState() ==  CGameManager::End) {
		KillTimer(1);
		return;
	}
	game_manager->HandleKeyMap();
	game_manager->draw(m_pMemDC);
	game_manager->AI();
	m_pDC->BitBlt(0, 0, game_manager->getWidth(), game_manager->getHeight(), m_pMemDC, 0, 0, SRCCOPY);
	CView::OnTimer(nIDEvent);
}

void CPlaneGameView::OnDestroy()
{
	CView::OnDestroy();
	//delete m_pMe;
	delete m_pMemDC;
	delete m_pDC;
	delete m_pMemBitmap;
	this->KillTimer(1);
	// TODO: 在此处添加消息处理程序代码
}

void CPlaneGameView::OnMove(int x, int y)
{
	CView::OnMove(x, y);
	//TRACE("Moved");
	// TODO: 在此处添加消息处理程序代码
}

//BUG:屏幕区域改变会出现问题
void CPlaneGameView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (game_manager != NULL) {
		CRect rect;
		this->GetClientRect(&rect);
		game_manager->setRect(rect.right - rect.left, rect.bottom - rect.top);
	}

	// TODO: 在此处添加消息处理程序代码
}
void CPlaneGameView::OnMove(UINT fwSide, LPRECT pRect)
{
	CView::OnMoving(fwSide, pRect);
	//TRACE("Moving\n");

	// TODO: 在此处添加消息处理程序代码
}
