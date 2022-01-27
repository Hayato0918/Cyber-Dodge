#include "main.h"

class CFullScreen
{
public:
    CFullScreen(
        HWND hwnd       //フルスクリーンにするウィンドウのハンドル
    );
    ~CFullScreen();

    //フルスクリーンモード / ウィンドウモード切り替え
    BOOL change();
    //戻り値
    //フルスクリーンモード => ウィンドウモード     : TRUE
    //ウィンドウモード     => フルスクリーンモード : FALSE

//フルスクリーン状態か調べる
    BOOL IsFullscreen();
    //戻り値
    //フルスクリーンモード    : TRUE
    //ウィンドウモード      : FALSE

private:
    HWND m_hwnd;        //フルスクリーンにするウィンドウのハンドル

    //保存用変数
    RECT m_rc;          //ウィンドウサイズ
    LONG m_style;       //ウィンドウスタイル
    BOOL m_bMax;        //最大化フラグ

    //現在の状態
    BOOL m_bFull;       //フルスクリーンフラグ
};


CFullScreen::CFullScreen(HWND hwnd)
{
    SetRect(&m_rc, 0, 0, 0, 0);
    m_hwnd = hwnd;
    m_bFull = FALSE;
    m_style = 0;
}

CFullScreen::~CFullScreen()
{
}

//フルスクリーンモード / ウィンドウモード切り替え
BOOL CFullScreen::change()
{
    if (!m_bFull) {
        //フルスクリーンにする
        //ウィンドウがあるモニタ
        HMONITOR hMoni = MonitorFromWindow(m_hwnd, MONITOR_DEFAULTTOPRIMARY);

        //スクリーンの大きさ
        MONITORINFOEX lpmi;
        lpmi.cbSize = sizeof(MONITORINFOEX);
        GetMonitorInfo(hMoni, &lpmi);

        //元のウィンドウの状態を保存
        m_style = GetWindowLongPtr(m_hwnd, GWL_STYLE);
        m_bMax = IsZoomed(m_hwnd);
        if (m_bMax) {
            WINDOWPLACEMENT wndPlace;
            wndPlace.length = sizeof(WINDOWPLACEMENT);
            GetWindowPlacement(m_hwnd, &wndPlace);
            m_rc = wndPlace.rcNormalPosition;
        }
        else
            GetWindowRect(m_hwnd, &m_rc);

        //一旦非表示にする
        ShowWindow(m_hwnd, SW_HIDE);

        //フルスクリーン用スタイル
        SetWindowLongPtr(m_hwnd, GWL_STYLE, WS_POPUP | WS_SYSMENU);
        SetWindowPos(m_hwnd, HWND_TOPMOST, lpmi.rcMonitor.left, lpmi.rcMonitor.top, lpmi.rcMonitor.right - lpmi.rcMonitor.left, lpmi.rcMonitor.bottom - lpmi.rcMonitor.top, NULL);
    }
    else {
        //戻す
        SetWindowLongPtr(m_hwnd, GWL_STYLE, m_style);
        SetWindowPos(m_hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        if (m_bMax) {
            WINDOWPLACEMENT wndPlace;
            wndPlace.length = sizeof(WINDOWPLACEMENT);
            wndPlace.rcNormalPosition = m_rc;
            SetWindowPlacement(m_hwnd, &wndPlace);
        }
        else
            MoveWindow(m_hwnd, m_rc.left, m_rc.top, m_rc.right - m_rc.left, m_rc.bottom - m_rc.top, TRUE);
    }

    //フラグ反転
    m_bFull = !m_bFull;

    //SetWindowLongPtr()によるスタイル変更を適用
    SetWindowPos(m_hwnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);

    //表示
    ShowWindow(m_hwnd, SW_SHOW);

    return m_bFull;
}


//フルスクリーン状態か調べる
BOOL CFullScreen::IsFullscreen()
{
    return m_bFull;
}