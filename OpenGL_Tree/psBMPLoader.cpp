// psBMPLoader.cpp: implementation of the psBMPLoader class.
//
//////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <stdio.h>
#include <gl\glu.h>

#include "psBMPLoader.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

psBMPLoader::psBMPLoader()
{

}

psBMPLoader::~psBMPLoader()
{

}


bool psBMPLoader::psLoad(const char* strPathName)
{
	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER m_BMIH;

	FILE* bm = fopen(strPathName, "rb");
	int count,i,j,str;
	unsigned char *arr,*ptr;

	if (bm==NULL)return false;

	count = fread((void*)&bmfh, sizeof(BITMAPFILEHEADER), 1, bm);
	if (count!=1 || bmfh.bfType != 0x4d42)
    {
        fclose(bm);
        throw "Bad file!";
        return false;
	}
	count = fread((void*)&m_BMIH, sizeof(BITMAPINFOHEADER), 1, bm);

	if (count!= 1)
    {
        fclose(bm);
        throw "Bad file!";
        return false;
	}

	if(m_BMIH.biBitCount < 24)
    {
        fclose(bm);
        throw "Bad file format: MUST BE 32 or 24 bpp!";
        return false;
    }
	
	str=m_BMIH.biBitCount/8;

	if( 256!= m_BMIH.biWidth || 256!= m_BMIH.biHeight)
    {
        fclose(bm);
        throw "Bad file format: MUST BE 256 x 256!";
        return false;
    }

	ptr=arr = new unsigned char[256*256*str];
	count = fread((void*)arr, sizeof(char),256*256*str, bm);

	if(count!=256*256*str)
    {
        fclose(bm);
        throw "Bad file format";
        return false;
    }

    for(i=0;i<256;i++)
    for(j=0;j<256;j++)
    {
         sar[i][j][0]=((float)ptr[2])/(float)255.;
         sar[i][j][1]=((float)ptr[1])/(float)255.;
         sar[i][j][2]=((float)ptr[0])/(float)255.;
         sar[i][j][3]= 255.;				//Alpha
         ptr+=str;
    }

	delete arr;
	fclose(bm);
	return true;
}


bool psBMPLoader::psMakeTexture()
{

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //GL_NEAREST
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, 256, 0, GL_RGBA,GL_FLOAT,sar);

	return true;
}