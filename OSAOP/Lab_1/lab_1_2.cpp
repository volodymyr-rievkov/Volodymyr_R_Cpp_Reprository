#include <iostream>
#include <string>
#include <filesystem>
#include <array>

#ifdef _WIN32
    #include <windows.h>
    #include <shlobj.h>
#elif __linux__
    #include <unistd.h> 
    #include <sys/wait.h> 
    #include <gtk/gtk.h>
#endif

void cross_platform_sleep(int seconds) 
{
#ifdef _WIN32
    Sleep(seconds * 1000); 
#elif __linux__
    sleep(seconds); 
#endif
}

std::string exec_command(const std::string& command) 
{
    std::array<char, 128> buffer;
    std::string result;
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) 
        {
            result += buffer.data();
        }
    } catch (...) 
    {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

void show_message(const char* message) 
{   
    #ifdef __linux__
    gtk_init(NULL, NULL);
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, 
                                    GTK_MESSAGE_INFO, GTK_BUTTONS_OK, 
                                    "%s", message);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    #endif
}

std::wstring choose_folder() 
{
    std::wstring folder_path;
    
    #ifdef _WIN32
        BROWSEINFOW bi = { 0 };
        bi.lpszTitle = L"Select Folder to Zip";
        LPITEMIDLIST pidl = SHBrowseForFolderW(&bi);
        if (pidl != 0) 
        {
            wchar_t path[MAX_PATH];
            if (SHGetPathFromIDListW(pidl, path)) 
            {
                folder_path = std::wstring(path);
            }
        }
        else
        {
            folder_path = L"";
        }
    #elif __linux__    
        std::string zenity_command = "zenity --file-selection --directory --title=\"Select Folder to Zip\"";
        std::string result = exec_command(zenity_command);
        result.erase(result.find_last_not_of(" \n\r\t") + 1);
        folder_path = std::wstring(result.begin(), result.end());
    #endif
    return folder_path;
}

void zip_folder(const std::wstring& folder_path, const std::wstring& zip_path) 
{
    bool is_to_kill = false;
#ifdef _WIN32
    std::wstring winrar_path = L"C:\\Program Files\\WinRAR\\WinRAR.exe";
    std::wstring command = L"\"";
    command += winrar_path;
    command += L"\" a -afzip \"" + zip_path + L"\" \"" + folder_path + L"\"";
    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(pi));
    if (CreateProcessW(NULL, &command[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) 
    {
        cross_platform_sleep(2);
        SuspendThread(pi.hThread);
        MessageBoxW(NULL, L"Thread was successfully stopped.", L"Success", MB_OK | MB_ICONINFORMATION);
        cross_platform_sleep(2);
        if (is_to_kill) 
        {
            TerminateProcess(pi.hProcess, 0);
            if (std::filesystem::exists(zip_path)) 
            {
                std::filesystem::remove(zip_path);
            }
            MessageBoxW(NULL, L"Process was successfully terminated.", L"Success", MB_OK | MB_ICONINFORMATION);
        } 
        else 
        {
            ResumeThread(pi.hThread);
            MessageBoxW(NULL, L"Thread was successfully resumed.", L"Success", MB_OK | MB_ICONINFORMATION);
            cross_platform_sleep(2);
            WaitForSingleObject(pi.hProcess, INFINITE);
            MessageBoxW(NULL, L"Folder was successfully zipped.", L"Success", MB_OK | MB_ICONINFORMATION);
        }
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } 
    else 
    {
        MessageBoxW(NULL, L"Error: Folder wasn't successfully zipped.", L"Failure", MB_OK | MB_ICONINFORMATION);
    }
#elif __linux__
    std::string zip_command = "zip -r \"" + std::string(zip_path.begin(), zip_path.end()) + "\" \"" + std::string(folder_path.begin(), folder_path.end()) + "\"";
    pid_t pid = fork();
    if (pid == 0) 
    {
        execl("/bin/sh", "sh", "-c", zip_command.c_str(), (char*)0);
        exit(0);
    } 
    else if (pid > 0) 
    {
        cross_platform_sleep(1);
        kill(pid, SIGSTOP);
        show_message("Process was successfully stopped.");
        if (is_to_kill) 
        {
            kill(pid, SIGTERM);
            if (std::filesystem::exists(zip_path)) 
            {
                std::filesystem::remove(zip_path);
            }
            show_message("Process was successfully terminated.");
        } 
        else 
        {
            cross_platform_sleep(2);
            kill(pid, SIGCONT);
            show_message("Process was successfully continued.");
            cross_platform_sleep(2);
            waitpid(pid, NULL, 0);
            show_message("Folder was successfully zipped.");
        }
    } 
    else 
    {
        show_message("Error: Forking process failed.");
    }
#endif
}

int main() 
{
    std::wstring folder_path = choose_folder();
    std::wstring zip_path = folder_path + L".zip";
    zip_folder(folder_path, zip_path);
}