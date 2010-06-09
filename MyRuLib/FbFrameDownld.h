#ifndef __FBFRAMEDOWNLD_H__
#define __FBFRAMEDOWNLD_H__

#include <wx/wx.h>
#include <wx/toolbar.h>
#include <wx/aui/tabmdi.h>
#include <wx/html/htmlwin.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/splitter.h>
#include <wx/wxsqlite3.h>
#include "wx/treelistctrl.h"
#include "FbFrameBase.h"
#include "FbTreeListCtrl.h"
#include "FbBookEvent.h"

class FbDownListData: public FbModelData
{
	public:
		FbDownListData(int code, const wxString &name)
			: m_code(code), m_name(name) {}
		virtual wxString GetValue(FbModel & model, size_t col = 0) const
			{ return col == 0 ? m_name : (wxString)wxEmptyString; }
		int GetCode() const 
			{ return m_code; }
	private:
		int m_code;
		wxString m_name;
		DECLARE_CLASS(FbDownListData);
};

class FbFrameDownld : public FbFrameBase
{
	public:
		FbFrameDownld(wxAuiMDIParentFrame * parent);
		wxString GetTitle() const { return _("Downloads"); };
		void UpdateFolder(const int iFolder, const FbFolderType type);
		virtual void Localize(bool bUpdateMenu);
	protected:
		virtual wxToolBar * CreateToolBar(long style = wxTB_FLAT|wxTB_NODIVIDER|wxTB_HORZ_TEXT, wxWindowID winid = wxID_ANY, const wxString& name = wxEmptyString);
		virtual void CreateControls();
		virtual void UpdateBooklist();
	private:
		void CreateColumns();
		void CreateBookInfo();
		void FillFolders(const int iCurrent = 0);
		void DeleteItems(const wxTreeItemId &root, wxArrayInt &items);
	private:
		void OnFavoritesDel(wxCommandEvent & event);
		void OnFolderAppend(wxCommandEvent & event);
		void OnFolderModify(wxCommandEvent & event);
		void OnFolderDelete(wxCommandEvent & event);
		void OnStart(wxCommandEvent & event);
		void OnPause(wxCommandEvent & event);
		void OnFolderSelected(wxTreeEvent & event);
		void OnMoveUp(wxCommandEvent& event);
		void OnMoveDown(wxCommandEvent& event);
		DECLARE_EVENT_TABLE()
		DECLARE_CLASS(FbFrameDownld)
};

#endif // __FBFRAMEDOWNLD_H__
