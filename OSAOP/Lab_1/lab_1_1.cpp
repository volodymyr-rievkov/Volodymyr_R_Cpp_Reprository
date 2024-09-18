#include <windows.h>
#include <shlobj.h>
#include <string>
#include<stdio.h>

std::wstring choose_folder() 
{
    BROWSEINFOW bi = { 0 };
    bi.lpszTitle = L"Select Folder to Zip";
    LPITEMIDLIST pidl = SHBrowseForFolderW(&bi);
    if (pidl != 0) 
    {
        wchar_t path[MAX_PATH];
        if (SHGetPathFromIDListW(pidl, path)) 
        {
            return std::wstring(path);
        }
    }
    return L""; 
}

void zip_folder(const std::wstring& folder_path, const std::wstring& zip_path) 
{
    std::wstring winrar_path = L"C:\\Program Files\\WinRAR\\WinRAR.exe";
    std::wstring command = L"\"";
    command += winrar_path;
    command += L"\" a -afzip \"";
    command += zip_path;
    command += L"\" \"";
    command += folder_path;
    command += L"\"";
    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(pi));
    if (CreateProcessW(NULL, &command[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) 
    {
        Sleep(2000);
        SuspendThread(pi.hThread);
        MessageBoxW(NULL, L"Thread  was successfully stopped.", L"Success", MB_OK | MB_ICONINFORMATION);
        
        Sleep(2000);

        ResumeThread(pi.hThread);
        MessageBoxW(NULL, L"Thread  was successfully resumed.", L"Success", MB_OK | MB_ICONINFORMATION);
        Sleep(2000);

        if(true)
        {
            TerminateProcess(pi.hProcess, 0);
            MessageBoxW(NULL, L"Process  was successfully terminated.", L"Success", MB_OK | MB_ICONINFORMATION);
            Sleep(2000);
        }
        else
        {
            WaitForSingleObject(pi.hProcess, INFINITE);
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
            MessageBoxW(NULL, L"Folder  was successfully zipped.", L"Success", MB_OK | MB_ICONINFORMATION);
        }
    } 
    else 
    {
        MessageBoxW(NULL, L"Error: Folder  wasn't successfully zipped.", L"Failure", MB_OK | MB_ICONINFORMATION);
    }
}

int main()
{
    std::wstring folder_path = choose_folder();
    std::wstring zip_path = folder_path + L".zip";
    zip_folder(folder_path, zip_path);
}