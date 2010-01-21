#ifndef __FBEXTRACTINFO_H__
#define __FBEXTRACTINFO_H__

#include <wx/wx.h>
#include <wx/filename.h>
#include <wx/arrimpl.cpp>
#include <wx/wxsqlite3.h>
#include "FbDatabase.h"

class FbExtractItem
{
	public:
		FbExtractItem(wxSQLite3ResultSet & result);
	public:
		wxFileName GetBook(const wxString &path = wxEmptyString) const;
		wxFileName GetZip(const wxString &path = wxEmptyString) const;
		wxString NameInfo() const;
		void DeleteFile(const wxString &basepath) const;
	public:
		int id_book;
		int id_archive;
		wxString book_name;
		wxString zip_name;
		bool librusec;
};

WX_DECLARE_OBJARRAY(FbExtractItem, FbExtractArrayBase);

class FbExtractArray
	: public FbExtractArrayBase
{
	public:
		FbExtractArray(FbDatabase & database, const int id);
		int GetId() const {return m_id; };
		void DeleteFiles(const wxString &basepath) const;
	private:
		int m_id;
};

#endif // __FBEXTRACTINFO_H__