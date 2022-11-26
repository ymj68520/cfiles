// MFCApplication2Dlg.cpp : 实现文件

//

#include <stdafx.h>

#include <MFCApplication2.h>

#include <MFCApplication2Dlg.h>

#include <afxdialogex.h>

#include <mmsystem.h>

#include <Resource.h>

#pragma comment(lib,"winmm.lib")

#ifdef _DEBUG

#define new DEBUG_NEW

#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx

{

public:

CAboutDlg();

// 对话框数据

enum { IDD = IDD_ABOUTBOX };

protected:

virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV 支持

// 实现

protected:

DECLARE_MESSAGE_MAP()

};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)

{

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)

{

CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()

// CMFCApplication2Dlg 对话框

CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)

: CDialogEx(CMFCApplication2Dlg::IDD, pParent)

{

m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)

{

CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)

ON_WM_SYSCOMMAND()

ON_WM_PAINT()

ON_WM_QUERYDRAGICON()

ON_BN_CLICKED(IDC_BUTTON_TEST, &CMFCApplication2Dlg::OnBnClickedButtonTest)

END_MESSAGE_MAP()

// CMFCApplication2Dlg 消息处理程序

BOOL CMFCApplication2Dlg::OnInitDialog()

{

CDialogEx::OnInitDialog();

// 将“关于...”菜单项添加到系统菜单中。

// IDM_ABOUTBOX 必须在系统命令范围内。

ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);

ASSERT(IDM_ABOUTBOX < 0xF000);

CMenu* pSysMenu = GetSystemMenu(FALSE);

if (pSysMenu != NULL)

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

// 设置此对话框的图标。 当应用程序主窗口不是对话框时，框架将自动

// 执行此操作

SetIcon(m_hIcon, TRUE);// 设置大图标

SetIcon(m_hIcon, FALSE);// 设置小图标

// TODO: 在此添加额外的初始化代码

return TRUE; // 除非将焦点设置到控件，否则返回 TRUE

}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)

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

// 如果向对话框添加最小化按钮，则需要下面的代码

// 来绘制该图标。 对于使用文档/视图模型的 MFC 应用程序，

// 这将由框架自动完成。

void CMFCApplication2Dlg::OnPaint()

{

if (IsIconic())

{

CPaintDC dc(this); // 用于绘制的设备上下文

SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

// 使图标在工作区矩形中居中

int cxIcon = GetSystemMetrics(SM_CXICON);

int cyIcon = GetSystemMetrics(SM_CYICON);

CRect rect;

GetClientRect(&rect);

int x = (rect.Width() - cxIcon + 1) / 2;

int y = (rect.Height() - cyIcon + 1) / 2;

// 绘制图标

dc.DrawIcon(x, y, m_hIcon);

}

else

{

CDialogEx::OnPaint();

}

}

//当用户拖动最小化窗口时系统调用此函数取得光标

//显示。

HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()

{

return static_cast<HCURSOR>(m_hIcon);

}

BOOL g_bStop = FALSE;

BOOL PaintFlower(int x, int y)

{

// 获取桌面的绘图设备并创建兼容设备

HWND hDesk = ::GetDesktopWindow();

HDC hDC = ::GetDC(hDesk);

HDC hMD = ::CreateCompatibleDC(hDC);

HDC hBuf = ::CreateCompatibleDC(hDC);

// 获取桌面宽和高

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

// 加载位图资源

HBITMAP tempbmp, oldtempbmp, bmp, oldbmp;

tempbmp = ::CreateCompatibleBitmap(hDC, dwWidth, dwHeight);

bmp = (HBITMAP)::LoadImage(::GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_FLOWERS), IMAGE_BITMAP, 0, 0, NULL);

// 选中资源

oldtempbmp = (HBITMAP)::SelectObject(hMD, tempbmp);

oldbmp = (HBITMAP)::SelectObject(hBuf, bmp);

// 复制一遍桌面

::BitBlt(hMD, 0, 0, dwWidth, dwHeight, hDC, 0, 0, SRCCOPY);

// 使用双缓冲的，绘制透明位图

// 先 and 再 or

::BitBlt(hMD, x, y, 100, 100, hBuf, 0, 0, SRCAND);

::BitBlt(hMD, x, y, 100, 100, hBuf, 0, 100, SRCPAINT);

// 绘制到桌面

::BitBlt(hDC, 0, 0, dwWidth, dwHeight, hMD, 0, 0, SRCCOPY);

::SelectObject(hBuf, oldbmp);

::SelectObject(hMD, oldtempbmp);

// 释放内存

::DeleteObject(tempbmp);

::DeleteDC(hBuf);

::DeleteDC(hMD);

::ReleaseDC(hDesk, hDC);

return TRUE;

}

int CMFCApplication2Dlg::ShowMyFlower0(LPVOID lpVoid)

{

CMFCApplication2Dlg *pThis = (CMFCApplication2Dlg *)lpVoid;

srand((unsigned int)time(NULL));

// 获取桌面屏幕的宽和高

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

DWORD m = dwWidth / 30, n = dwHeight / 30;

DWORD x = 0, y = 0;

DWORD i = 0;

// 绘制网格的点 599 朵

i = 999;

do

{

if (g_bStop)

{

return 0;

}

x = rand() % m;

y = rand() % n;

PaintFlower(30 * x, 30 * y);

i--;

Sleep(50);

} while (0 <= i);

return 0;

}

int CMFCApplication2Dlg::ShowMyFlower1(LPVOID lpVoid)

{

CMFCApplication2Dlg *pThis = (CMFCApplication2Dlg *)lpVoid;

// 获取桌面屏幕的宽和高

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

DWORD m = dwWidth / 30, n = dwHeight / 30;

DWORD x = 0, y = 0;

DWORD i = 0;

// 随机 400 朵

i = 999;

do

{

if (g_bStop)

{

return 0;

}

x = rand() % m;

y = rand() % n;

PaintFlower(30 * x, 30 * y);

i--;

Sleep(50);

} while (0 <= i);

return 0;

}

//画x轴方向的花

int CMFCApplication2Dlg::ShowMyFlower2(LPVOID lpVoid)

{

CMFCApplication2Dlg *pThis = (CMFCApplication2Dlg *)lpVoid;

/*Sleep(500);*/

// 获取桌面屏幕的宽和高

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

DWORD i = 0;

// 顺时针显示

while (TRUE)

{

for (i = 0; i < dwWidth - 50; i = i + 60)

{

PaintFlower(i, 0);

Sleep(300);

}

for (i = 0; i < dwHeight - 50; i = i + 60)

{

PaintFlower(dwWidth - 100, i);

Sleep(300);

}

}

/*

for(i = dwWidth - 100; i >= 50; i = i - 60)

{

PaintFlower(i, dwHeight - 100);

Sleep(300);

}

for(i = dwHeight - 100; i >= 50 ; i = i - 60)

{

PaintFlower(0, i);

Sleep(300);

}

*/

return 0;

}

int CMFCApplication2Dlg::ShowMyFlower3(LPVOID lpVoid)

{

CMFCApplication2Dlg *pThis = (CMFCApplication2Dlg *)lpVoid;

//Sleep(1000);

// 获取桌面屏幕的宽和高

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

DWORD i = 0;

while (TRUE)

{

for (i = dwWidth - 100; i >= 50; i = i - 60)

{

PaintFlower(i, dwHeight - 100);

Sleep(300);

}

for (i = dwHeight - 100; i >= 50; i = i - 60)

{

PaintFlower(0, i);

Sleep(300);

}

}

return 0;

}

int CMFCApplication2Dlg::ShowMyFlower4(LPVOID lpVoid)

{

CMFCApplication2Dlg *pThis = (CMFCApplication2Dlg *)lpVoid;

//Sleep(12000);

HWND hDesk = ::GetDesktopWindow();

HDC hDC = ::GetDC(hDesk);

HDC hMD = ::CreateCompatibleDC(hDC);

HDC hBuf = ::CreateCompatibleDC(hDC);

// 获取桌面宽和高

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

// 计算绘制的位置

int x = (dwWidth - 400) / 2;

int y = 110;

// 加载位图资源

HBITMAP tempbmp, oldtempbmp, bmp, oldbmp;

tempbmp = ::CreateCompatibleBitmap(hDC, dwWidth, dwHeight);

//GetModuleHandle是获取一个应用程序或动态链接库的模块句柄

bmp = (HBITMAP)::LoadImage(::GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_520), IMAGE_BITMAP, 0, 0, NULL);

// 选中资源

oldtempbmp = (HBITMAP)::SelectObject(hMD, tempbmp);

oldbmp = (HBITMAP)::SelectObject(hBuf, bmp);

DWORD i = 0, j = 0;

while (TRUE)

{

for (i = 0; i < 4; i++)

{

// 复制一遍桌面

::BitBlt(hMD, 0, 0, dwWidth, dwHeight, hDC, 0, 0, SRCCOPY);

// 使用双缓冲的，绘制透明位图

// 先 and 再 or

::BitBlt(hMD, x, y, 400, 150, hBuf, 0, 0, SRCAND);

::BitBlt(hMD, x, y, 400, 150, hBuf, 0, 150 * (1 + i), SRCPAINT);

// 绘制到桌面

::BitBlt(hDC, 0, 0, dwWidth, dwHeight, hMD, 0, 0, SRCCOPY);

Sleep(300);

}

for (j = 2; j > 0; j--)

{

// 复制一遍桌面

::BitBlt(hMD, 0, 0, dwWidth, dwHeight, hDC, 0, 0, SRCCOPY);

// 使用双缓冲的，绘制透明位图

// 先 and 再 or

::BitBlt(hMD, x, y, 400, 150, hBuf, 0, 0, SRCAND);

::BitBlt(hMD, x, y, 400, 150, hBuf, 0, 150 * (1 + j), SRCPAINT);

// 绘制到桌面

::BitBlt(hDC, 0, 0, dwWidth, dwHeight, hMD, 0, 0, SRCCOPY);

Sleep(300);

}

}

::SelectObject(hBuf, oldbmp);

::SelectObject(hMD, oldtempbmp);

// 释放内存

::DeleteObject(tempbmp);

::DeleteDC(hBuf);

::DeleteDC(hMD);

::ReleaseDC(hDesk, hDC);

return 0;

}

int CMFCApplication2Dlg::ShowMyFlower5(LPVOID lpVoid)

{

CMFCApplication2Dlg *pThis = (CMFCApplication2Dlg *)lpVoid;

//Sleep(15000);

HWND hDesk = ::GetDesktopWindow();

HDC hDC = ::GetDC(hDesk);

HDC hMD = ::CreateCompatibleDC(hDC);

HDC hBuf = ::CreateCompatibleDC(hDC);

HDC hBuf2 = ::CreateCompatibleDC(hDC);

// 获取桌面宽和高

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

// 计算绘制的位置

int x = (dwWidth - 700) / 2;

int y = 260;

// 加载位图资源

HBITMAP tempbmp, oldtempbmp, bmp, oldbmp, bmp2, oldbmp2;

tempbmp = ::CreateCompatibleBitmap(hDC, dwWidth, dwHeight);

bmp = (HBITMAP)::LoadImage(::GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOVE), IMAGE_BITMAP, 0, 0, NULL);

bmp2 = (HBITMAP)::LoadImage(::GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOVE2), IMAGE_BITMAP, 0, 0, NULL);

// 选中资源

oldtempbmp = (HBITMAP)::SelectObject(hMD, tempbmp);

oldbmp = (HBITMAP)::SelectObject(hBuf, bmp);

oldbmp2 = (HBITMAP)::SelectObject(hBuf2, bmp2);

while (TRUE)

{

// 复制一遍桌面

::BitBlt(hMD, 0, 0, dwWidth, dwHeight, hDC, 0, 0, SRCCOPY);

// 使用双缓冲的，绘制位图

::BitBlt(hMD, x, y, 700, 450, hBuf, 0, 0, SRCAND);

::BitBlt(hMD, x, y, 700, 450, hBuf2, 0, 0, SRCPAINT);

// 绘制到桌面

::BitBlt(hDC, 0, 0, dwWidth, dwHeight, hMD, 0, 0, SRCCOPY);

Sleep(300);

}

::SelectObject(hBuf, oldbmp);

::SelectObject(hBuf, oldbmp2);

::SelectObject(hMD, oldtempbmp);

// 释放内存

::DeleteObject(tempbmp);

::DeleteDC(hBuf);

::DeleteDC(hMD);

::ReleaseDC(hDesk, hDC);

return 0;

}

int CMFCApplication2Dlg::ShowMyFlower6(LPVOID lpVoid)

{

CMFCApplication2Dlg *pThis = (CMFCApplication2Dlg *)lpVoid;

//Sleep(15000);

srand((unsigned int)time(NULL));

// 获取桌面屏幕的宽和高

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

//DWORD m = dwWidth/100, n = dwHeight/100;

DWORD x = 0, y = 0;

while (TRUE)

{

x = rand() % dwWidth;

y = rand() % dwHeight;

PaintFlower(x, y);

Sleep(300);

}

return 0;

}

void CMFCApplication2Dlg::OnBnClickedButtonTest()

{

// TODO: 在此添加控件通知处理程序代码

// 播放音乐

mciSendString(L"open res\\一生所爱.mp3 alias music", 0, 0, 0);

mciSendString(L"play music repeat", 0, 0, 0);

// 窗口最小化到任务栏

::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);

// 停顿

//Sleep(1000);

创建多线程

第一部分 --> 999朵花迅速霸屏

HANDLE hThread0 = ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower0, this, 0, NULL);

HANDLE hThread1 = ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower1, this, 0, NULL);

::WaitForSingleObject(hThread0, 10000);

g_bStop = TRUE;

Sleep(500); //切换图像

::CloseHandle(hThread0);

::CloseHandle(hThread1);

// 刷新桌面

HWND hDesktop = ::FindWindow(L"", L"");

hDesktop = ::FindWindowEx(hDesktop, 0, L"", L"");

hDesktop = ::FindWindowEx(hDesktop, 0, L"", L"");

::InvalidateRect(hDesktop, NULL, TRUE);

::SendMessage(hDesktop, WM_PAINT, 0, 0);

::SetCapture(hDesktop);

Sleep(1000);

/*第二部分 --> 显示花边*/

::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower2, this, 0, NULL);

::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower3, this, 0, NULL);

/* 第三部分 --> 显示520和贺卡*/

::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower4, this, 0, NULL);

::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower5, this, 0, NULL);

第三部分 --> 随机出现的玫瑰

::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower6, this, 0, NULL);

}
