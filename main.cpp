#include <windows.h>
#include <tchar.h> // For _TCHAR and related functions

// Global variables (optional, but convenient for window class name)
const TCHAR g_szClassName[] = _T("MyWindowClass");

// 1. The Window Procedure (Callback Function)
// This simplified function only handles closing the window.
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE:
        // When the user clicks the 'X' button
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        // When the window is destroyed, quit the application's message loop
        PostQuitMessage(0);
        break;
    default:
        // Handle any messages we don't explicitly process
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// 2. The Main Entry Point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg; // Required for the message loop

    // Step 3: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;             // Pointer to the Window Procedure
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); // Window background color
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, _T("Window Registration Failed!"), _T("Error!"),
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 4: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,   // Extended style
        g_szClassName,      // Class name
        _T("Simplified Win32 Window"), // Window title bar text
        WS_OVERLAPPEDWINDOW, // Style: standard resizable window
        CW_USEDEFAULT, CW_USEDEFAULT, // X, Y position
        500, 300,           // Width, Height
        NULL, NULL,         // Parent window, Menu handle
        hInstance, NULL     // Instance handle, User defined parameter
    );

    if(hwnd == NULL)
    {
        MessageBox(NULL, _T("Window Creation Failed!"), _T("Error!"),
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 5: Displaying the Window
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Step 6: The Message Loop
    // This loop constantly checks for messages and dispatches them to WndProc.
    // It is essential for the window to remain open and responsive.
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}
