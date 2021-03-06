#include "stdafx.h"
#include "User.h"
#include "..\Utilities\FileSystem.h"

using namespace std;

CUser::CUser(const CString& name, const CString& password) :
	_name(name), 
	_password(password)
{
}

CString CUser::CreateUid()
{
	auto now = COleDateTime::GetCurrentTime();
	return _name + now.Format(_T("_%Y%m%d%H%M%S"));
}

const CString& CUser::GetName() const
{
	return _name;
}

void CUser::SetName(const CString& val)
{
	_name = val;
}

const CString& CUser::GetPassword() const
{
	return _password;
}

void CUser::SetPassword(const CString& passoword)
{
	_password = passoword;
}

void CUser::SetUid(const CString& uid)
{
	_uid = uid;
}

const CString& CUser::GetUid()
{
	if (_uid.IsEmpty()) {
		_uid = CreateUid();
	}
	return _uid;
}

void CUser::SetWorkingFolder(const CString& folder)
{
	_working_folder = folder;
}

const CString& CUser::GetWorkingFolder() const
{
	return _working_folder;
}
