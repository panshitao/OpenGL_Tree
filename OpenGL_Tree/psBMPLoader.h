// psBMPLoader.h: interface for the psBMPLoader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSBMPLOADER_H__687312B9_EDEC_4B8D_B59A_A5A3802B3C8B__INCLUDED_)
#define AFX_PSBMPLOADER_H__687312B9_EDEC_4B8D_B59A_A5A3802B3C8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class psBMPLoader  
{
public:
	float sar[256][256][4];
public:
	psBMPLoader();
	virtual ~psBMPLoader();
	bool psLoad(const char* strPathName);
	bool psMakeTexture();

};

#endif // !defined(AFX_PSBMPLOADER_H__687312B9_EDEC_4B8D_B59A_A5A3802B3C8B__INCLUDED_)
