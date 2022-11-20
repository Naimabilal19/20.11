#include <Windows.h>
#include <tchar.h>
#include <ctime>
#include "resource.h"

HWND hList, hB, hBox, hR1, hR2, hR3, hResult;    //� ������ 
TCHAR str[20];
int num, result,result1=1, arr[20];  //����������!! ���������� ��� ����������

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), 0, (DLGPROC)DlgProc);
}

void random()              //������ ������� ��� �������
{
	num = rand() % (20);        
	wsprintf(str, TEXT("%d"), num);     
}

void fill()              //��� ���������� ������
{ 
	SendMessage(hList, LB_RESETCONTENT, 0, 0);
	for (int i = NULL; i < 20; i++)               
	{
		SendMessage(hList, LB_ADDSTRING, 0, LPARAM(str));
		random();
		arr[i] = num;
	}
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	srand(time(0));
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return(TRUE);
	case WM_INITDIALOG:
		hList = GetDlgItem(hWnd, IDC_LIST1);
		hB = GetDlgItem(hWnd, IDC_BUTTON1);
		hBox = GetDlgItem(hWnd, IDC_STATIC);
		hR1 = GetDlgItem(hWnd, IDC_RADIO1);
		hR2 = GetDlgItem(hWnd, IDC_RADIO2);
		hR3 = GetDlgItem(hWnd, IDC_RADIO3);
		hResult = GetDlgItem(hWnd, IDC_EDIT1);
		fill();
		return(TRUE);
	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTON1)            //���� ������ "�����"
		{
			fill();    //����������
			SendMessage(hResult, WM_SETTEXT, 0, LPARAM(TEXT("...")));  
		}
		else if (LOWORD(wParam) == IDC_RADIO1)  //���� ������ �������
		{
			for (int i = 0; i < 19; i++)
			{
				result += arr[i];    //���������� ��� �����
			}
			wsprintf(str, TEXT("%d"), result);     
			SendMessage(hResult, WM_SETTEXT, 0, LPARAM(str));   //���������� ��������� 
			result = 0;  //�������� ���������
		}
		else if (LOWORD(wParam) == IDC_RADIO2)  //���� 2 �������
		{
			for (int i = NULL; i < 19; i++)
			{
				result1 *= arr[i]; //��������
			}
			wsprintf(str, TEXT("%d"), result);
			SendMessage(hResult, WM_SETTEXT, 0, LPARAM(str)); //���������� ���������
			result = 0;
		}
		else if (LOWORD(wParam) == IDC_RADIO3)
		{
			for (int i = NULL; i < 9; i++)
			{
				result += arr[i]; //c�������� 
			}
			wsprintf(str, TEXT("%d"), result / 10);  //�����
			SendMessage(hResult, WM_SETTEXT, 0, LPARAM(str));   //���������� ���������
			result = 0;
		}
		return(TRUE);
	}
	return(FALSE);
}








