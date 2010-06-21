#ifndef __SEQNLIST_H__
#define __SEQNLIST_H__

#include "FbTreeModel.h"
#include "FbCollection.h"
#include "FbThread.h"

class FbSeqnListThread: public FbThread
{
	public:
		FbSeqnListThread(wxEvtHandler * frame, const FbMutexLocker &locker, const wxString &string, int order = 0)
			:FbThread(wxTHREAD_JOINABLE), m_frame(frame), m_tester(locker), m_string(string), m_order(order) {}
	protected:
		virtual void * Entry();
	private:
		static wxString GetOrder(const wxString &fields, int column);
		void DoString(wxSQLite3Database &database);
		void DoFullText(wxSQLite3Database &database);
		void MakeModel(wxSQLite3ResultSet &result);
		bool IsFullText(wxSQLite3Database &database) const;
	private:
		wxEvtHandler * m_frame;
		FbMutexTester m_tester;
		wxString m_string;
		int m_order;
};

class FbSeqnListData: public FbModelData
{
	public:
		FbSeqnListData(int code): m_code(code) {}
		virtual wxString GetValue(FbModel & model, size_t col = 0) const;
		int GetCode() const { return m_code; }
		virtual FbModelData * Clone() const
			 { return new FbSeqnListData(m_code); }
	private:
		int m_code;
		DECLARE_CLASS(FbSeqnListData);
};

class FbSeqnListModel: public FbListModel
{
	public:
		FbSeqnListModel(const wxArrayInt &items);
		virtual ~FbSeqnListModel(void);
		virtual void Append(FbModelData * data);
		virtual void Replace(FbModelData * data);
		virtual void Delete();
		void Append(const wxArrayInt &items);
		void Delete(int code);
	protected:
		virtual size_t GetRowCount() const
			{ return m_items.Count(); }
		virtual FbModelItem GetCurrent()
			{ return GetData(m_position); };
	protected:
		virtual FbModelItem DoGetData(size_t row, int &level);
	private:
		wxArrayInt m_items;
		DECLARE_CLASS(FbSeqnListModel);
};

#endif // __SEQNLIST_H__
