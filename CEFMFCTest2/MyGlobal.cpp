#include "stdafx.h"
#include "MyGlobal.h"


MyGlobal::MyGlobal()
{
}

MyGlobal::~MyGlobal()
{
}

MyGlobal& MyGlobal::inst()
{
	static MyGlobal inst;
	return inst;
}