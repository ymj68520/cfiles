// MFCApplication2Dlg.cpp : ʵ���ļ�

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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx

{

public:

CAboutDlg();

// �Ի�������

enum { IDD = IDD_ABOUTBOX };

protected:

virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV ֧��

// ʵ��

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

// CMFCApplication2Dlg �Ի���

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

// CMFCApplication2Dlg ��Ϣ�������

BOOL CMFCApplication2Dlg::OnInitDialog()

{

CDialogEx::OnInitDialog();

// ��������...���˵�����ӵ�ϵͳ�˵��С�

// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�

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

// ���ô˶Ի����ͼ�ꡣ ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�

// ִ�д˲���

SetIcon(m_hIcon, TRUE);// ���ô�ͼ��

SetIcon(m_hIcon, FALSE);// ����Сͼ��

// TODO: �ڴ���Ӷ���ĳ�ʼ������

return TRUE; // ���ǽ��������õ��ؼ������򷵻� TRUE

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

// �����Ի��������С����ť������Ҫ����Ĵ���

// �����Ƹ�ͼ�ꡣ ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���

// �⽫�ɿ���Զ���ɡ�

void CMFCApplication2Dlg::OnPaint()

{

if (IsIconic())

{

CPaintDC dc(this); // ���ڻ��Ƶ��豸������

SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

// ʹͼ���ڹ����������о���

int cxIcon = GetSystemMetrics(SM_CXICON);

int cyIcon = GetSystemMetrics(SM_CYICON);

CRect rect;

GetClientRect(&rect);

int x = (rect.Width() - cxIcon + 1) / 2;

int y = (rect.Height() - cyIcon + 1) / 2;

// ����ͼ��

dc.DrawIcon(x, y, m_hIcon);

}

else

{

CDialogEx::OnPaint();

}

}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��

//��ʾ��

HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()

{

return static_cast<HCURSOR>(m_hIcon);

}

BOOL g_bStop = FALSE;

BOOL PaintFlower(int x, int y)

{

// ��ȡ����Ļ�ͼ�豸�����������豸

HWND hDesk = ::GetDesktopWindow();

HDC hDC = ::GetDC(hDesk);

HDC hMD = ::CreateCompatibleDC(hDC);

HDC hBuf = ::CreateCompatibleDC(hDC);

// ��ȡ�����͸�

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

// ����λͼ��Դ

HBITMAP tempbmp, oldtempbmp, bmp, oldbmp;

tempbmp = ::CreateCompatibleBitmap(hDC, dwWidth, dwHeight);

bmp = (HBITMAP)::LoadImage(::GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_FLOWERS), IMAGE_BITMAP, 0, 0, NULL);

// ѡ����Դ

oldtempbmp = (HBITMAP)::SelectObject(hMD, tempbmp);

oldbmp = (HBITMAP)::SelectObject(hBuf, bmp);

// ����һ������

::BitBlt(hMD, 0, 0, dwWidth, dwHeight, hDC, 0, 0, SRCCOPY);

// ʹ��˫����ģ�����͸��λͼ

// �� and �� or

::BitBlt(hMD, x, y, 100, 100, hBuf, 0, 0, SRCAND);

::BitBlt(hMD, x, y, 100, 100, hBuf, 0, 100, SRCPAINT);

// ���Ƶ�����

::BitBlt(hDC, 0, 0, dwWidth, dwHeight, hMD, 0, 0, SRCCOPY);

::SelectObject(hBuf, oldbmp);

::SelectObject(hMD, oldtempbmp);

// �ͷ��ڴ�

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

// ��ȡ������Ļ�Ŀ�͸�

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

DWORD m = dwWidth / 30, n = dwHeight / 30;

DWORD x = 0, y = 0;

DWORD i = 0;

// ��������ĵ� 599 ��

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

// ��ȡ������Ļ�Ŀ�͸�

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

DWORD m = dwWidth / 30, n = dwHeight / 30;

DWORD x = 0, y = 0;

DWORD i = 0;

// ��� 400 ��

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

//��x�᷽��Ļ�

int CMFCApplication2Dlg::ShowMyFlower2(LPVOID lpVoid)

{

CMFCApplication2Dlg *pThis = (CMFCApplication2Dlg *)lpVoid;

/*Sleep(500);*/

// ��ȡ������Ļ�Ŀ�͸�

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

DWORD i = 0;

// ˳ʱ����ʾ

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

// ��ȡ������Ļ�Ŀ�͸�

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

// ��ȡ�����͸�

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

// ������Ƶ�λ��

int x = (dwWidth - 400) / 2;

int y = 110;

// ����λͼ��Դ

HBITMAP tempbmp, oldtempbmp, bmp, oldbmp;

tempbmp = ::CreateCompatibleBitmap(hDC, dwWidth, dwHeight);

//GetModuleHandle�ǻ�ȡһ��Ӧ�ó����̬���ӿ��ģ����

bmp = (HBITMAP)::LoadImage(::GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_520), IMAGE_BITMAP, 0, 0, NULL);

// ѡ����Դ

oldtempbmp = (HBITMAP)::SelectObject(hMD, tempbmp);

oldbmp = (HBITMAP)::SelectObject(hBuf, bmp);

DWORD i = 0, j = 0;

while (TRUE)

{

for (i = 0; i < 4; i++)

{

// ����һ������

::BitBlt(hMD, 0, 0, dwWidth, dwHeight, hDC, 0, 0, SRCCOPY);

// ʹ��˫����ģ�����͸��λͼ

// �� and �� or

::BitBlt(hMD, x, y, 400, 150, hBuf, 0, 0, SRCAND);

::BitBlt(hMD, x, y, 400, 150, hBuf, 0, 150 * (1 + i), SRCPAINT);

// ���Ƶ�����

::BitBlt(hDC, 0, 0, dwWidth, dwHeight, hMD, 0, 0, SRCCOPY);

Sleep(300);

}

for (j = 2; j > 0; j--)

{

// ����һ������

::BitBlt(hMD, 0, 0, dwWidth, dwHeight, hDC, 0, 0, SRCCOPY);

// ʹ��˫����ģ�����͸��λͼ

// �� and �� or

::BitBlt(hMD, x, y, 400, 150, hBuf, 0, 0, SRCAND);

::BitBlt(hMD, x, y, 400, 150, hBuf, 0, 150 * (1 + j), SRCPAINT);

// ���Ƶ�����

::BitBlt(hDC, 0, 0, dwWidth, dwHeight, hMD, 0, 0, SRCCOPY);

Sleep(300);

}

}

::SelectObject(hBuf, oldbmp);

::SelectObject(hMD, oldtempbmp);

// �ͷ��ڴ�

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

// ��ȡ�����͸�

DWORD dwWidth = ::GetSystemMetrics(SM_CXSCREEN);

DWORD dwHeight = ::GetSystemMetrics(SM_CYSCREEN);

// ������Ƶ�λ��

int x = (dwWidth - 700) / 2;

int y = 260;

// ����λͼ��Դ

HBITMAP tempbmp, oldtempbmp, bmp, oldbmp, bmp2, oldbmp2;

tempbmp = ::CreateCompatibleBitmap(hDC, dwWidth, dwHeight);

bmp = (HBITMAP)::LoadImage(::GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOVE), IMAGE_BITMAP, 0, 0, NULL);

bmp2 = (HBITMAP)::LoadImage(::GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOVE2), IMAGE_BITMAP, 0, 0, NULL);

// ѡ����Դ

oldtempbmp = (HBITMAP)::SelectObject(hMD, tempbmp);

oldbmp = (HBITMAP)::SelectObject(hBuf, bmp);

oldbmp2 = (HBITMAP)::SelectObject(hBuf2, bmp2);

while (TRUE)

{

// ����һ������

::BitBlt(hMD, 0, 0, dwWidth, dwHeight, hDC, 0, 0, SRCCOPY);

// ʹ��˫����ģ�����λͼ

::BitBlt(hMD, x, y, 700, 450, hBuf, 0, 0, SRCAND);

::BitBlt(hMD, x, y, 700, 450, hBuf2, 0, 0, SRCPAINT);

// ���Ƶ�����

::BitBlt(hDC, 0, 0, dwWidth, dwHeight, hMD, 0, 0, SRCCOPY);

Sleep(300);

}

::SelectObject(hBuf, oldbmp);

::SelectObject(hBuf, oldbmp2);

::SelectObject(hMD, oldtempbmp);

// �ͷ��ڴ�

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

// ��ȡ������Ļ�Ŀ�͸�

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

// TODO: �ڴ���ӿؼ�֪ͨ����������

// ��������

mciSendString(L"open res\\һ������.mp3 alias music", 0, 0, 0);

mciSendString(L"play music repeat", 0, 0, 0);

// ������С����������

::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);

// ͣ��

//Sleep(1000);

�������߳�

��һ���� --> 999�仨Ѹ�ٰ���

HANDLE hThread0 = ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower0, this, 0, NULL);

HANDLE hThread1 = ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower1, this, 0, NULL);

::WaitForSingleObject(hThread0, 10000);

g_bStop = TRUE;

Sleep(500); //�л�ͼ��

::CloseHandle(hThread0);

::CloseHandle(hThread1);

// ˢ������

HWND hDesktop = ::FindWindow(L"", L"");

hDesktop = ::FindWindowEx(hDesktop, 0, L"", L"");

hDesktop = ::FindWindowEx(hDesktop, 0, L"", L"");

::InvalidateRect(hDesktop, NULL, TRUE);

::SendMessage(hDesktop, WM_PAINT, 0, 0);

::SetCapture(hDesktop);

Sleep(1000);

/*�ڶ����� --> ��ʾ����*/

::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower2, this, 0, NULL);

::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower3, this, 0, NULL);

/* �������� --> ��ʾ520�ͺؿ�*/

::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower4, this, 0, NULL);

::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower5, this, 0, NULL);

�������� --> ������ֵ�õ��

::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowMyFlower6, this, 0, NULL);

}
