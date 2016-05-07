
// PsiScaleEditorDlg.h : 头文件
//

#pragma once

#include <memory>
#include "afxwin.h"
#include "..\PsiCommon\TestManager.h"

class PsiScale;
class PsiScaleQuestion;

// CPsiScaleEditorDlg 对话框
class CPsiScaleEditorDlg : public CDialogEx
{
// 构造
public:
	CPsiScaleEditorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PSISCALEEDITOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	std::shared_ptr<PsiScale> _scale;
	std::shared_ptr<PsiScaleQuestion> _question;
	CTestManager _test_manager;
	int _current_question;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckSameChoice();
	afx_msg void OnBnClickedButtonNew();

	UINT _scale_id;
	CString _scale_name;
	CString _prologue_text;
	CString _question_text;
	BOOL _use_same_choices;
	
	CListBox _question_list;
	CListBox _choice_list;
	CListBox _group_list;
	afx_msg void OnBnClickedButtonAddQuestion();
	void UpdateUi();
	afx_msg void OnBnClickedButtonAddGroup();
	afx_msg void OnBnClickedButtonAddChoice();
	afx_msg void OnEnChangeEditQuestion();
	afx_msg void OnLbnSelchangeListQuestions();
	afx_msg void OnBnClickedButtonSave();

	CMFCButton _add_question_button;
	CMFCButton _delete_question_button;
	CEdit _scale_id_edit;
	CEdit _scale_name_edit;
	CEdit _prologue_text_edit;
	CEdit _question_text_edit;
	CMFCButton _shared_choices_checkbox;
	CMFCButton _add_choice_button;
	CMFCButton _delete_choice_button;
	CMFCButton _modify_choice_button;
	CMFCButton _add_group_button;
	CMFCButton _delete_group_button;
	CMFCButton _modify_group_button;
	CMFCButton _new_scale_table_button;
	CMFCButton _save_scale_button;
	CMFCButton _exit_button;
};
