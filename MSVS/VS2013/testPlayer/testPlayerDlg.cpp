
// testPlayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "testPlayer.h"
#include "testPlayerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestPlayerDlg dialog



CtestPlayerDlg::CtestPlayerDlg(CWnd* pParent /*=NULL*/)
    :CDialogEx(CtestPlayerDlg::IDD, pParent),
    m_handle1_speed(0),
    m_handle1_percentage(0),
    m_handle2_percentage(0),
    m_handle2_speed(0),
    m_handle1_filepath(_T("")),
    m_handle2_filepath(_T("")),
    m_handle1_snapshot_path(_T("")),
    m_handle2_snapshot_path(_T(""))
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_HANDLE1_SPEED, m_handle1_speed);
    DDX_Text(pDX, IDC_EDIT_HANDLE1_PERCENTAGE, m_handle1_percentage);
    DDX_Text(pDX, IDC_EDIT_HANDLE2_PERCENTAGE, m_handle2_percentage);
    DDX_Text(pDX, IDC_EDIT_HANDLE2_SPEED, m_handle2_speed);
    DDX_Text(pDX, IDC_EDIT_HANDLE1_FILEPATH, m_handle1_filepath);
    DDX_Text(pDX, IDC_EDIT_HANDLE2_FILEPATH, m_handle2_filepath);
    DDX_Text(pDX, IDC_EDIT_HANDLE1_SNAPSHOT_PATH, m_handle1_snapshot_path);
    DDX_Text(pDX, IDC_EDIT_HANDLE2_SNAPSHOT_PATH, m_handle2_snapshot_path);
}

BEGIN_MESSAGE_MAP(CtestPlayerDlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_HANDLE1_PLAY, &CtestPlayerDlg::OnClickedButtonHandle1Play)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE1_PAUSE, &CtestPlayerDlg::OnClickedButtonHandle1Pause)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE1_STOP, &CtestPlayerDlg::OnClickedButtonHandle1Stop)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE1_SET_SPEED, &CtestPlayerDlg::OnClickedButtonHandle1SetSpeed)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE1_GET_PERCENTAGE, &CtestPlayerDlg::OnClickedButtonHandle1GetPercentage)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE1_SET_PERCENTAGE, &CtestPlayerDlg::OnClickedButtonHandle1SetPercentage)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE1_TAKE_SNAPSHOT, &CtestPlayerDlg::OnClickedButtonHandle1TakeSnapshot)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE2_PLAY, &CtestPlayerDlg::OnClickedButtonHandle2Play)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE2_PAUSE, &CtestPlayerDlg::OnClickedButtonHandle2Pause)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE2_STOP, &CtestPlayerDlg::OnClickedButtonHandle2Stop)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE2_SET_SPEED, &CtestPlayerDlg::OnClickedButtonHandle2SetSpeed)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE2_GET_PERCENTAGE, &CtestPlayerDlg::OnClickedButtonHandle2GetPercentage)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE2_SET_PERCENTAGE, &CtestPlayerDlg::OnClickedButtonHandle2SetPercentage)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE2_TAKE_SNAPSHOT, &CtestPlayerDlg::OnClickedButtonHandle2TakeSnapshot)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE1_APPLY, &CtestPlayerDlg::OnClickedButtonHandle1Apply)
    ON_BN_CLICKED(IDC_BUTTON_HANDLE2_APPLY, &CtestPlayerDlg::OnClickedButtonHandle2Apply)
    ON_WM_RBUTTONDOWN()
    ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CtestPlayerDlg message handlers

BOOL CtestPlayerDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);         // Set big icon
    SetIcon(m_hIcon, FALSE);        // Set small icon

    // TODO: Add extra initialization here
    m_handle1_speed = 1.0;
    m_handle2_speed = 1.0;
    m_handle1_filepath = _T("rtsp://192.168.10.29/gsd15070731am.mkv");
    m_handle2_filepath = _T("E:\\Avengers.Age.of.Ultron.2015.1080p.BluRay.x264.YIFY.mp4");
    m_handle1_snapshot_path = _T("D:\\");
    m_handle2_snapshot_path = _T("D:\\");
    UpdateData(FALSE);
    LSP_initial();

    return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CtestPlayerDlg::OnPaint()
{
    if(IsIconic())
    {
        CPaintDC dc(this); // device context for painting

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // Center icon in client rectangle
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // Draw the icon
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CtestPlayerDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}



BOOL CtestPlayerDlg::DestroyWindow()
{
    // TODO: Add your specialized code here and/or call the base class
    LSP_uninitial();
    return CDialogEx::DestroyWindow();
}


void CtestPlayerDlg::OnClickedButtonHandle1Play()
{
    // TODO: Add your control notification handler code here
    LSP_play(m_play_handle1);
}


void CtestPlayerDlg::OnClickedButtonHandle1Pause()
{
    // TODO: Add your control notification handler code here
    LSP_pause(m_play_handle1);
}


void CtestPlayerDlg::OnClickedButtonHandle1Stop()
{
    // TODO: Add your control notification handler code here
    LSP_stop(m_play_handle1);
}


void CtestPlayerDlg::OnClickedButtonHandle1SetSpeed()
{
    // TODO: Add your control notification handler code here
    UpdateData();
    LSP_set_speed(m_play_handle1, m_handle1_speed);
}


void CtestPlayerDlg::OnClickedButtonHandle1GetPercentage()
{
    // TODO: Add your control notification handler code here
    LSP_get_playing_percentage(m_play_handle1, &m_handle1_percentage);
    UpdateData(FALSE);
}


void CtestPlayerDlg::OnClickedButtonHandle1SetPercentage()
{
    // TODO: Add your control notification handler code here
    UpdateData();
    LSP_set_playing_percentage(m_play_handle1, m_handle1_percentage);
}


void CtestPlayerDlg::OnClickedButtonHandle1TakeSnapshot()
{
    // TODO: Add your control notification handler code here
    UpdateData();
    LSP_get_snapshot(m_play_handle1, CCStringToChar(m_handle1_snapshot_path).GetCStyleString());
}


void CtestPlayerDlg::OnClickedButtonHandle2Play()
{
    // TODO: Add your control notification handler code here
    LSP_play(m_play_handle2);
}


void CtestPlayerDlg::OnClickedButtonHandle2Pause()
{
    // TODO: Add your control notification handler code here
    LSP_pause(m_play_handle2);
}


void CtestPlayerDlg::OnClickedButtonHandle2Stop()
{
    // TODO: Add your control notification handler code here
    LSP_stop(m_play_handle2);
}


void CtestPlayerDlg::OnClickedButtonHandle2SetSpeed()
{
    // TODO: Add your control notification handler code here
    UpdateData();
    LSP_set_speed(m_play_handle2, m_handle2_speed);
}


void CtestPlayerDlg::OnClickedButtonHandle2GetPercentage()
{
    // TODO: Add your control notification handler code here
    LSP_get_playing_percentage(m_play_handle2, &m_handle2_percentage);
    UpdateData(FALSE);
}


void CtestPlayerDlg::OnClickedButtonHandle2SetPercentage()
{
    // TODO: Add your control notification handler code here
    UpdateData();
    LSP_set_playing_percentage(m_play_handle2, m_handle2_percentage);
}


void CtestPlayerDlg::OnClickedButtonHandle2TakeSnapshot()
{
    // TODO: Add your control notification handler code here
    UpdateData();
    LSP_get_snapshot(m_play_handle2, CCStringToChar(m_handle2_snapshot_path).GetCStyleString());
}

void play_handle1_play_end_event(void* user_data)
{
    MessageBox(NULL, _T("Play handle1 play end"), _T("Notify"), MB_OK);
}


void CtestPlayerDlg::OnClickedButtonHandle1Apply()
{
    // TODO: Add your control notification handler code here
    UpdateData();
    LSP_get_idle_handle(&m_play_handle1);
    LSP_set_MUL(m_play_handle1, CCStringToChar(m_handle1_filepath).GetCStyleString());
    LSP_set_hwnd(m_play_handle1, GetDlgItem(IDC_HANDLE1_PICTURE_AREA)->m_hWnd);
    LSP_set_play_end_event_callback(m_play_handle1, play_handle1_play_end_event, NULL);
}

void play_handle2_play_end_event(void* user_data)
{
    MessageBox(NULL, _T("Play handle2 play end"), _T("Notify"), MB_OK);
}

void CtestPlayerDlg::OnClickedButtonHandle2Apply()
{
    // TODO: Add your control notification handler code here
    UpdateData();
    LSP_get_idle_handle(&m_play_handle2);
    LSP_set_filepath(m_play_handle2, CCStringToChar(m_handle2_filepath).GetCStyleString());
    LSP_set_hwnd(m_play_handle2, GetDlgItem(IDC_HANDLE2_PICTURE_AREA)->m_hWnd);
    LSP_set_play_end_event_callback(m_play_handle2, play_handle2_play_end_event, NULL);
}


void CtestPlayerDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default

    AfxMessageBox(_T("Right button clicked"));

    CDialogEx::OnRButtonDown(nFlags, point);
}


void CtestPlayerDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default

    AfxMessageBox(_T("Left button clicked"));

    CDialogEx::OnLButtonDown(nFlags, point);
}
