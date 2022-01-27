#include "main.h"

class CFullScreen
{
public:
    CFullScreen(
        HWND hwnd       //�t���X�N���[���ɂ���E�B���h�E�̃n���h��
    );
    ~CFullScreen();

    //�t���X�N���[�����[�h / �E�B���h�E���[�h�؂�ւ�
    BOOL change();
    //�߂�l
    //�t���X�N���[�����[�h => �E�B���h�E���[�h     : TRUE
    //�E�B���h�E���[�h     => �t���X�N���[�����[�h : FALSE

//�t���X�N���[����Ԃ����ׂ�
    BOOL IsFullscreen();
    //�߂�l
    //�t���X�N���[�����[�h    : TRUE
    //�E�B���h�E���[�h      : FALSE

private:
    HWND m_hwnd;        //�t���X�N���[���ɂ���E�B���h�E�̃n���h��

    //�ۑ��p�ϐ�
    RECT m_rc;          //�E�B���h�E�T�C�Y
    LONG m_style;       //�E�B���h�E�X�^�C��
    BOOL m_bMax;        //�ő剻�t���O

    //���݂̏��
    BOOL m_bFull;       //�t���X�N���[���t���O
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

//�t���X�N���[�����[�h / �E�B���h�E���[�h�؂�ւ�
BOOL CFullScreen::change()
{
    if (!m_bFull) {
        //�t���X�N���[���ɂ���
        //�E�B���h�E�����郂�j�^
        HMONITOR hMoni = MonitorFromWindow(m_hwnd, MONITOR_DEFAULTTOPRIMARY);

        //�X�N���[���̑傫��
        MONITORINFOEX lpmi;
        lpmi.cbSize = sizeof(MONITORINFOEX);
        GetMonitorInfo(hMoni, &lpmi);

        //���̃E�B���h�E�̏�Ԃ�ۑ�
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

        //��U��\���ɂ���
        ShowWindow(m_hwnd, SW_HIDE);

        //�t���X�N���[���p�X�^�C��
        SetWindowLongPtr(m_hwnd, GWL_STYLE, WS_POPUP | WS_SYSMENU);
        SetWindowPos(m_hwnd, HWND_TOPMOST, lpmi.rcMonitor.left, lpmi.rcMonitor.top, lpmi.rcMonitor.right - lpmi.rcMonitor.left, lpmi.rcMonitor.bottom - lpmi.rcMonitor.top, NULL);
    }
    else {
        //�߂�
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

    //�t���O���]
    m_bFull = !m_bFull;

    //SetWindowLongPtr()�ɂ��X�^�C���ύX��K�p
    SetWindowPos(m_hwnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);

    //�\��
    ShowWindow(m_hwnd, SW_SHOW);

    return m_bFull;
}


//�t���X�N���[����Ԃ����ׂ�
BOOL CFullScreen::IsFullscreen()
{
    return m_bFull;
}