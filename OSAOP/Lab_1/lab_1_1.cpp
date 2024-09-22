#include <windows.h>
#include <shlobj.h>
#include <string>
#include <stdio.h>
#include <filesystem>

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
    bool is_to_kill = false;
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

        if(!is_to_kill)
        {
            TerminateProcess(pi.hProcess, 0);
            if (std::filesystem::exists(zip_path)) 
            {
                std::filesystem::remove(zip_path);
            }
            MessageBoxW(NULL, L"Process  was successfully terminated.", L"Success", MB_OK | MB_ICONINFORMATION);
            Sleep(2000);
        }
        else
        {
            ResumeThread(pi.hThread);
            MessageBoxW(NULL, L"Thread  was successfully resumed.", L"Success", MB_OK | MB_ICONINFORMATION);
            Sleep(2000);

            WaitForSingleObject(pi.hProcess, INFINITE);
            MessageBoxW(NULL, L"Folder  was successfully zipped.", L"Success", MB_OK | MB_ICONINFORMATION);
        }
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
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