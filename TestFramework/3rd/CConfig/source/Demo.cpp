//--------------------------------------------//
// Demo.cpp                                   //
// CConfig.exe                                //
//                                            //
// This execute will use the class of CConfig //
// to show you that how to use this class.    //
// Can run in multi OS.                       //
//                                            //
// Writed by Deyou Kong, 2016-12-10           //
// Checked by Deyou Kong, 2016-12-11          //
//--------------------------------------------//

#include <iostream>
#include <string>
#include "CConfig.h"

int main(void)
{
	CConfig cfg("CConfig.cfg");
	
	cfg.SetFilePath("CConfig_Origin.cfg");

	cfg.SetAutoSave(false);

	unsigned int uiLine = 0;
	cfg.LoadFile(&uiLine);

	cout << "uiLine:" << uiLine << endl << endl;

	cout << "Testing output:" << endl;

	cout << "default - default_int:" << cfg.GetInteger ("default", "default_int") << endl;
	cout << "default - default_dou:" << cfg.GetDouble  ("default", "default_dou") << endl;
	cout << "default - default_boo:" << cfg.GetBoolean ("default", "default_boo") << endl;
	cout << "default - default_atr:" << cfg.GetString  ("default", "default_atr") << endl;

	cout << "group_int - group_int:" << cfg.GetInteger ("group_int", "group_int") << endl;
	cout << "group_dou - group_dou:" << cfg.GetDouble  ("group_dou", "group_dou") << endl;
	cout << "group_boo - group_boo:" << cfg.GetBoolean ("group_boo", "group_boo") << endl;
	cout << "group_str - group_str:" << cfg.GetString  ("group_str", "group_str") << endl;

	cout << "group_all - group_int:" << cfg.GetInteger ("group_all", "group_int") << endl;
	cout << "group_all - group_dou:" << cfg.GetDouble  ("group_all", "group_dou") << endl;
	cout << "group_all - group_boo:" << cfg.GetBoolean ("group_all", "group_boo") << endl;
	cout << "group_all - group_str:" << cfg.GetString  ("group_all", "group_str") << endl;

	cout << "group empty - group_int:" << cfg.GetInteger ("group empty", "group_int") << endl;
	cout << "group empty - group_dou:" << cfg.GetDouble  ("group empty", "group_dou") << endl;
	cout << "group empty - group_boo:" << cfg.GetBoolean ("group empty", "group_boo") << endl;
	cout << "group empty - group_str:" << cfg.GetString  ("group empty", "group_str") << endl;

	cfg.SaveFileAs("CConfig_SaveAs.cfg");
	cout << "Output as CConfig_SaveAs.cfg" << endl;

	cout << endl;

	cout << "Testing change value:" << endl;

	cfg.SetInteger ("default", "default_int", 500);
	cfg.SetDouble  ("default", "default_dou", 5.0);
	cfg.SetBoolean ("default", "default_boo",   1);
	cfg.SetString  ("default", "default_str", "0");
											 
	cfg.SetInteger ("group_int", "group_int", 501);
	cfg.SetDouble  ("group_dou", "group_dou", 5.1);
	cfg.SetBoolean ("group_boo", "group_boo",   1);
	cfg.SetString  ("group_str", "group_str", "1");
											 
	cfg.SetInteger ("group_all", "group_int", 502);
	cfg.SetDouble  ("group_all", "group_dou", 5.2);
	cfg.SetBoolean ("group_all", "group_boo",   1);
	cfg.SetString  ("group_all", "group_str", "2");

	cfg.SaveFileAs("CConfig_Change.cfg");

	cout << "Change value and save as CConfig_Change.cfg" << endl << endl;
	
	system("pause");

	return 0;
}