
// mfc_ffmpeg_video_filterDlg.h : 头文件
//
#ifdef __cplusplus
extern "C" {
#endif
#include <libavcodec/avcodec.h>
#include <libavdevice/avdevice.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfiltergraph.h>
#include <libavfilter/buffersink.h>
#include <libavfilter/buffersrc.h>
#include <libavutil/avutil.h>
#include "libavutil/imgutils.h"
//#include "libavutil/mem.h"
#include "libavutil/mathematics.h"
#include "libavutil/time.h"
#include <libswscale/swscale.h>
#include <sdl/sdl.h>
#ifdef __cplusplus
}
#endif
#include "afxcmn.h"
#include "MySliderCtrl.h"
#pragma once


// CMFC_ffmpeg_video_filterDlg 对话框
class CMFC_ffmpeg_streamerDlg : public CDialogEx
{
// 构造
public:
	SDL_Window *sdl_win;
	CString m_file_path;
	CMFC_ffmpeg_streamerDlg(CWnd* pParent = NULL);	// 标准构造函数
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_FFMPEG_STREAMER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CMenu m_menu;
	CStatusBar m_statusbar;
	CRect m_SaveIcon;
	CRect m_SaveButtonMin;
	CRect m_SaveButtonMax;
	CRect m_SaveButtonClose;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int OpenInput(const char *pSrc);
	int CloseInput();
	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedBtnPlay();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int SetStatusMessage(char *buf);
protected:
	afx_msg LRESULT OnUserMsg1(WPARAM wParam, LPARAM lParam);
public:
	int m_vset1;
	afx_msg void OnOpenFile();
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	CMySliderCtrl m_ptsSlider;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnNMCustomdrawSliderPts(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnReleasedcaptureSliderPts(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedMovieClip();
	afx_msg void OnBnClickedBtnCutstart();
	afx_msg void OnBnClickedBtnCutend();
	afx_msg void OnClickedBtnSave();
};
