#pragma once

struct CmFile
{
	//static string BrowseFile(const char* strFilter = "Images (*.jpg;*.png)\0*.jpg;*.png\0All (*.*)\0*.*\0\0", bool isOpen = true);
	//static string BrowseFolder();

	static inline string GetFolder(CStr& path);
	static inline string GetName(CStr& path);
	static inline string GetNameNE(CStr& path);
	static inline string GetPathNE(CStr& path);

	// Get file names from a wildcard. Eg: GetNames("D:\\*.jpg", imgNames);
	static int GetNames(CStr &nameW, vecS &names, string &dir);
	static int GetNames(CStr &nameW, vecS &names);
	static int GetNames(CStr& rootFolder, CStr &fileW, vecS &names);
	static int GetNamesNE(CStr& nameWC, vecS &names, string &dir, string &ext);
	static int GetNamesNE(CStr& nameWC, vecS &names);
	static int GetNamesNE(CStr& rootFolder, CStr &fileW, vecS &names);
	static inline string GetExtention(CStr name);

	static inline string GetWkDir();

	static BOOL MkDir(CStr&  path);

	static int GetSubFolders(CStr& folder, vecS& subFolders);

	static vecS loadStrList(CStr &fName);
	static bool writeStrList(CStr &fName, const vecS &strs);
};

/************************************************************************/
/* Implementation of inline functions                                   */
/************************************************************************/
string CmFile::GetFolder(CStr& path)
{
	return path.substr(0, path.find_last_of("\\/")+1);
}

string CmFile::GetName(CStr& path)
{
	int start = path.find_last_of("\\/")+1;
	int end = path.find_last_not_of(' ')+1;
	return path.substr(start, end - start);
}

string CmFile::GetNameNE(CStr& path)
{
	int start = path.find_last_of("\\/")+1;
	int end = path.find_last_of('.');
	if (end >= 0)
		return path.substr(start, end - start);
	else
		return path.substr(start,  path.find_last_not_of(' ')+1 - start);
}

string CmFile::GetPathNE(CStr& path)
{
	int end = path.find_last_of('.');
	if (end >= 0)
		return path.substr(0, end);
	else
		return path.substr(0,  path.find_last_not_of(' ') + 1);
}

string CmFile::GetExtention(CStr name)
{
	return name.substr(name.find_last_of('.'));
}